#include "motor_control.h"
#include "config.h"
#include <FlexCAN.h>

extern volatile long encoderPosX;
extern volatile long encoderPosY;

FlexCAN canBus(500000); // Initialize CAN bus at 500 kbps

void initMotors() {
    canBus.begin();
}

void sendMotorCommand(int motorId, int command) {
    CAN_message_t msg;
    msg.id = motorId;
    msg.len = 2;
    msg.buf[0] = command >> 8;
    msg.buf[1] = command & 0xFF;
    canBus.write(msg);
}

void pidControl(long setPointX, long setPointY) {
    static long prevErrorX = 0, prevErrorY = 0;
    static long integralX = 0, integralY = 0;

    long errorX = setPointX - encoderPosX;
    long errorY = setPointY - encoderPosY;

    integralX += errorX;
    integralY += errorY;

    long derivativeX = errorX - prevErrorX;
    long derivativeY = errorY - prevErrorY;

    long outputX = kp * errorX + ki * integralX + kd * derivativeX;
    long outputY = kp * errorY + ki * integralY + kd * derivativeY;

    prevErrorX = errorX;
    prevErrorY = errorY;

    sendMotorCommand(MOTOR_X_ID, outputX);
    sendMotorCommand(MOTOR_Y_ID, outputY);
}

void stopMotors() {
    sendMotorCommand(MOTOR_X_ID, 0);
    sendMotorCommand(MOTOR_Y_ID, 0);
}

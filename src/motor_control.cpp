#include "motor_control.h"
#include "config.h"
#include <ACAN_T4.h>

extern volatile long encoderPosX;
extern volatile long encoderPosY;

void initMotors() {
    // CAN initialization is now done in initCAN
}

void sendMotorCommand(int motorId, int command) {
    CANMessage message;
    message.id = motorId;
    message.len = 2;
    message.data[0] = command >> 8;
    message.data[1] = command & 0xFF;
    sendCANMessage(message);
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

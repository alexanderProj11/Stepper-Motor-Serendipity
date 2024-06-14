#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

void initMotors();
void sendMotorCommand(int motorId, int command);
void pidControl(long setPointX, long setPointY);
void stopMotors();

#endif // MOTOR_CONTROL_H

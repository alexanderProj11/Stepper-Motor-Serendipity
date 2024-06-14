#ifndef CONFIG_H
#define CONFIG_H

// Pin definitions
#define JOYSTICK_X_PIN A0
#define JOYSTICK_Y_PIN A1
#define ENCODER_A_PIN 2
#define ENCODER_B_PIN 3
#define CAN_TX_PIN 4
#define CAN_RX_PIN 5
#define EMERGENCY_STOP_PIN 6

// Motor settings
#define MOTOR_X_ID 1
#define MOTOR_Y_ID 2

// Control parameters
extern const float kp;
extern const float ki;
extern const float kd;

// Health monitoring parameters
extern const float maxCurrent;
extern const float maxTemperature;

// Other configurations
extern const int maxSpeed;

void loadConfig();

#endif // CONFIG_H

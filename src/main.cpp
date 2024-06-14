#include <Arduino.h>
#include "config.h"
#include "motor_control.h"
#include "joystick.h"
#include "encoder.h"
#include "can_communication.h"
#include "health_monitoring.h"

void setup() {
    Serial.begin(115200);
    loadConfig();
    initMotors();
    initJoystick();
    initEncoders();
    initCAN();
    initHealthMonitoring();
}

void loop() {
    if (checkEmergencyStop()) {
        stopMotors();
        Serial.println("Emergency Stop Triggered!");
        while (true) {} // Halt the system
    }

    if (!checkHealthStatus()) {
        Serial.println("Health Check Failed!");
        while (true) {} // Halt the system
    }

    int joystickX = readJoystickX();
    int joystickY = readJoystickY();

    long setPointX = map(joystickX, 0, 1023, -maxSpeed, maxSpeed);
    long setPointY = map(joystickY, 0, 1023, -maxSpeed, maxSpeed);

    pidControl(setPointX, setPointY);

    float current = readCurrent();
    float temperature = readTemperature();

    Serial.print("Current: ");
    Serial.print(current);
    Serial.print(" A, Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    delay(100);
}

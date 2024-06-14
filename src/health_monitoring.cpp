#include "health_monitoring.h"
#include "config.h"
#include "motor_control.h"
#include <ACS712.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>

ACS712 motorCurrent(A0, 5.0); // Assuming current sensor on pin A0
OneWire oneWire(4); // Pin 4
DallasTemperature sensors(&oneWire);

void initHealthMonitoring() {
    sensors.begin();
    pinMode(EMERGENCY_STOP_PIN, INPUT_PULLUP); // Assuming normally closed emergency stop button
}

float readCurrent() {
    return motorCurrent.getCurrentAC();
}

float readTemperature() {
    sensors.requestTemperatures();
    return sensors.getTempCByIndex(0);
}

bool checkEmergencyStop() {
    return digitalRead(EMERGENCY_STOP_PIN) == LOW; // Emergency stop is triggered when button is pressed
}

bool checkHealthStatus() {
    float current = readCurrent();
    float temperature = readTemperature();

    if (current > maxCurrent || temperature > maxTemperature) {
        stopMotors();
        return false;
    }

    return true;
}

#include "health_monitoring.h"
#include "config.h"
#include "motor_control.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>

OneWire oneWire(4); // Pin 4
DallasTemperature sensors(&oneWire);

void initHealthMonitoring() {
    sensors.begin();
    pinMode(EMERGENCY_STOP_PIN, INPUT_PULLUP); // Assuming normally closed emergency stop button
}

// Assuming a 5A ACS712 sensor with a sensitivity of 185 mV/A
const float ACS712_SENSITIVITY = 0.185; // Sensitivity in V/A
const int ACS712_OFFSET = 512; // Midpoint value for zero current (assuming 10-bit ADC)

float readCurrent() {
    int sensorValue = analogRead(A0); // Read the analog value from the sensor
    float voltage = (sensorValue - ACS712_OFFSET) * (5.0 / 1024.0); // Convert to voltage
    return voltage / ACS712_SENSITIVITY; // Convert to current
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

#include "config.h"

const float kp = 1.0;
const float ki = 0.1;
const float kd = 0.01;

const float maxCurrent = 5.0; // Maximum allowable current in Amps
const float maxTemperature = 70.0; // Maximum allowable temperature in Celsius

const int maxSpeed = 1000;

void loadConfig() {
    // Load or initialize other configuration settings if needed
}

#include "joystick.h"
#include "config.h"
#include <Arduino.h>

void initJoystick() {
    pinMode(JOYSTICK_X_PIN, INPUT);
    pinMode(JOYSTICK_Y_PIN, INPUT);
}

int readJoystickX() {
    return analogRead(JOYSTICK_X_PIN);
}

int readJoystickY() {
    return analogRead(JOYSTICK_Y_PIN);
}

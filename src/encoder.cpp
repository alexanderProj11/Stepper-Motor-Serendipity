#include "encoder.h"
#include "config.h"
#include <Arduino.h>

volatile long encoderPosX = 0;
volatile long encoderPosY = 0;
volatile bool dirX = true;
volatile bool dirY = true;

void IRAM_ATTR readEncoderA() {
    dirX = digitalRead(ENCODER_B_PIN);
    encoderPosX += (dirX ? 1 : -1);
}

void IRAM_ATTR readEncoderB() {
    dirY = digitalRead(ENCODER_A_PIN);
    encoderPosY += (dirY ? -1 : 1);
}

void initEncoders() {
    pinMode(ENCODER_A_PIN, INPUT);
    pinMode(ENCODER_B_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(ENCODER_A_PIN), readEncoderA, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENCODER_B_PIN), readEncoderB, CHANGE);
}

#ifndef ENCODER_H
#define ENCODER_H

void initEncoders();
void readEncoderA();
void readEncoderB();

extern volatile long encoderPosX;
extern volatile long encoderPosY;

#endif // ENCODER_H

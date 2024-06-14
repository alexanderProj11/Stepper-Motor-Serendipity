#ifndef CAN_COMMUNICATION_H
#define CAN_COMMUNICATION_H

#include <ACAN_T4.h>

bool readCANMessage(CANMessage &msg);
void sendCANMessage(const CANMessage &msg);
void initCAN();

#endif // CAN_COMMUNICATION_H


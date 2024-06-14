#ifndef CAN_COMMUNICATION_H
#define CAN_COMMUNICATION_H

void initCAN();
bool readCANMessage(CAN_message_t &msg);
void sendCANMessage(const CAN_message_t &msg);

#endif // CAN_COMMUNICATION_H

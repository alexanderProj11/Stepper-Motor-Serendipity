#include "can_communication.h"
#include <FlexCAN.h>

FlexCAN canBus(500000); // Initialize CAN bus at 500 kbps

void initCAN() {
    canBus.begin();
}

bool readCANMessage(CAN_message_t &msg) {
    return canBus.read(msg);
}

void sendCANMessage(const CAN_message_t &msg) {
    canBus.write(msg);
}

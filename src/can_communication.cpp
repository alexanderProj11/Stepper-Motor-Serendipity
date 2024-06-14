#include "can_communication.h"
#include "config.h"

void initCAN() {
    ACAN_T4_Settings settings(500 * 1000); // Set to 500 kbps
    const uint32_t errorCode = ACAN_T4::can1.begin(settings);
    if (errorCode != 0) {
        Serial.print("CAN initialization error: 0x");
        Serial.println(errorCode, HEX);
    }
}

bool readCANMessage(CANMessage &msg) {
    return ACAN_T4::can1.receive(msg);
}

void sendCANMessage(const CANMessage &msg) {
    ACAN_T4::can1.tryToSend(msg);
}

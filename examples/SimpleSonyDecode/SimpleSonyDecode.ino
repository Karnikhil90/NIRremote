#include <NIRremote.h>

NIRremote remote;

void setup() {
    Serial.begin(115200);
    remote.begin(11); // IR receiver on GPIO 2
}

void loop() {
    if (remote.capture()) {
        uint32_t code = remote.decodeSony();
        if (code != 0) {
            Serial.print("Sony Code: 0x");
            Serial.println(code, HEX);
        } else {
            Serial.println("Failed to decode Sony");
        }
    }
}

#include <NIRcore.h>
#include <IRDebug.h>

Decode decoder;

void setup() {
    Serial.begin(115200);
    decoder.begin(11); // IR receiver on GPIO 2
}

void loop() {
    if (decoder.capture()) {
        printRaw(decoder.getRawPulses(), decoder.getPulseCount());

        uint32_t code = decoder.decodeSony();
        if (code != 0) {
            Serial.print("Decoded Sony Code: 0x");
            Serial.println(code, HEX);
        } else {
            Serial.println("Invalid Sony Signal");
        }
    }
}

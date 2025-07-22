#include <NIRremote.h>

NIRremote remote;

void setup() {
    Serial.begin(115200);
    remote.begin(11); // IR receiver on GPIO 2
}

void loop() {
    if (remote.capture()) {
        remote.printRaw();  // Print all raw pulse timings
        delay(1000);
    }
}

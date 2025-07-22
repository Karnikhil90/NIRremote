#include "IRDebug.h"

void printRaw(IRPulse* pulses, int count) {
    Serial.println(F("Raw Pulses:"));
    for (int i = 0; i < count; i++) {
        Serial.print(i);
        Serial.print(F(": "));
        Serial.print(pulses[i].duration);
        Serial.print(F("us "));
        Serial.println(pulses[i].isMark ? "MARK" : "SPACE");
    }
    Serial.println();
}

void printHex(uint32_t code) {
    Serial.print(F("Code (HEX): 0x"));
    Serial.println(code, HEX);
}

void printBinary(uint32_t code, uint8_t bits) {
    Serial.print(F("Code (BIN): "));
    for (int8_t i = bits - 1; i >= 0; i--) {
        Serial.print((code >> i) & 1);
    }
    Serial.println();
}

void printAsArray(IRPulse* pulses, int count) {
    Serial.println(F("Raw Pulse Array:"));
    Serial.print(F("uint16_t rawPulses[] = { "));
    for (int i = 0; i < count; i++) {
        Serial.print(pulses[i].duration);
        if (i < count - 1) Serial.print(F(", "));
    }
    Serial.println(F(" };"));
    Serial.print(F("// Total pulses: "));
    Serial.println(count);
    Serial.println();
}

void printSummary(IRPulse* pulses, int count) {
    Serial.println(F("Pulse Summary:"));
    Serial.print(F("Total Pulses: "));
    Serial.println(count);

    unsigned long totalTime = 0;
    int markCount = 0;
    int spaceCount = 0;

    for (int i = 0; i < count; i++) {
        totalTime += pulses[i].duration;
        if (pulses[i].isMark) markCount++;
        else spaceCount++;
    }

    Serial.print(F("Total Duration: "));
    Serial.print(totalTime);
    Serial.println(F(" us"));

    Serial.print(F("MARKs: "));
    Serial.print(markCount);
    Serial.print(F(" | SPACEs: "));
    Serial.println(spaceCount);
    Serial.println();
}

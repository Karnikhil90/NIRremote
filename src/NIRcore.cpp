#include "NIRcore.h"

// Internal buffer to store captured pulses
static IRPulse pulses[MAX_PULSES];
static int pulseCount = 0;
static uint8_t irPin;

/**
 * @brief Initialize the IR decoding engine.
 */
void Decode::begin(uint8_t pin) {
    irPin = pin;
    pinMode(irPin, INPUT);
}

/**
 * @brief Capture raw IR pulses using digitalRead and micros().
 */
bool Decode::capture() {
    pulseCount = 0;
    unsigned long startTime = micros();
    unsigned long lastTime = startTime;
    bool lastState = digitalRead(irPin);

    while ((micros() - startTime) < CAPTURE_TIMEOUT && pulseCount < MAX_PULSES) {
        bool currentState = digitalRead(irPin);
        if (currentState != lastState) {
            unsigned long now = micros();
            unsigned int duration = now - lastTime;

            pulses[pulseCount].type = lastState ? MARK : SPACE;
            pulses[pulseCount].duration = duration;
            pulseCount++;

            lastState = currentState;
            lastTime = now;
        }
    }

    return pulseCount > MIN_PULSES;
}

/**
 * @brief Print raw IR data to Serial.
 */
void Decode::debugPrint() {
    Serial.println(F("RAW PULSES:"));
    for (int i = 0; i < pulseCount; i++) {
        Serial.print(i);
        Serial.print(": ");
        Serial.print(pulses[i].type == MARK ? "MARK  " : "SPACE ");
        Serial.print(" - ");
        Serial.print(pulses[i].duration);
        Serial.println(" us");
    }
}

/**
 * @brief Decode captured pulses as Sony protocol.
 */
uint32_t Decode::decodeSony() {
    return NSony::decode(pulses, pulseCount);
}

/**
 * @brief Decode captured pulses as Samsung protocol.
 */
uint32_t Decode::decodeSamsung() {
    return NSamsung::decode(pulses, pulseCount);
}

/**
 * @brief Identify the brand from code.
 */
String Decode::detectBrand(uint32_t code) {
    return NBrand::getBrandName(code);
}

/**
 * @brief Return pointer to raw pulse buffer.
 */
IRPulse* Decode::getRawPulses() {
    return pulses;
}

/**
 * @brief Return number of valid pulses captured.
 */
int Decode::getPulseCount() {
    return pulseCount;
}

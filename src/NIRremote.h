/**
 * @file NIRremote.h
 * @brief Public interface header for the NIRremote Arduino library.
 *
 * This file provides a simple and unified API to interact with the library's decoding capabilities.
 * Designed for users to include only this file in their sketches to access the full functionality.
 *
 * @author
 * Nikhil Karmakar (https://github.com/karnikhil90)
 *
 * @version 1.0.0
 * @date July 21, 2025
 *
 * MIT License
 * Copyright (c) 2025 Nikhil Karmakar
 */

#ifndef NIRREMOTE_H
#define NIRREMOTE_H

#include "NIRcore.h"
#include "IRDebug.h"

/**
 * @class NIRremote
 * @brief High-level interface for using the NIRremote decoding features in Arduino sketches.
 *
 * This class wraps around the core decoding functionality and debug tools. It simplifies
 * access for users by allowing them to use a single instance for initialization, capturing,
 * decoding, and debugging IR signals.
 *
 * Example usage:
 * ```cpp
 * #include <NIRremote.h>
 *
 * NIRremote remote;
 *
 * void setup() {
 *     Serial.begin(115200);
 *     remote.begin(2); // Set your IR receiver pin
 * }
 *
 * void loop() {
 *     if (remote.capture()) {
 *         remote.printRaw(); // Optional debug
 *         uint32_t code = remote.decodeSony();
 *         Serial.print("Decoded: ");
 *         Serial.println(code, HEX);
 *     }
 * }
 * ```
 */
class NIRremote {
private:
    Decode decoder;

public:
    /**
     * @brief Initialize the NIRremote system with IR receiver pin.
     * @param pin GPIO pin connected to the IR receiver.
     */
    void begin(uint8_t pin) {
        decoder.begin(pin);
    }

    /**
     * @brief Capture raw IR signal and store its timing.
     * @return true if valid IR signal was captured.
     */
    bool capture() {
        return decoder.capture();
    }

    /**
     * @brief Attempt to decode a captured signal using the Sony protocol.
     * @return 32-bit decoded IR code, or 0 if invalid.
     */
    uint32_t decodeSony() {
        return decoder.decodeSony();
    }

    /**
     * @brief Optional debug: Print all captured pulses to Serial.
     */
    void printRaw() {
        printRaw(getRawPulses(), getPulseCount());
    }

    /**
     * @brief Returns pointer to captured pulse buffer.
     * @return IRPulse* array of captured pulses.
     */
    IRPulse* getRawPulses() {
        return decoder.getRawPulses();
    }

    /**
     * @brief Get count of captured IR pulses.
     * @return Number of captured pulses.
     */
    int getPulseCount() {
        return decoder.getPulseCount();
    }

    /**
     * @brief Detect brand from the decoded IR code.
     * @param code The decoded IR code.
     * @return String name of the guessed brand.
     */
    String detectBrand(uint32_t code) {
        return decoder.detectBrand(code);
    }
};

#endif // NIRREMOTE_H

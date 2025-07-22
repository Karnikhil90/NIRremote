/**
 * @file NIRcore.h
 * @brief Core IR decoding interface for the NIRremote library.
 *
 * This header defines the Decode class used to capture and decode
 * raw IR remote signals using various protocols like Sony and Samsung.
 * 
 * NIRremote is a lightweight and modular IR decoding library designed for 
 * learning, prototyping, and supporting multiple brands of IR remotes.
 * 
 * @author
 * Nikhil Karmakar (https://github.com/karnikhil90)
 *
 * @version 1.0.0
 * @date July 21, 2025
 * 
 * 
 * MIT License
 * 
 * Copyright (c) 2025 Nikhil Karmakar
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef NIRCORE_H
#define NIRCORE_H

#include "NProtocol.h"
#include "NSony.h"
#include "NSamsung.h"
#include "NBrand.h"
#include "NIRconfig.h"
#include "IRDebug.h"

/**
 * @class Decode
 * @brief Responsible for receiving and decoding IR signals using known protocols.
 *
 * This class handles capturing raw IR pulses (MARK and SPACE),
 * analyzing the signal, and decoding it based on known protocols
 * such as Sony or Samsung. It's meant to serve as the core IR decoding
 * engine in the NIRremote library.
 *
 * Typical usage:
 * ```cpp
 * Decode decoder;
 * decoder.begin(IR_RECEIVE_PIN);
 * if (decoder.capture()) {
 *     decoder.debugPrint();         // Optional for analysis
 *     uint32_t code = decoder.decodeSony();  // Try Sony
 *     Serial.println(code, HEX);
 * }
 * ```
 */
class Decode {
public:

    /**
     * @brief Initialize the IR decoding engine.
     * @param pin The GPIO pin number where the IR receiver is connected.
     */
    void begin(uint8_t pin);

    /**
     * @brief Capture a raw IR signal and store its pulse sequence.
     * @return true if a valid signal is captured, false otherwise.
     */
    bool capture();

    /**
     * @brief Print the captured IR pulse sequence to Serial in a human-readable format.
     */
    void debugPrint();

    /**
     * @brief Attempt to decode the captured signal using the Sony IR protocol.
     * @return Decoded 32-bit IR code if successful, 0 if invalid.
     */
    uint32_t decodeSony();

    /**
     * @brief Attempt to decode the captured signal using the Samsung IR protocol.
     * @return Decoded 32-bit IR code if successful, 0 if invalid.
     */
    uint32_t decodeSamsung();

    /**
     * @brief Attempt to identify the IR remote brand based on the decoded code.
     * @param code The decoded IR value.
     * @return A String representing the guessed brand name.
     */
    String detectBrand(uint32_t code);

    /**
     * @brief Get pointer to the internal buffer of captured IR pulses.
     * @return Pointer to the IRPulse array.
     */
    IRPulse* getRawPulses();

    /**
     * @brief Get the number of valid pulses captured.
     * @return Integer count of pulses.
     */
    int getPulseCount();
};

#endif // NIRCORE_H

/*
// Future class for sending IR signals
class Encode {
public:
    void sendSony(uint32_t data, uint8_t bits);
    void sendSamsung(uint32_t data, uint8_t bits);
};
*/

#endif // NIRCORE_H

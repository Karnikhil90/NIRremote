/**
 * @file NSamsung.h
 * @brief Samsung IR protocol decoder for the NIRremote library.
 *
 * This header defines logic for identifying and decoding IR signals
 * that follow the Samsung remote control protocol. It includes a class
 * to validate and decode the raw pulse stream into a 32-bit IR code.
 *
 * Samsung IR remotes typically use a NEC-like format with specific
 * pulse timings and leader codes.
 * 
 * @author
 * Nikhil Karmakar (https://github.com/karnikhil90)
 * 
 * @version 1.0.0
 * @date July 21, 2025
 * 
 */

#ifndef NSAMSUNG_H
#define NSAMSUNG_H

#include "NProtocol.h"

/**
 * @class SamsungProtocol
 * @brief Provides static functions to decode Samsung IR signals.
 *
 * The class contains utility functions to determine whether a captured
 * IR signal conforms to the Samsung IR protocol and, if valid,
 * decode the signal into a usable 32-bit value.
 */
class SamsungProtocol {
public:
    /**
     * @brief Checks if the pulse sequence matches Samsung protocol characteristics.
     * @param pulses Array of captured IRPulse data.
     * @param count Number of pulses in the signal.
     * @return true if the signal resembles Samsung format; false otherwise.
     */
    static bool isSamsung(IRPulse* pulses, int count);

    /**
     * @brief Decodes a Samsung-formatted IR pulse stream.
     * @param pulses Array of raw IR pulses.
     * @param count Length of the pulse array.
     * @return A 32-bit decoded IR value, or 0 if decoding fails.
     */
    static uint32_t decode(IRPulse* pulses, int count);
};

#endif // NSAMSUNG_H

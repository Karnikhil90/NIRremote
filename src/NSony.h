/**
 * @file NSony.h
 * @brief Sony IR protocol decoder for the NIRremote library.
 *
 * This header provides decoding logic specific to the Sony infrared protocol,
 * including validation and bit extraction from the raw IR pulse data.
 * 
 * The Sony protocol is simple and often used in consumer electronics like TVs and receivers.
 * This class and namespace allow decoding from captured raw IR signals.
 * 
 * @author
 * Nikhil Karmakar (https://github.com/karnikhil90)
 * 
 * @version 1.0.0
 * @date July 21, 2025
 * 
 */

#ifndef NSONY_H
#define NSONY_H

#include "NProtocol.h"

/**
 * @class SonyProtocol
 * @brief Provides static functions to validate and decode Sony IR signals.
 *
 * This utility class processes raw IR pulses to determine if they conform to the Sony
 * standard and, if valid, extract the data bits into a 32-bit IR code.
 */
class SonyProtocol {
public:
    /**
     * @brief Check whether a given pulse stream looks like Sony protocol.
     * @param pulses Array of captured IRPulse objects.
     * @param count Number of pulses in the array.
     * @return true if the signal resembles Sony protocol, false otherwise.
     */
    static bool isSony(IRPulse* pulses, int count);

    /**
     * @brief Decode the pulse stream assuming it's in Sony format.
     * @param pulses Array of IR pulses to decode.
     * @param count Total number of pulses.
     * @return 32-bit decoded IR code if valid, 0 otherwise.
     */
    static uint32_t decode(IRPulse* pulses, int count);
};

/**
 * @namespace NSony
 * @brief Simple wrapper namespace for decoding Sony protocol signals.
 */
namespace NSony {
    /**
     * @brief Decode Sony IR signals via the SonyProtocol class.
     * @param pulses Raw IR pulse buffer.
     * @param count Total pulse count.
     * @return Decoded 32-bit code or 0 on failure.
     */
    uint32_t decode(IRPulse* pulses, int count);
}

#endif // NSONY_H

/**
 * @file NSony.cpp
 * @brief Implements decoding logic for Sony IR protocol in the NIRremote library.
 * 
 * The Sony IR protocol uses variable bit encoding with fixed timing.
 * Logic here attempts to identify and decode such signals based on pulse length patterns.
 * 
 * @author
 * Nikhil Karmakar (https://github.com/karnikhil90)
 * 
 * @version 1.0.0
 * @date July 21, 2025
 */

#include "NSony.h"

#define SONY_HEADER_MARK 2400   ///< Typical Sony header mark in microseconds
#define SONY_HEADER_SPACE 600   ///< Typical Sony header space in microseconds
#define SONY_BIT_MARK 600       ///< Length of logical 0/1 bit mark
#define SONY_ONE_SPACE 1200     ///< Space length for logical 1
#define SONY_ZERO_SPACE 600     ///< Space length for logical 0
#define SONY_TOLERANCE 200      ///< Timing tolerance for matching

bool SonyProtocol::isSony(IRPulse* pulses, int count) {
    if (count < 3) return false;

    // Check header pulse (MARK + SPACE)
    int mark = pulses[0].duration;
    int space = pulses[1].duration;

    return abs(mark - SONY_HEADER_MARK) < SONY_TOLERANCE &&
           abs(space - SONY_HEADER_SPACE) < SONY_TOLERANCE;
}

uint32_t SonyProtocol::decode(IRPulse* pulses, int count) {
    if (!isSony(pulses, count)) return 0;

    uint32_t data = 0;
    int bits = 0;

    // Start decoding from pulse[2] (after header)
    for (int i = 2; i + 1 < count; i += 2) {
        int mark = pulses[i].duration;
        int space = pulses[i + 1].duration;

        if (abs(mark - SONY_BIT_MARK) > SONY_TOLERANCE) break;

        if (abs(space - SONY_ONE_SPACE) < SONY_TOLERANCE) {
            data |= (1UL << bits);
        } else if (abs(space - SONY_ZERO_SPACE) < SONY_TOLERANCE) {
            // bit is already 0; do nothing
        } else {
            break; // Invalid space timing
        }

        bits++;
        if (bits >= 32) break;
    }

    return data;
}

// Convenience wrapper namespace
namespace NSony {
    uint32_t decode(IRPulse* pulses, int count) {
        return SonyProtocol::decode(pulses, count);
    }
}

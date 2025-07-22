#ifndef IRDEBUG_H
#define IRDEBUG_H

#include <Arduino.h>
#include "NProtocol.h"

/**
 * @brief Print all pulses in raw format (duration + MARK/SPACE).
 * @param pulses Array of IRPulse structures.
 * @param count Number of pulses captured.
 */
void printRaw(IRPulse* pulses, int count);

/**
 * @brief Print decoded code in hexadecimal format.
 * @param code The decoded 32-bit IR signal.
 */
void printHex(uint32_t code);

/**
 * @brief Print all pulses in C-array style (good for saving).
 * @param pulses Array of IRPulse.
 * @param count Total number of pulses.
 *
 * This will output something like:
 * `{900, 450, 600, 600, ...}`
 */
void printAsArray(IRPulse* pulses, int count);

/**
 * @brief Print summary (total pulses, total time, etc.)
 * @param pulses Pulse array
 * @param count Count of pulses
 */
void printSummary(IRPulse* pulses, int count);

/**
 * @brief Print binary representation of the decoded code.
 * @param code Decoded IR value
 * @param bits Number of bits (optional, defaults to 32)
 */
void printBinary(uint32_t code, uint8_t bits = 32);

#endif // IRDEBUG_H

#ifndef IRTYPES_H
#define IRTYPES_H

enum PulseType { MARK, SPACE };

struct IRPulse {
    PulseType type;
    uint16_t duration; // in microseconds
};

#endif

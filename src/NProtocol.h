#define MAX_PULSES 100
#define CAPTURE_TIMEOUT 50000
#define MIN_PULSES 10

enum PulseType { MARK, SPACE };

struct IRPulse {
    PulseType type;
    unsigned int duration;
};

namespace NBrand {
    String getBrandName(uint32_t code);
}


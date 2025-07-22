#ifndef NBRAND_H
#define NBRAND_H

#include <Arduino.h>

enum Brand {
    BRAND_UNKNOWN,
    BRAND_SONY,
    BRAND_SAMSUNG,
};

const char* brandToString(Brand b);

#endif

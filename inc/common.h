#ifndef HOUSTON_COMMON_H
#define HOUSTON_COMMON_H

#include <stdint.h>

inline uint8_t houston_common_mapToUint8(unsigned int min, unsigned int max, unsigned int val) {
    return min == max ? 0 : (uint8_t) (((val < min ? min : (val > max ? max : val)) - min) * 255 / (max - min));
}

#endif

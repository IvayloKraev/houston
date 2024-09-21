#ifndef HOUSTON_COMMON_H
#define HOUSTON_COMMON_H

#include "FreeRTOSConfig.h"

#define tskCRITICAL_PRORITY (configMAX_PRIORITIES - 1)

typedef enum {
    huston_OK,
    huston_ERR,
    huston_WARN
} huston_RESULT;

#endif

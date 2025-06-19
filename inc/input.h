#ifndef HOUSTON_INPUT_H
#define HOUSTON_INPUT_H

#include <stdint.h>

#include "hardware/gpio.h"
#include "hardware/adc.h"

#include "hcst/error.h"

#include "config.h"

typedef struct {
    bool dragEnable;
    bool forward;
    bool backward;
    bool leftSpin;
    bool rightSpin;
    bool joystickBtn;
    uint16_t joystickX;
    uint16_t joystickY;
    uint16_t speed;
} inputData_t;

hcst_error_t houston_input_init();

hcst_error_t houston_input_read(inputData_t*);

#endif

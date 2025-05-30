#ifndef HOUSTON_INPUT_H
#define HOUSTON_INPUT_H

#include <stdint.h>

#include "hardware/gpio.h"
#include "hardware/adc.h"

#include "hcst/message.h"
#include "hcst/state.h"

#include "common.h"

#define ENABLE_MOTORS_PIN   2
#define LEFT_SPIN_PIN       3
#define RIGHT_SPIN_PIN      4

#define SPEED_ADC           2
#define SPEED_PIN           (SPEED_ADC + 26)

houston_RESULT houston_input_init();

_Noreturn void houston_input_watch(void*);

#endif

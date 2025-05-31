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

hcst_ERROR_t houston_input_init();

hcst_ERROR_t houston_input_tick(hcst_message_t);

#endif

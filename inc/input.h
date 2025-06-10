#ifndef HOUSTON_INPUT_H
#define HOUSTON_INPUT_H

#include <stdint.h>

#include "hardware/gpio.h"
#include "hardware/adc.h"

#include "hcst/message.h"
#include "hcst/state.h"

#include "common.h"

#define DRAG_ENABLE_PIN     22

#define FORWARD_PIN         21
#define BACKWARD_PIN        20
#define LEFT_SPIN_PIN       19
#define RIGHT_SPIN_PIN      18

#define JOYSTICK_X_ADC      0
#define JOYSTICK_X_PIN      (JOYSTICK_X_ADC + 26)

#define JOYSTICK_Y_ADC      1
#define JOYSTICK_Y_PIN      (JOYSTICK_Y_ADC + 26)

#define SPEED_ADC           2
#define SPEED_PIN           (SPEED_ADC + 26)

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

hcst_ERROR_t houston_input_tick(hcst_message_t);

#endif

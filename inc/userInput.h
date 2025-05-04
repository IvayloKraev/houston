#ifndef HOUSTON_USERINPUT_H
#define HOUSTON_USERINPUT_H

#include <stdint.h>
#include "stdbool.h"

#include "hardware/gpio.h"
#include "hardware/adc.h"

#include "FreeRTOS.h"
#include "task.h"

#define START_MOTORS_PIN    2
#define STOP_MOTORS_PIN     3
#define LEFT_TURN_PIN       4
#define RIGHT_TURN_PIN      5

#define SPEED_CTRL_ADC      2
#define SPEED_CTRL_PIN      (SPEED_CTRL_ADC + 26)

typedef struct {
    bool startMotors;
    bool stopMotors;
    bool leftTurn;
    bool rightTurn;
    uint16_t speed;
} rawUserInput_t;

typedef rawUserInput_t *rawUserInput_handler_t;

_Noreturn void houston_userInput_getState(void *);

#endif

#include "userInput.h"

_Noreturn void houston_userInput_getState(void *paramsPtr) {
    rawUserInput_handler_t rawUserInput = (rawUserInput_handler_t) paramsPtr;

    gpio_init(START_MOTORS_PIN);
    gpio_set_dir(START_MOTORS_PIN, GPIO_IN);

    gpio_init(STOP_MOTORS_PIN);
    gpio_set_dir(STOP_MOTORS_PIN, GPIO_IN);

    gpio_init(LEFT_TURN_PIN);
    gpio_set_dir(LEFT_TURN_PIN, GPIO_IN);

    gpio_init(RIGHT_TURN_PIN);
    gpio_set_dir(RIGHT_TURN_PIN, GPIO_IN);

    adc_init();
    adc_gpio_init(SPEED_CTRL_PIN);

    HOUSTON_STATUS_WAIT_WIFI_DONE();

    while (1) {
        rawUserInput->startMotors = gpio_get(START_MOTORS_PIN);
        rawUserInput->stopMotors = gpio_get(STOP_MOTORS_PIN);
        rawUserInput->leftTurn = gpio_get(LEFT_TURN_PIN);
        rawUserInput->rightTurn = gpio_get(RIGHT_TURN_PIN);

        adc_select_input(SPEED_CTRL_ADC);
        rawUserInput->speed = adc_read();

        HOUSTON_STATUS_SET_RAW_USER_INPUT();

        vTaskDelay(10);
    }
};

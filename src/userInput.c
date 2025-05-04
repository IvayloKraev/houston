#include "userInput.h"

houston_RESULT houston_userInput_init() {
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

    return houston_OK;
}

_Noreturn void houston_userInput_getState() {
    while (1) {
        gpio_get(START_MOTORS_PIN);
        gpio_get(STOP_MOTORS_PIN);
        gpio_get(LEFT_TURN_PIN);
        gpio_get(RIGHT_TURN_PIN);

        adc_select_input(SPEED_CTRL_ADC);
        adc_read();

        vTaskDelay(10);
    }
};

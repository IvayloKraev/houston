#include "input.h"

houston_RESULT houston_input_init() {
    gpio_init(ENABLE_MOTORS_PIN);
    gpio_set_dir(ENABLE_MOTORS_PIN, GPIO_IN);

    gpio_init(LEFT_SPIN_PIN);
    gpio_set_dir(LEFT_SPIN_PIN, GPIO_IN);

    gpio_init(RIGHT_SPIN_PIN);
    gpio_set_dir(RIGHT_SPIN_PIN, GPIO_IN);

    adc_init();
    adc_gpio_init(SPEED_PIN);

    return houston_OK;
}

_Noreturn void houston_input_watch() {
    while (1) {
        hcst_message_t message;
        hcst_MESSAGE_INIT(message);

        const uint8_t motorsEnabled = gpio_get(ENABLE_MOTORS_PIN),
                      leftSpin = gpio_get(LEFT_SPIN_PIN),
                      rightSpin = gpio_get(RIGHT_SPIN_PIN);

        adc_select_input(SPEED_CTRL_ADC);
        adc_read();
        adc_select_input(SPEED_ADC);
        const uint16_t speed = adc_read();

        vTaskDelay(10);

        free(message);
    }
};

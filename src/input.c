#include "input.h"

hcst_ERROR_t houston_input_init() {
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

_Noreturn void houston_input_watch(void *paramsPtr) {
    const sendMessageFn_t send = paramsPtr;

    while (1) {
        hcst_message_t message;
        hcst_MESSAGE_INIT(message);

        const uint8_t motorsEnabled = gpio_get(ENABLE_MOTORS_PIN),
                leftSpin = gpio_get(LEFT_SPIN_PIN),
                rightSpin = gpio_get(RIGHT_SPIN_PIN);

        adc_select_input(SPEED_ADC);
        const uint16_t speed = adc_read();

        hcst_powerMotor_set(message, hcst_FLM_BIT, motorsEnabled);
        hcst_powerMotor_set(message, hcst_FRM_BIT, motorsEnabled);
        hcst_powerMotor_set(message, hcst_RLM_BIT, motorsEnabled);
        hcst_powerMotor_set(message, hcst_RRM_BIT, motorsEnabled);

        hcst_directionMotor_set(message, hcst_FLM_BIT, 1);
        hcst_directionMotor_set(message, hcst_FRM_BIT, 1);
        hcst_directionMotor_set(message, hcst_RLM_BIT, 1);
        hcst_directionMotor_set(message, hcst_RRM_BIT, 1);

        if (leftSpin) {
            hcst_directionMotor_set(message, hcst_FLM_BIT, 0);
            hcst_directionMotor_set(message, hcst_RLM_BIT, 0);
        } else if (rightSpin) {
            hcst_directionMotor_set(message, hcst_FRM_BIT, 0);
            hcst_directionMotor_set(message, hcst_RRM_BIT, 0);
        }

        hcst_speed_set(message, houston_common_mapToUint8(0, 4098, speed));

        send(message);

        vTaskDelay(TICK_BETWEEN_LOOPS);

        free(message);
    }
}

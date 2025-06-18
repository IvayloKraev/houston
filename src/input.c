#include "input.h"

hcst_error_t houston_input_init() {
    gpio_init(DRAG_ENABLE_PIN);
    gpio_init(FORWARD_PIN);
    gpio_init(BACKWARD_PIN);
    gpio_init(LEFT_SPIN_PIN);
    gpio_init(RIGHT_SPIN_PIN);
    gpio_init(JOYSTICK_BTN_PIN);

    adc_init();
    adc_gpio_init(SPEED_PIN);
    adc_gpio_init(JOYSTICK_X_PIN);
    adc_gpio_init(JOYSTICK_Y_PIN);

    return hcst_error_none;
}

hcst_error_t houston_input_read(inputData_t* inputData) {
    if (inputData == NULL)
        return hcst_error_nullPtr;

    inputData->dragEnable = gpio_get(DRAG_ENABLE_PIN);
    inputData->forward = gpio_get(FORWARD_PIN);
    inputData->backward = gpio_get(BACKWARD_PIN);
    inputData->leftSpin = gpio_get(LEFT_SPIN_PIN);
    inputData->rightSpin = gpio_get(RIGHT_SPIN_PIN);

    inputData->joystickBtn = gpio_get(JOYSTICK_BTN_PIN);

    adc_select_input(SPEED_ADC);
    inputData->speed = adc_read();

    adc_select_input(JOYSTICK_X_ADC);
    inputData->joystickX = adc_read();

    adc_select_input(JOYSTICK_Y_ADC);
    inputData->joystickY = adc_read();

    return hcst_error_none;
}

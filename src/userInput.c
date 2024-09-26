#include "userInput.h"

rawUserInput_t userInput_raw = {};
QueueHandle_t userInput_rawCommandQueue = NULL;

void houston_userInput_init(QueueHandle_t newRawCommandQueue) {

    if(newRawCommandQueue == NULL) {
        stdio_printf("Raw Command Queue is NULL\n");
        return;
    }

    userInput_rawCommandQueue = newRawCommandQueue;

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
}

void houston_userInput_getState() {
    while (1) {
        userInput_raw.startMotors = gpio_get(START_MOTORS_PIN);
        userInput_raw.stopMotors = gpio_get(STOP_MOTORS_PIN);
        userInput_raw.leftTurn = gpio_get(LEFT_TURN_PIN);
        userInput_raw.rightTurn = gpio_get(RIGHT_TURN_PIN);

        adc_select_input(SPEED_CTRL_ADC);
        userInput_raw.speed = adc_read();

        xQueueSendToBack(userInput_rawCommandQueue, &userInput_raw, (TickType_t) 10);

        stdio_printf(
            "startMotors: %d\n"
            "stopMotors: %d\n"
            "leftTurn: %d\n"
            "rightTun: %d\n"
            "speed: %d\n",
            userInput_raw.startMotors,
            userInput_raw.stopMotors,
            userInput_raw.leftTurn,
            userInput_raw.rightTurn,
            userInput_raw.speed);

        vTaskDelay(100);
    }
};
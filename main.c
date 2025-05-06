#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"

#include "FreeRTOS.h"
#include "task.h"

#include "wifiCtrl.h"
#include "input.h"
#include "common.h"
#include "socket.h"

static wifiConfig_t wifiConfig = {
    .ssid = "Houston",
    .password = "12345678"
};

static QueueHandle_t inputQueue;

static BaseType_t sendFromInput(hcst_message_t message) {
    xQueueOverwrite(inputQueue, message);
};

int main(void) {
    stdio_usb_init();

    sleep_ms(5000);

    stdio_printf("Start init\n");

    inputQueue = xQueueCreate(1, sizeof(uint8_t)*hcst_MESSAGE_SIZE_BYTES);

    houston_input_init();

    stdio_printf("Start loop logic\n");

    xTaskCreate(
        huston_wifiCtrl_init,
        "huston_wifiCtrl_init",
        configMINIMAL_STACK_SIZE,
        &wifiConfig,
        tskCRUCIAL_PRIORITY,
        NULL
    );

    xTaskCreate(
        houston_input_watch,
        "houston_userInput_getState",
        configMINIMAL_STACK_SIZE,
        &sendFromInput,
        tskNORMAL_PRIORITY,
        NULL
    );

    xTaskCreate(
        houston_socket_pipeData,
        "houston_socket_pipeData",
        configMINIMAL_STACK_SIZE,
        NULL,
        tskNORMAL_PRIORITY,
        NULL
    );

    vTaskStartScheduler();
    return 0;
}

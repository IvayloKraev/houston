#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"

#include "FreeRTOS.h"
#include "task.h"

#include "wifiCtrl.h"
#include "userInput.h"

wifiConfig_t wifiConfig = {
    .ssid = "Houston",
    .password = "123456789"
};

QueueHandle_t rawCommandQueue;


int main(void)
{
    stdio_usb_init();

    rawCommandQueue = xQueueCreate(1, sizeof(struct rawUserInput_t*));

    sleep_ms(5000);

    stdio_printf("Start program\n");

    houston_userInput_init(rawCommandQueue);

    stdio_printf("userInput init\n");

    xTaskCreate(
            huston_wifiCtrl_init,
            "huston_wifiCtrl_init",
            configMINIMAL_STACK_SIZE,
            &wifiConfig,
            tskCRITICAL_PRORITY,
            NULL
            );

    xTaskCreate(
            houston_userInput_getState,
            "houston_userInput_getState",
            configMINIMAL_STACK_SIZE,
            NULL,
            tskCRITICAL_PRORITY,
            NULL
            );

    vTaskStartScheduler();
    return 0;
}

#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"

#include "FreeRTOS.h"
#include "task.h"

#include "wifiCtrl.h"
#include "userInput.h"
#include "encodeCommands.h"

wifiConfig_t wifiConfig = {
    .ssid = "Houston",
    .password = "123456789"
};

rawUserInput_t rawUserInput = {};
hctp_message_t m={};

TaskHandle_t houston_userInput_getState_handle;
UBaseType_t houston_userInput_getState_CoreAffinityMask = (1 << 1);

int main(void)
{
    stdio_usb_init();

    sleep_ms(5000);

    stdio_printf("Start program\n");

    hctp_message_init(m);

    houston_userInput_init(&rawUserInput);
    houston_encodeCommands_init(&rawUserInput, m);

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
            &houston_userInput_getState_handle
            );

    xTaskCreate(
            houston_encodeCommands_receive,
            "houston_encodeCommands_receive",
            configMINIMAL_STACK_SIZE,
            NULL,
            tskCRITICAL_PRORITY,
            NULL
    );

//    vTaskCoreAffinitySet(
//            houston_userInput_getState_handle,
//            houston_userInput_getState_CoreAffinityMask
//            );

    vTaskStartScheduler();
    return 0;
}

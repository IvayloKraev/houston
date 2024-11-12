#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"

#include "FreeRTOS.h"
#include "task.h"

#include "wifiCtrl.h"
#include "userInput.h"
#include "encodeCommands.h"
#include "status.h"
#include "socket.h"

static wifiConfig_t wifiConfig = {
    .ssid = "Houston",
    .password = "12345678"
};

static rawUserInput_t rawUserInput = {};
static hctp_message_t houston_message = {};

static TaskHandle_t houston_userInput_getState_handle;
static UBaseType_t houston_userInput_getState_CoreAffinityMask = (1 << 1);

static houston_encodeCommands_params_t  houston_encodeCommands_params;

int main(void)
{
    stdio_usb_init();

    sleep_ms(5000);

    stdio_printf("Start init\n");

    hctp_message_init(houston_message);

    houston_encodeCommands_params = (houston_encodeCommands_params_t){
            .newRawCommand = &rawUserInput,
            .message = houston_message
    };

    houston_status_init();

    stdio_printf("Start loop logic\n");

    xTaskCreate(
            houston_wifiCtrl_init,
            "houston_wifiCtrl_init",
            configMINIMAL_STACK_SIZE,
            &wifiConfig,
            tskCRUCIAL_PRIORITY,
            NULL
            );

    xTaskCreate(
            houston_userInput_getState,
            "houston_userInput_getState",
            configMINIMAL_STACK_SIZE,
            &rawUserInput,
            tskNORMAL_PRIORITY,
            &houston_userInput_getState_handle
            );

    xTaskCreate(
            houston_encodeCommands_receive,
            "houston_encodeCommands_receive",
            configMINIMAL_STACK_SIZE,
            &houston_encodeCommands_params,
            tskNORMAL_PRIORITY,
            NULL
    );

    xTaskCreate(
            houston_socket_pipeData,
            "houston_socket_pipeData",
            configMINIMAL_STACK_SIZE,
            houston_message,
            tskNORMAL_PRIORITY,
            NULL
    );

    vTaskStartScheduler();
    return 0;
}

#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"

#include "FreeRTOS.h"
#include "task.h"

#include "wifiCtrl.h"

wifiConfig_t wifiConfig = {
    .ssid = "Houston",
    .password = "123456789"
};

int main(void)
{
    stdio_usb_init();

    sleep_ms(5000);

    stdio_printf("Start program\n");

    xTaskCreate(
            huston_wifiCtrl_init,
            "huston_wifiCtrl_init",
            configMINIMAL_STACK_SIZE,
            &wifiConfig,
            tskCRITICAL_PRORITY,
            NULL
            );

    vTaskStartScheduler();
    return 0;
}

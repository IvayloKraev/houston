#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"

#include "FreeRTOS.h"
#include "task.h"
#include "input.h"
#include "common.h"
#include "socket.h"

int main(void) {
    stdio_usb_init();

    sleep_ms(5000);

    stdio_printf("Start init\n");

    houston_input_init();

    stdio_printf("Start loop logic\n");

    return 0;
}

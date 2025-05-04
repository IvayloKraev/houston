#ifndef HOUSTON_WIFICTRL_H
#define HOUSTON_WIFICTRL_H

#include <pico/cyw43_arch.h>
#include <pico/stdio_usb.h>

#include "FreeRTOS.h"
#include "task.h"

#define CYW43_COUNTRY_BULGARIA CYW43_COUNTRY('B', 'G', 0)

typedef struct {
    const char *ssid;
    const char *password;
} wifiConfig_t;

typedef wifiConfig_t *wifiConfigHandler_t;

_Noreturn void huston_wifiCtrl_init(void *);

#endif

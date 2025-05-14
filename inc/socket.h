#ifndef HOUSTON_SOCKET_H
#define HOUSTON_SOCKET_H

#include <pico/cyw43_arch.h>
#include <pico/stdio.h>
#include <lwip/api.h>
#include <lwip/netif.h>

#include "FreeRTOS.h"
#include "task.h"

#include "hcst/message.h"

#define WIFI 1

#define CYW43_COUNTRY_BULGARIA CYW43_COUNTRY('B', 'G', 0)

typedef struct {
    const char *ssid;
    const char *password;
    uint32_t auth;
} wifiConfig_t;

typedef wifiConfig_t *wifiConfigHandler_t;

_Noreturn void houston_socket_init();
_Noreturn void houston_socket_send(void*);

#endif

#ifndef HOUSTON_SOCKET_H
#define HOUSTON_SOCKET_H


#include <pico/stdio.h>
#include <lwip/api.h>
#include <lwip/netif.h>

#include "FreeRTOS.h"
#include "task.h"

#include "hcst/message.h"

_Noreturn void houston_socket_pipeData();

#endif

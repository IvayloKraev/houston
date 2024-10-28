#ifndef HOUSTON_STATUS_H
#define HOUSTON_STATUS_H

#include "FreeRTOS.h"
#include "event_groups.h"

#define HOUSTON_STATUS_WIFI_DONE (1 << 0)
#define HOUSTON_STATUS_RAW_USER_INPUT (1 << 1)

#define HOUSTON_STATUS_WAIT_WIFI_DONE() houston_status_waitStatus(HOUSTON_STATUS_WIFI_DONE, pdFALSE)
#define HOUSTON_STATUS_SET_WIFI_DONE() houston_status_setStatus(HOUSTON_STATUS_WIFI_DONE)

#define HOUSTON_STATUS_WAIT_RAW_USER_INPUT() houston_status_waitStatus(HOUSTON_STATUS_RAW_USER_INPUT, pdTRUE);
#define HOUSTON_STATUS_SET_RAW_USER_INPUT() houston_status_setStatus(HOUSTON_STATUS_RAW_USER_INPUT);


void houston_status_init();

void houston_status_waitStatus(EventBits_t, BaseType_t);

void houston_status_setStatus(EventBits_t);


#endif

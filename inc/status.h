#ifndef HOUSTON_STATUS_H
#define HOUSTON_STATUS_H

#include "FreeRTOS.h"
#include "event_groups.h"

#define HOUSTON_STATUS_WIFI_DONE (1 << 0)

#define HOUSTON_STATUS_WAIT_WIFI_DONE() houston_status_waitStatus(HOUSTON_STATUS_WIFI_DONE)
#define HOUSTON_STATUS_SET_WIFI_DONE() houston_status_setStatus(HOUSTON_STATUS_WIFI_DONE)

void houston_status_init();

void houston_status_waitStatus(EventBits_t);

void houston_status_setStatus(EventBits_t);


#endif

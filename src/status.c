#include "status.h"

static EventGroupHandle_t houston_status_eventGroup;

void houston_status_init() {
    houston_status_eventGroup = xEventGroupCreate();
}

void houston_status_waitStatus(EventBits_t bitsToWait) {
    do {
        EventBits_t wifiBit =
                xEventGroupWaitBits(
                    houston_status_eventGroup,
                    bitsToWait,
                    pdFALSE,
                    pdTRUE,
                    portMAX_DELAY
                );

        if (wifiBit != 0) return;

        vTaskDelay(10 / portTICK_PERIOD_MS);
    } while (1);
}

void houston_status_setStatus(EventBits_t bits) {
    xEventGroupSetBits(houston_status_eventGroup, bits);
}

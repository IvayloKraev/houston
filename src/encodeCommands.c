#include "encodeCommands.h"

QueueHandle_t encodeCommands_rawCommandQueue = NULL;

void houston_encodeCommands_init(QueueHandle_t newRawCommandQueue) {
    if(newRawCommandQueue == NULL) {
        stdio_printf("Raw Command Queue is NULL\n");
        return;
    }

    encodeCommands_rawCommandQueue = newRawCommandQueue;
}


_Noreturn void houston_encodeCommands_recieve() {
    while (1) {
        rawUserInput_t rawUserInput;
        hctp_message_t message = {};

        if(xQueueReceive(encodeCommands_rawCommandQueue, &rawUserInput, (TickType_t) 10) == pdTRUE) {
            hctp_speed_get(message);
        }

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
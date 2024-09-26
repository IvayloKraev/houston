#ifndef HOUSTON_ENCODECOMMANDS_H
#define HOUSTON_ENCODECOMMANDS_H


#include "pico/stdio_usb.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "hctp/messageModel.h"
#include "hctp/control.h"
#include "hctp/speed.h"

#include "userInput.h"

typedef struct {

} handledCommand_t;

void houston_encodeCommands_init(QueueHandle_t);

_Noreturn void houston_encodeCommands_recieve();

#endif

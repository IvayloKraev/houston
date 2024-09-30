#ifndef HOUSTON_ENCODECOMMANDS_H
#define HOUSTON_ENCODECOMMANDS_H


#include "pico/stdio_usb.h"

#include "FreeRTOS.h"
#include "task.h"

#include "hctp/messageModel.h"
#include "hctp/control.h"
#include "hctp/speed.h"
#include "hctp/encodeMessage.h"

#include "userInput.h"
#include "common.h"

typedef struct {
    rawUserInput_handler_t newRawCommand;
    hctp_message_t message;
} houston_encodeCommands_params_t;

_Noreturn void houston_encodeCommands_receive(void*);

#endif

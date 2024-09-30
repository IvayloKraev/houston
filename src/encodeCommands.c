#include "encodeCommands.h"

rawUserInput_handler_t houston_encodeCommands_rawCommand;
hctp_message_t houston_message;
hctp_message_readyToEncode_t houston_encodeCommands_base = {
        .motorState = 0,
        .leftTurn = 0,
        .rightTurn = 0,
        .speed = 0
};

void houston_encodeCommands_init(rawUserInput_handler_t newRawCommand, hctp_message_t message) {
    if(newRawCommand == NULL) {
        stdio_printf("Raw Command is NULL\n");
        return;
    }

    if(message == NULL) {
        stdio_printf("Message is NULL\n");
        return;
    }

    houston_encodeCommands_rawCommand = newRawCommand;
    houston_message = message;
}

_Noreturn void houston_encodeCommands_receive() {
    while (1) {
        houston_encodeCommands_base = (hctp_message_readyToEncode_t){
                .motorState = (houston_encodeCommands_rawCommand->stopMotors == 1) ? 0 :
                              (houston_encodeCommands_rawCommand->startMotors == 1) ? 1 :
                              houston_encodeCommands_base.motorState,
                .leftTurn = houston_encodeCommands_rawCommand->leftTurn,
                .rightTurn = houston_encodeCommands_rawCommand->rightTurn,
                .speed = houston_common_mapToUint8(20, 4080, houston_encodeCommands_rawCommand->speed)
        };

        hctp_message_encode(&houston_encodeCommands_base, houston_message);

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
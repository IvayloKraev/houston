#include "encodeCommands.h"

_Noreturn void houston_encodeCommands_receive(void* paramsPtr) {
    houston_encodeCommands_params_t *params = (houston_encodeCommands_params_t*)paramsPtr;

    hctp_message_readyToEncode_t encodeCommands_base = {
            .motorState = 0,
            .leftTurn = 0,
            .rightTurn = 0,
            .speed = 0
    };

    while (1) {
        encodeCommands_base = (hctp_message_readyToEncode_t){
                .motorState = (params->newRawCommand->stopMotors == 1) ? 0 :
                              (params->newRawCommand->startMotors == 1) ? 1 :
                              encodeCommands_base.motorState,
                .leftTurn = params->newRawCommand->leftTurn,
                .rightTurn = params->newRawCommand->rightTurn,
                .speed = houston_common_mapToUint8(20, 4080, params->newRawCommand->speed)
        };

        hctp_message_encode(&encodeCommands_base, params->message);

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
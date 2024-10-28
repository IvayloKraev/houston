#include "encodeCommands.h"

#include <string.h>
#include <pico/stdio.h>

#define PRINT_UINT8_BITS(x) do {            \
for (int _i = 7; _i >= 0; _i--) {      \
stdio_printf("%d", ((x) >> _i) & 1);     \
}                                       \
stdio_printf("\n");                           \
} while(0)

_Noreturn void houston_encodeCommands_receive(void *paramsPtr) {
    const houston_encodeCommands_params_t *params = (houston_encodeCommands_params_t *) paramsPtr;

    hctp_message_readyToEncode_t encodeCommands_base = {
        .motorState = 0,
        .leftTurn = 0,
        .rightTurn = 0,
        .speed = 0
    };

    hctp_message_readyToEncode_t encodeCommands_current = {
        .motorState = 0,
        .leftTurn = 0,
        .rightTurn = 0,
        .speed = 0
    };

    HOUSTON_STATUS_WAIT_WIFI_DONE();

    while (1) {

        HOUSTON_STATUS_WAIT_RAW_USER_INPUT();

        encodeCommands_current = (hctp_message_readyToEncode_t){
            .motorState =   (params->newRawCommand->stopMotors == 1) ? 0 :
                            (params->newRawCommand->startMotors == 1) ? 1 :
                            encodeCommands_base.motorState,
            .leftTurn = params->newRawCommand->leftTurn,
            .rightTurn = params->newRawCommand->rightTurn,
            .speed = houston_common_mapToUint8(100, 4000, params->newRawCommand->speed)
        };

        if(encodeCommands_current.motorState != encodeCommands_base.motorState ||
            encodeCommands_current.leftTurn != encodeCommands_base.leftTurn ||
            encodeCommands_current.rightTurn != encodeCommands_base.rightTurn) {
            hctp_message_encode(&encodeCommands_current, params->message);

        }

        encodeCommands_base.motorState = encodeCommands_current.motorState;
        encodeCommands_base.leftTurn = encodeCommands_current.leftTurn;
        encodeCommands_base.rightTurn = encodeCommands_current.rightTurn;
        encodeCommands_base.speed = encodeCommands_current.speed;
    }
}

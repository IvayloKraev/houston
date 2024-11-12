#include "encodeCommands.h"

_Noreturn void houston_encodeCommands_receive(void *params) {
    rawUserInput_handler_t rawUserInput = ((houston_encodeCommands_params_t *) params)->newRawCommand;
    hctp_message_t message = ((houston_encodeCommands_params_t *) params)->message;

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
            .motorState =   (rawUserInput->stopMotors == 1) ? 0 :
                            (rawUserInput->startMotors == 1) ? 1 :
                            encodeCommands_base.motorState,
            .leftTurn = rawUserInput->leftTurn,
            .rightTurn = rawUserInput->rightTurn,
            .speed = houston_common_mapToUint8(100, 4000, rawUserInput->speed)
        };

        if(encodeCommands_current.motorState != encodeCommands_base.motorState ||
            encodeCommands_current.leftTurn != encodeCommands_base.leftTurn ||
            encodeCommands_current.rightTurn != encodeCommands_base.rightTurn) {
            hctp_message_encode(&encodeCommands_current, message);
            HOUSTON_STATUS_SET_ENCODED_COMMAND();
        }

        encodeCommands_base.motorState = encodeCommands_current.motorState;
        encodeCommands_base.leftTurn = encodeCommands_current.leftTurn;
        encodeCommands_base.rightTurn = encodeCommands_current.rightTurn;
        encodeCommands_base.speed = encodeCommands_current.speed;
    }
}

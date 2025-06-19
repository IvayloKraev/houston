#ifndef HOUSTON_CONFIG_H
#define HOUSTON_CONFIG_H

// Wait time
#define MS_BETWEEN_LOOPS 10
#define TICK_BETWEEN_LOOPS pdMS_TO_TICKS(MS_BETWEEN_LOOPS)

// Tasks
#define tskNORMAL_PRIORITY 1
#define tskCRUCIAL_PRIORITY ((configMAX_PRIORITIES - 1) | portPRIVILEGE_BIT)

// Socket
#define WIFI                            1
#define CYW43_COUNTRY_BULGARIA          CYW43_COUNTRY('B', 'G', 0)
#define CURRENT_COUNTRY                 CYW43_COUNTRY_BULGARIA
#define WIFI_SSID                       "Houston"
#define WIFI_PASSWORD                   "12345678"
#define WIFI_AUTH                       CYW43_AUTH_WPA2_AES_PSK

// Pins
#define DRAG_ENABLE_PIN     17
#define RIGHT_SPIN_PIN      18
#define LEFT_SPIN_PIN       19
#define BACKWARD_PIN        20
#define FORWARD_PIN         21
#define JOYSTICK_BTN_PIN    22
#define JOYSTICK_X_PIN      26
#define JOYSTICK_Y_PIN      27
#define SPEED_PIN           28


#endif

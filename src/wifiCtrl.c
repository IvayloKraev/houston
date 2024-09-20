#include "wifiCtrl.h"

void huston_wifiCtrl_init() {
    const char* ssid = "Huston";
    const char* password = "123456789";

    if (cyw43_arch_init() != PICO_OK) {
        stdio_printf("failed to initialise wifi\n");
        // return huston_ERR;
    }

    cyw43_arch_enable_ap_mode(ssid, password, CYW43_AUTH_WPA2_AES_PSK);

    stdio_printf("access point initialized\n");

    // return huston_OK;
}

void huston_wifiCtrl_deinit() {
    cyw43_arch_disable_ap_mode();
    cyw43_arch_deinit();
}

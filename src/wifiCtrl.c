#include "wifiCtrl.h"

_Noreturn void huston_wifiCtrl_init(void *paramsPtr) {
    wifiConfigHandler_t wifiConfig = (wifiConfigHandler_t) paramsPtr;

    if (cyw43_arch_init_with_country(CYW43_COUNTRY_BULGARIA)) {
        stdio_printf("failed to initialise wifi\n");
        vTaskDelete(NULL);
    }

    //TODO: Make Houston a access point (create a DHCP server)

    cyw43_arch_enable_sta_mode();
    stdio_printf("sta mode enabled\n");

    if (cyw43_arch_wifi_connect_blocking(wifiConfig->ssid, wifiConfig->password, CYW43_AUTH_WPA2_AES_PSK) != PICO_OK) {
        stdio_printf("failed to connect to ap\n");
        vTaskDelete(NULL);
    }

    const ip4_addr_t *ip = netif_ip4_addr(netif_default);
    if (ip != NULL) {
        printf("IP Address: %s\n", ip4addr_ntoa(ip));
    } else {
        printf("Failed to get IP address\n");
        vTaskDelete(NULL);
    }

    while (true) {
        cyw43_arch_poll();
        cyw43_arch_wait_for_work_until(make_timeout_time_ms(1000));
    }
}

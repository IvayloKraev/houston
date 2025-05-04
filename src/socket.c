#include "socket.h"

_Noreturn void houston_socket_pipeData(void *param) {
    const ip_addr_t *houstonIpAddr = netif_ip4_addr(netif_default);

    ip_addr_t *curiosityIpAddr = (ip_addr_t *) malloc(sizeof(ip_addr_t));
    IP4_ADDR(curiosityIpAddr, 192, 168, 1, 16);


    // Creating connection
    struct netconn *houstonUdpConnection = netconn_new(NETCONN_UDP);

    err_t netconnStatus = netconn_bind(houstonUdpConnection, houstonIpAddr, 784) +
                          netconn_connect(houstonUdpConnection, curiosityIpAddr, 784);

    if (netconnStatus != ERR_OK) {
        stdio_printf("netconn_bind/netconn_connect failed\n");
        vTaskDelete(NULL);
    }


    // Assigning value
    struct netbuf *houstonNetBuffer = netbuf_new();

    err_t netBufStatus = netbuf_ref(houstonNetBuffer, param, hcst_MESSAGE_SIZE_BYTES);

    if (netBufStatus != ERR_OK) {
        stdio_printf("netbuf_ref failed\n");
        vTaskDelete(NULL);
    }

    while (1) {
        err_t netconnSendStatus = netconn_send(houstonUdpConnection, houstonNetBuffer);

        if (netconnSendStatus != ERR_OK) {
            stdio_printf("netconn_send failed\n");
            vTaskDelete(NULL);
        }
    }
}

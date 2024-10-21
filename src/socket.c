#include "socket.h"

#include <lwip/api.h>

#define PRINT_BITS_8(num) do { \
for (int i = 7; i >= 0; i--) { \
stdio_printf("%d", (num >> i) & 1); \
} \
stdio_printf("\n"); \
} while(0)


_Noreturn void houston_socket_pipeData(void *param) {

    stdio_printf("Houston socket pipe data\n");
    HOUSTON_STATUS_WAIT_WIFI_DONE();
    stdio_printf("Houston_socket_pipeData()\n");

    uint32_t hoston_socket = lwip_socket(AF_INET, SOCK_DGRAM, 0);

    stdio_printf("socket %d\n", hoston_socket);

    struct netconn * xUdpConn = netconn_new ( NETCONN_UDP );

    stdio_printf("netconn %d\n", xUdpConn);

    struct netbuf  * xNetBuf = netbuf_new();

    stdio_printf("xNetBuf %d\n", xNetBuf);

    ip_addr_t ipAddr;
    IP4_ADDR(&ipAddr, 192, 168, 0, 114);

    uint8_t t = netconn_bind(xUdpConn, &ipAddr,784);

    stdio_printf("netconn bind %d\n", t);

    uint8_t u = netconn_connect(xUdpConn, IP_ADDR_BROADCAST, 784);

    stdio_printf("netconn connect %d\n", u);

    uint8_t m = netbuf_ref(xNetBuf, param, HCTP_MESSAGE_SIZE_BYTES);

    stdio_printf("m %d\n", m);

    while (1) {
        netconn_send(xUdpConn, xNetBuf);

        vTaskDelay(1000);
    }
}

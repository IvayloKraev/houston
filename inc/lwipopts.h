#ifndef LWIPOPTS_H
#define LWIPOPTS_H

/* ---------- System options ---------- */
#define NO_SYS                          0
#define SYS_LIGHTWEIGHT_PROT            1

/* ---------- Memory options ---------- */
#define MEM_ALIGNMENT                   4
#define MEM_SIZE                        1600

/* ---------- Pbuf options ---------- */
#define PBUF_POOL_SIZE                  8
#define PBUF_POOL_BUFSIZE               512

/* ---------- TCP options ---------- */
#define LWIP_TCP                        1
#define TCP_TTL                         255
#define TCP_QUEUE_OOSEQ                 0
#define TCP_MSS                         512
#define TCP_SND_BUF                     (2 * TCP_MSS)
#define TCP_WND                         (2 * TCP_MSS)

/* ---------- UDP options ---------- */
#define LWIP_UDP                        1
#define UDP_TTL                         255

/* ---------- ICMP options ---------- */
#define LWIP_ICMP                       1

/* ---------- DHCP options ---------- */
#define LWIP_DHCP                       1

/* ---------- DNS options ---------- */
#define LWIP_DNS                        1

/* ---------- Socket options ---------- */
#define LWIP_SOCKET                     1
#define LWIP_NETCONN                    1

/* ---------- Thread options ---------- */
#define TCPIP_THREAD_NAME               "TCP/IP"
#define TCPIP_THREAD_STACKSIZE          1024
#define TCPIP_THREAD_PRIO               (configMAX_PRIORITIES - 2)
#define DEFAULT_THREAD_STACKSIZE        512

/* ---------- Sequential layer options ---------- */
#define LWIP_NETCONN_SEM_PER_THREAD     1

/* ---------- Mailbox sizes ---------- */
#define TCPIP_MBOX_SIZE                 8
#define DEFAULT_UDP_RECVMBOX_SIZE       8
#define DEFAULT_TCP_RECVMBOX_SIZE       8
#define DEFAULT_ACCEPTMBOX_SIZE         8

/* ---------- Timeouts ---------- */
#define LWIP_SO_RCVTIMEO                1
#define LWIP_SO_SNDTIMEO                1
#define LWIP_TIMEVAL_PRIVATE            0

/* ---------- Network interface options ---------- */
#define LWIP_NETIF_STATUS_CALLBACK      1
#define LWIP_NETIF_LINK_CALLBACK        1

/* ---------- Checksum options ---------- */
#define LWIP_CHECKSUM_CTRL_PER_NETIF    0
#define CHECKSUM_BY_HARDWARE            0

#if CHECKSUM_BY_HARDWARE
#define CHECKSUM_GEN_IP                 0
#define CHECKSUM_GEN_UDP                0
#define CHECKSUM_GEN_TCP                0
#define CHECKSUM_CHECK_IP               0
#define CHECKSUM_CHECK_UDP              0
#define CHECKSUM_CHECK_TCP              0
#else
#define CHECKSUM_GEN_IP                 1
#define CHECKSUM_GEN_UDP                1
#define CHECKSUM_GEN_TCP                1
#define CHECKSUM_CHECK_IP               1
#define CHECKSUM_CHECK_UDP              1
#define CHECKSUM_CHECK_TCP              1
#endif

/* ---------- Statistics options ---------- */
#define LWIP_STATS                      0
#define LWIP_PROVIDE_ERRNO              1

/* ---------- Debugging options ---------- */
#define LWIP_DEBUG                      0

#endif

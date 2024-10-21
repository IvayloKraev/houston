cmake_minimum_required(VERSION 3.29)

set(PICO_BOARD pico_w)

include(lib/pico-sdk/pico_sdk_init.cmake)
include(lib/FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)
include(lib/hctp/CMakeLists.txt)

project(Houston LANGUAGES C CXX ASM)

pico_sdk_init()

set(CMAKE_C_STANDARD 11)

set(SOURCES
        src/wifiCtrl.c
        src/userInput.c
        src/encodeCommands.c
        src/socket.c
        src/status.c
)

add_executable(Houston main.c
        ${SOURCES})

include_directories(inc)

target_link_libraries(
        Houston
        pico_stdlib
        FreeRTOS-Kernel
        FreeRTOS-Kernel-Heap4
        pico_cyw43_arch_lwip_sys_freertos
        hardware_adc
        hardware_gpio
        hctp
)

pico_enable_stdio_usb(Houston 1)
pico_enable_stdio_uart(Houston 0)

pico_add_extra_outputs(Houston)

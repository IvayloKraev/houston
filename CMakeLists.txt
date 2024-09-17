cmake_minimum_required(VERSION 3.29)

set(PICO_BOARD pico_w)

include(lib/pico-sdk/pico_sdk_init.cmake)
include(lib/FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

project(Curiosity_Remote LANGUAGES C CXX ASM)

pico_sdk_init()

set(CMAKE_C_STANDARD 11)

add_executable(Curiosity_Remote main.c)

target_include_directories(Curiosity_Remote PRIVATE inc)

target_link_libraries(
        Curiosity_Remote
        pico_stdlib
        pico_cyw43_arch_lwip_sys_freertos
        FreeRTOS-Kernel-Heap4
)

pico_enable_stdio_usb(Curiosity_Remote 1)
pico_enable_stdio_uart(Curiosity_Remote 0)

pico_add_extra_outputs(Curiosity_Remote)

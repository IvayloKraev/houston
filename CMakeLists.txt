cmake_minimum_required(VERSION 3.29)

set(PICO_BOARD pico_w)

include(lib/pico-sdk/pico_sdk_init.cmake)
include(lib/FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)
include(lib/hcst/CMakeLists.txt)

project(houston LANGUAGES C CXX ASM)

pico_sdk_init()

set(CMAKE_C_STANDARD 11)

add_executable(
        houston
        main.c
        src/wifiCtrl.c
        src/userInput.c
        src/socket.c
)

include_directories(inc)

target_link_libraries(
        houston
        pico_stdlib
        FreeRTOS-Kernel
        FreeRTOS-Kernel-Heap4
        pico_cyw43_arch_lwip_sys_freertos
        hardware_adc
        hardware_gpio
        hcst
)

pico_enable_stdio_usb(houston 1)
pico_enable_stdio_uart(houston 0)
pico_add_extra_outputs(houston)

cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(pico-74hc165)

pico_sdk_init()

add_executable(${PROJECT_NAME} src/main.c)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_definitions(${PROJECT_NAME} PUBLIC
        -DPICO_DEFAULT_UART_TX_PIN=16
        -DPICO_DEFAULT_UART_RX_PIN=17
)
target_link_libraries(${PROJECT_NAME} PUBLIC
        pico_stdlib
        hardware_pio
        "-Wl,--print-memory-usage"
)

pico_generate_pio_header(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/74hc165.pio)
pico_generate_pio_header(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/74hc165-x2.pio)

pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})
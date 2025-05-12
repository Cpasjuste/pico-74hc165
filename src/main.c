//
// Created by cpasjuste on 31/03/25.
//

#include <stdio.h>
#include <pico/stdio.h>
//#include <pico/stdio_usb.h>
#include <pico/time.h>
#include "74hc165.pio.h"

#define DATA_PIN    2 // QH
#define CLK_PIN     3 // CLK
#define LATCH_PIN   4 // SH/LD

void print_bits(const uint8_t value) {
    printf("0x%02X: ", value);
    for (int i = 0; i < 8; i++) {
        printf("%d", (value >> i) & 1);
    }
    printf("\r\n");
}

int main() {
    stdio_init_all();

    // wait for usb debug
    //while (!stdio_usb_connected()) { sleep_ms(10); }

    printf("Hello 74hc165\r\n");

    hc165_t hc;
    hc165_program_init(&hc, DATA_PIN, CLK_PIN, LATCH_PIN, 10);

    while (1) {
        const uint8_t value = hc165_get(&hc);
        print_bits(value);
    }

    return 0;
}

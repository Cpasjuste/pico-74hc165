//
// 74HC165 - cpasjuste @ 2025
//

#include <stdio.h>
#include <pico/stdio.h>
//#include <pico/stdio_usb.h>
#include <pico/time.h>
#include "74hc165.pio.h"
#include "74hc165-x2.pio.h"

#define DATA_PIN    2 // QH
#define CLK_PIN     3 // CLK
#define LATCH_PIN   4 // SH/LD

void print_bits(const uint8_t value) {
    printf("0x%02X: ", value);
    for (int i = 0; i < 8; i++) {
        printf("%d", value >> i & 1);
    }
    printf("\r\n");
}

void print_bits_16(const uint16_t value) {
    printf("0x%04X: ", value);
    for (int i = 0; i < 16; i++) {
        printf("%d", value >> i & 1);
    }
    printf("\r\n");
}

int main() {
    stdio_init_all();

    // wait for usb debug
    //while (!stdio_usb_connected()) { sleep_ms(10); }

    printf("Hello 74hc165\r\n");

    // 1 chip
    //hc165_t hc;
    //hc165_program_init(&hc, DATA_PIN, CLK_PIN, LATCH_PIN, 10);

    // 2 chips
    hc165x2_t hc;
    hc165x2_program_init(&hc, DATA_PIN, CLK_PIN, LATCH_PIN, 10);

    while (1) {
        const uint16_t value = hc165x2_get(&hc);
        print_bits_16(value);
    }

    return 0;
}

#include <stdint.h>

#define HEX_DISPLAY_BASE ((volatile uint32_t *)0xFF200020)

// Segment encoding for digits 0-9
const unsigned char digit_map[10] = {
    0x3F,  // 0: 0011 1111 (0)
    0x06,  // 1: 0000 0110 (1)
    0x5B,  // 2: 0101 1011 (2)
    0x4F,  // 3: 0100 1111 (3)
    0x66,  // 4: 0110 0110 (4)
    0x6D,  // 5: 0110 1101 (5)
    0x7D,  // 6: 0111 1101 (6)
    0x07,  // 7: 0000 0111 (7)
    0x7F,  // 8: 0111 1111 (8)
    0x6F   // 9: 0110 1111 (9)
};

// Segment encoding for "Err"
const unsigned char error_map[4] = {
    0x79,  // E: 0111 1001
    0x50,  // r: 0101 0000
    0x50,  // r: 0101 0000
    0x00   // Blank
};

// Delay function to slow down counting
void delay() {
    volatile int i;
    for (i = 0; i < 1000; i++)
        ;
}

// Display a 4-digit number or "Err" if out of range
void show_number(int number) {
    unsigned char display[4];
    int i;

    // Check if the number is out of range
    if (number < 0 || number > 9999) {
        // Display "Err"
        *HEX_DISPLAY_BASE = (error_map[0] << 24) | (error_map[1] << 16) | (error_map[2] << 8) | error_map[3];
        return;
    }

    // Extract digits (right to left)
    for (i = 0; i < 4; i++) {
        int digit = number % 10;
        display[i] = digit_map[digit];
        number /= 10;
    }

    // Pack the digits into a single 32-bit value for the display
    uint32_t hex_value = (display[3] << 24) | (display[2] << 16) | (display[1] << 8) | display[0];
    *HEX_DISPLAY_BASE = hex_value;
}

// Main loop to count from 0 to 9999
int main() {
    int number = 0;

    while (1) {
        show_number(number);
        delay();

        number++;
        if (number > 11000) {
            number = 0;
        }
    }
}

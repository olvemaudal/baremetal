#include <stdint.h>

const uint8_t seven_seg_lookup[] = {
    /* Digits */
    ['0'] = 0b00111111, // 0: A, B, C, D, E, F
    ['1'] = 0b00000110, // 1: B, C
    ['2'] = 0b01011011, // 2: A, B, D, E, G
    ['3'] = 0b01001111, // 3: A, B, C, D, G
    ['4'] = 0b01100110, // 4: B, C, F, G
    ['5'] = 0b01101101, // 5: A, C, D, F, G
    ['6'] = 0b01111101, // 6: A, C, D, E, F, G
    ['7'] = 0b00000111, // 7: A, B, C
    ['8'] = 0b01111111, // 8: A, B, C, D, E, F, G
    ['9'] = 0b01101111, // 9: A, B, C, D, F, G
    
    /* Uppercase Letters */
    ['A'] = 0b01110111, // A: A, B, C, E, F, G
    ['B'] = 0b01111100, // B: C, D, E, F, G (lowercase b)
    ['C'] = 0b00111001, // C: A, D, E, F
    ['D'] = 0b01011110, // D: B, C, D, E, G (lowercase d)
    ['E'] = 0b01111001, // E: A, D, E, F, G
    ['F'] = 0b01110001, // F: A, E, F, G
    ['G'] = 0b00111101, // G: A, C, D, E, F
    ['H'] = 0b01110110, // H: B, C, E, F, G
    ['I'] = 0b00000110, // I: B, C (same as 1)
    ['J'] = 0b00011110, // J: B, C, D, E
    ['K'] = 0b01110110, // K: A, B, E, F, G (approximation)
    ['L'] = 0b00111000, // L: D, E, F
    ['M'] = 0b00110111, // M: B, C, E, F (approximation)
    ['N'] = 0b01010100, // N: B, C, E, F, G (approximation)
    ['O'] = 0b00111111, // O: A, B, C, D, E, F (same as 0)
    ['P'] = 0b01110011, // P: A, B, E, F, G
    ['Q'] = 0b01100111, // Q: A, B, C, F, G (approximation)
    ['R'] = 0b01010000, // R: E, G (approximation)
    ['S'] = 0b01101101, // S: A, C, D, F, G (same as 5)
    ['T'] = 0b01111000, // T: D, E, F, G (approximation)
    ['U'] = 0b00111110, // U: B, C, D, E, F
    ['V'] = 0b00111110, // V: B, C, D, E, F (same as U)
    ['W'] = 0b00101010, // W: B, D, F (approximation)
    ['X'] = 0b01110110, // X: B, C, E, F, G (same as H)
    ['Y'] = 0b01101110, // Y: B, C, D, F, G
    ['Z'] = 0b01011011, // Z: A, B, D, E, G (same as 2)
    
    /* Space and Other Characters */
    [' '] = 0b00000000, // Space: All segments off
    ['-'] = 0b01000000, // Dash: G
    ['_'] = 0b00001000, // Underscore: D
};

void write_led(int ledno, int ch)
{
    uint32_t * addr;
    int shift;
    switch (ledno) {
        case 0: addr = (uint32_t*)0xff200030; shift = 8; break;
        case 1: addr = (uint32_t*)0xff200030; shift = 0; break;
        case 2: addr = (uint32_t*)0xff200020; shift = 24; break;
        case 3: addr = (uint32_t*)0xff200020; shift = 16; break;
        case 4: addr = (uint32_t*)0xff200020; shift = 8; break;
        case 5: addr = (uint32_t*)0xff200020; shift = 0; break;
        default: return;
    }
    uint32_t memword = *addr;
    memword &= ~(0xff << shift);
    uint8_t mybyte = seven_seg_lookup[ch];
    memword |= (mybyte << shift);
    *addr = memword;
}

volatile int counter = 0;
void sleep(int delay) 
{
    while (delay) {
        counter++;
        delay--;
    }
}

void _start(void)
{
    char * msg = "HELLO WONDERFUL WORLD OF BARE METAL CODING         ";
    
    for (;;) {
        int offset = 0;
        for (int i=0; i < 42; i++) {
            for (int led = 0; led < 6; led++) 
                write_led(led, msg[offset + led]);
            sleep(1000000);
            offset++;
        }
    }
}

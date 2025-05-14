#include <stdint.h>
#include <stdio.h>

uint32_t * SWITCHES_BASE = (uint32_t*)0xff200040;
uint32_t * DISPLAY_BASE = (uint32_t*)0xff200020;

int main(void)
{
    uint32_t status = 0;
    uint32_t prev_status = 0;
    while (1) {
        status = *SWITCHES_BASE;
        *DISPLAY_BASE = status;
        if (status != prev_status) {
            printf("%08lx\n", status);
            prev_status = status;
        }		
    }
}

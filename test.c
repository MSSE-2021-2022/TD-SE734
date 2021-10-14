#include <stdint.h>
#include "init.h"
#include <stdio.h>
#include "led.h"

uint32_t fibo(uint32_t n) {
    uint32_t ret = 0;
    if (n<2) {
        return n;
    }
    else {
        return fibo(n-1) + fibo(n-2);
    }
}

int main(void) {
    uint32_t i=0;
    //fibo(8);
    led_init();

    while(1) {
        // vert - jaune - bleu - vert - jaune - bleu, etc.
        led_g_on();
        led_g_off();

        led(LED_YELLOW);
        led(LED_BLUE);
        led(LED_OFF);
    }
    return 0;
}
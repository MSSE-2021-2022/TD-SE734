#include <stdint.h>
#include "led.h"

int main(void) {
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

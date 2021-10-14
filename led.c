#include "led.h"

void Enable_GPIO_Clock(uint8_t port) {
    RCC_AHB2_ENR |= (1<<port);
}

void Disable_GPIO_Clock(uint8_t port) {
    RCC_AHB2_ENR &= (~(1<<port));
}

void pinMode(uint8_t reg, uint8_t pin, uint8_t mode) {
    if (mode == INPUT) {
        GPIO_MODE(reg) &= ~(3<<(pin*2));
    }
    else {
        GPIO_MODE(reg) |= (1<<(pin*2));
        GPIO_MODE(reg) &= ~(1<<(pin*2+1));
        GPIO_OTYPER(reg) &= ~(1<<pin);
    }
}

void digitalWrite(uint8_t reg, uint8_t pin, uint8_t mode) {
    // Reset en poid fort, Set en poid faible, mettre à 0 quand l'autre est a 1
    uint32_t valeur_registre = GPIO_SET(reg);
    if (mode == HIGH) {
        valeur_registre &= ~(1<<(pin+16));
        valeur_registre |= (1<<pin);
    }
    else {
        valeur_registre &= ~(1<<(pin));
        valeur_registre |= (1<<(pin+16));
    }
    GPIO_SET(reg) = valeur_registre;
}

void led_init(void) {
/*
    active l'horloge du port B dans le registre RCC_*ENR* idoine,
    configure la broche PB14 en mode sortie.
*/
    Enable_GPIO_Clock(PORTB);
    pinMode(PORTB, 14, OUTPUT);
}

void led_g_on(void) {
    digitalWrite(PORTB, 14, HIGH);
    GPIO_B_BSSR = 0x4000;
}

void led_g_off(void) {
    //digitalWrite(PORTB, 14, LOW);
    GPIO_B_BSSR = 0x40000000;
}

/*
void led_g_on(void) {
    GPIO_B_BSSR = 0x4000;
}

void led_g_off(void) {
    GPIO_B_BSSR = 0x4000000;
}
*/
#ifndef LED_H
#define LED_H

#include <stdint.h>

#define RCC_BASE        0x40021000
#define RCC_AHB2_ENR    (*((volatile uint32_t *) (RCC_BASE+0x4C)))

#define GPIO_B_BASE     0x48000400
#define GPIO_B_MODE     (*((volatile uint32_t *) (GPIO_B_BASE)))
#define GPIO_B_BSSR     (*((volatile uint32_t *) (GPIO_B_BASE+0x18)))

#define GPIO_BASE   0x48000000
#define GPIO_MODE(x) (*((volatile uint32_t *) (GPIO_BASE+0x400*(x))))
#define GPIO_OTYPER(x) (*((volatile uint32_t *) (GPIO_BASE+0x04+0x400*(x))))
#define GPIO_SET(x) (*((volatile uint32_t *) (GPIO_BASE+0x18+(0x400*(x)))))

#define INPUT 00
#define OUTPUT 01
#define HIGH 1
#define LOW 0
#define PORTB 1

void Enable_GPIO_Clock(uint8_t port);
void Disable_GPIO_Clock(uint8_t port);
void pinMode(uint8_t reg, uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t reg, uint8_t pin, uint8_t mode);

/*  INIT : active le périphérique GPIO : p251 
    Active la pin PORTB.14 en sortie : p303 + p81 datasheet
*/
void led_init(void);

/*  TOOGLE : registres de sorties p306
*/
void led_g_on(void);
void led_g_off(void);

#endif
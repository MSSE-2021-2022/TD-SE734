#include <stdint.h>
#include "led.h"
#include "stm32l475xx.h"

/*#define RCC_BASE 0x40021000
#define RCC_AHB2ENR *((volatile uint32_t*)(RCC_BASE+0x4C))

#define GPIOB_BASE 0x48000400 
#define GPIOC_BASE 0x48000800 
#define GPIOB_MODER *((volatile uint32_t*)(GPIOB_BASE+0x00))
#define GPIOC_MODER *((volatile uint32_t*)(GPIOC_BASE+0x00))
#define GPIOB_ODR   *((volatile uint32_t*)(GPIOB_BASE+0x14))
#define GPIOC_BSRR   *((volatile uint32_t*)(GPIOC_BASE+0x18))*/




void led(enum state state)
{
   if(state ==0)
   {
    GPIOC->MODER &= ~ GPIO_MODER_MODE9;//GPIOC_MODER =(GPIOC_MODER & ~(0x3<<18U)); //PC9 est en entrée (= haute impédance), les deux LED sont éteintes.
    
   }
   else if (state == 1)
   {

     GPIOC->MODER |= GPIO_MODER_MODE9_0; //GPIOC_MODER =(GPIOC_MODER & ~(0x3<<18U))| (0x1<<18U);
    GPIOC->BRR |= GPIO_BRR_BR_9; // GPIOC_BSRR  =(GPIOC_BSRR  & ~(0x1<<9U))| (0x1<<9U);  //PC9 est en sortie à l'état haut, LED3 est allumée, LED4 est éteinte.
   }
   else
   {
     GPIOC->MODER |= GPIO_MODER_MODE9_0;// GPIOC_MODER =(GPIOC_MODER & ~(0x3<<18U))| (0x1<<18U);
     GPIOC->BSRR |= GPIO_BSRR_BR_9; //GPIOC_BSRR  =(GPIOC_BSRR  & ~(0x1<<9U))| (0x1<<25U);  //PC9 est en sortie à l'état bas, LED3 est éteinte, LED4 est allumée.
   }
}

void led_init()
{
   //activation du clock du GPIOB et GPIOC
   
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOCEN;//RCC_AHB2ENR =(RCC_AHB2ENR & ~(0x1<<1U))| (0x1<<1U);  //IO port B clock enabled
                                                            //RCC_AHB2ENR =(RCC_AHB2ENR & ~(0x1<<2U))| (0x1<<2U);  //IO port C clock enabled
   //PB14 en mode sortie
   GPIOB->MODER =0;//init MODER
   GPIOB->MODER |= GPIO_MODER_MODE14_0;//GPIOB_MODER =(GPIOB_MODER & ~(0x3<<28U))| (0x1<<28U);
   
}
void led_g_on()
{
  GPIOB->ODR |= GPIO_ODR_OD14;//GPIOB_ODR  =(GPIOB_ODR & ~(0x1<<14U))| (0x1<<14U);//PB14 is on
}
void led_g_off()
{
   GPIOB->ODR &= ~GPIO_ODR_OD14;//GPIOB_ODR  =(GPIOB_ODR & ~(0x1<<14U));//PB14 is off
}
#include <stdint.h>
#include "stm32f103.h"
#include "gpio.h"
// #define RCC_APB2ENR (*((volatile uint32_t *)0x40021018)) // Dia chi cua RCC la 0x40021000 + them offset cua APB2 se la 0x18
// #define GPIOC_CRH (*((volatile uint32_t *)0x40011004))   // Dia chi cua GPIOC la 0x40011000 + them offset cua CRH se la 0x04
// #define GPIOC_ODR (*((volatile uint32_t *)0x4001100C))   // Dia chi cua GPIOC la 0x40011000 + them offset cua ODR se la 0x0C
// #define GPIOA_CRL (*((volatile uint32_t *)0x40010800))
// #define GPIOA_ODR (*((volatile uint32_t *)0x4001080C))

void delay(volatile uint32_t count)
{
    while (count--)
    {
    }
}
int main(void)
{
    GPIO_EnableClock(GPIOA);
    GPIO_SetPin(GPIOA, 3, GPIO_MODE_OUTPUT_PULL_2MHZ);
    while (1)
    {
        GPIO_Toggle(GPIOA, 3);
        delay(500000);
    }
    return 0;
}
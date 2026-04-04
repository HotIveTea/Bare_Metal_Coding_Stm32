#ifndef stm32f103_h
#define stm32f103_h
#include <stdint.h>
// Dia chi goc
#define PERIPH_BASE 0x40000000UL
#define APB2PERIPH_BASE (PERIPH_BASE + 0x10000UL)
#define APB1PERIPH_BASE (PERIPH_BASE)
#define AHBPERIPH_BASE (PERIPH_BASE + 0x20000UL)

#define RCC_PERIPH_BASE (AHBPERIPH_BASE + 0x1000UL)

// Dia chi goc cua cac GPIO
#define GPIOG_PERIPH_BASE (APB2PERIPH_BASE + 0x2000UL)
#define GPIOF_PERIPH_BASE (APB2PERIPH_BASE + 0x1C00UL)
#define GPIOE_PERIPH_BASE (APB2PERIPH_BASE + 0x1800UL)
#define GPIOD_PERIPH_BASE (APB2PERIPH_BASE + 0x1400UL)
#define GPIOC_PERIPH_BASE (APB2PERIPH_BASE + 0x1000UL)
#define GPIOB_PERIPH_BASE (APB2PERIPH_BASE + 0x0C00UL)
#define GPIOA_PERIPH_BASE (APB2PERIPH_BASE + 0x0800UL)
// Dia chi goc cua cac USART
#define USART1_PERIPH_BASE (APB2PERIPH_BASE + 0x3800UL)
#define USART2_PERIPH_BASE (APB1PERIPH_BASE + 0x4400UL)
#define USART3_PERIPH_BASE (APB1PERIPH_BASE + 0x4800UL)
#define UART4_PERIPH_BASE (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_PERIPH_BASE (APB1PERIPH_BASE + 0x5000UL)

typedef struct
{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t RCC_APB2RSTR;
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_AHBENR;
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;
    volatile uint32_t RCC_AHBRSTR;
    volatile uint32_t RCC_CFGR2;
} RCC_TypeDef;

typedef struct
{
    volatile uint32_t GPIOx_CRL;
    volatile uint32_t GPIOx_CRH;
    volatile uint32_t GPIOx_IDR;
    volatile uint32_t GPIOx_ODR;
    volatile uint32_t GPIOx_BSRR;
    volatile uint32_t GPIOx_BRR;
    volatile uint32_t GPIOx_LCKR;
} GPIO_TypeDef;

typedef struct
{
    volatile uint32_t USARTx_SR;
    volatile uint32_t USARTx_DR;
    volatile uint32_t USARTx_BRR;
    volatile uint32_t USARTx_CR1;
    volatile uint32_t USARTx_CR2;
    volatile uint32_t USARTx_CR3;
    volatile uint32_t USARTx_GTPR;
} USART_TypeDef;

#define RCC ((RCC_TypeDef *)RCC_PERIPH_BASE)

#define GPIOA ((GPIO_TypeDef *)GPIOA_PERIPH_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_PERIPH_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_PERIPH_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_PERIPH_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_PERIPH_BASE)
#define GPIOF ((GPIO_TypeDef *)GPIOF_PERIPH_BASE)
#define GPIOG ((GPIO_TypeDef *)GPIOG_PERIPH_BASE)

#define USART1 ((USART_TypeDef *)USART1_PERIPH_BASE);
#define USART2 ((USART_TypeDef *)USART2_PERIPH_BASE);
#define USART3 ((USART_TypeDef *)USART3_PERIPH_BASE);
#define UART4 ((USART_TypeDef *)UART4_PERIPH_BASE);
#define UART5 ((USART_TypeDef *)UART5_PERIPH_BASE);

#endif
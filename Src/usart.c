#include "usart.h"
#include "gpio.h"
void USART_Init(USART_TypeDef *USARTx, uint32_t APB_Clock, uint32_t baudrate)
{
    RCC->RCC_APB2ENR |= (1 << 0);
    switch ((uint32_t)USARTx)
    {
    case USART1_PERIPH_BASE:
        RCC->RCC_APB2ENR |= (1 << 14);
        RCC->RCC_APB2ENR |= (1 << 2);
        GPIO_SetPin(GPIOA, 9, GPIO_MODE_AF_PUSH_PULL_50MHZ);
        GPIO_SetPin(GPIOA, 10, GPIO_MODE_INPUT_FLOATING);
        break;
    case USART2_PERIPH_BASE:
        RCC->RCC_APB1ENR |= (1 << 17);
        RCC->RCC_APB2ENR |= (1 << 2);
        GPIO_SetPin(GPIOA, 2, GPIO_MODE_AF_PUSH_PULL_50MHZ);
        GPIO_SetPin(GPIOA, 3, GPIO_MODE_INPUT_FLOATING);
        break;
    case USART3_PERIPH_BASE:
        RCC->RCC_APB1ENR |= (1 << 18);
        RCC->RCC_APB2ENR |= (1 << 3);
        GPIO_SetPin(GPIOB, 10, GPIO_MODE_AF_PUSH_PULL_50MHZ);
        GPIO_SetPin(GPIOB, 11, GPIO_MODE_INPUT_FLOATING);
        break;
    case UART4_PERIPH_BASE:
        RCC->RCC_APB1ENR |= (1 << 19);
        RCC->RCC_APB2ENR |= (1 << 4);
        GPIO_SetPin(GPIOC, 10, GPIO_MODE_AF_PUSH_PULL_50MHZ);
        GPIO_SetPin(GPIOC, 11, GPIO_MODE_INPUT_FLOATING);
        break;
    case UART5_PERIPH_BASE:
        RCC->RCC_APB1ENR |= (1 << 20);
        RCC->RCC_APB2ENR |= (1 << 5);
        RCC->RCC_APB2ENR |= (1 << 4);
        GPIO_SetPin(GPIOC, 12, GPIO_MODE_AF_PUSH_PULL_50MHZ);
        GPIO_SetPin(GPIOD, 2, GPIO_MODE_INPUT_FLOATING);
        break;
    default:
        break;
    }
    USARTx->USARTx_BRR = (APB_Clock + (baudrate / 2)) / baudrate;
    USARTx->USARTx_CR1 |= (1 << 2) | (1 << 3) | (1 << 13);
}
void USART_SendChar(USART_TypeDef *USARTx, char ch)
{
    while (!(USARTx->USARTx_SR & (1 << 7)))
    {
    }
    USARTx->USARTx_DR = (ch & 0xFF);
}
char USART_Received(USART_TypeDef *USARTx)
{
    while (!(USARTx->USARTx_SR & (1 << 5)))
    {
    }
    return (char)(USARTx->USARTx_DR & 0xFF);
}
void USART_SendString(USART_TypeDef *USARTx, char *str)
{
    while (*str)
    {
        USART_SendChar(USARTx, *str++);
    }
}
#include "usart.h"

void USART_Init(USART_TypeDef *USARTx)
{
    USARTx->USARTx_CR1 |= (1 << 2) | (1 << 3) | (1 << 13);
}
void USART_SetBaudRate(USART_TypeDef *USARTx, uint32_t baudrate)
{
    USARTx->USARTx_BRR = baudrate;
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
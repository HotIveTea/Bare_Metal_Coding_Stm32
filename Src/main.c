#include <stdint.h>
#include <string.h>
#include "stm32f103.h"
#include "gpio.h"
#include "os.h"
#include "timer.h"
#include "usart.h"
#define STACK_SIZE 100
uint32_t idle_stack[STACK_SIZE];
uint32_t task1_stack[STACK_SIZE];
uint32_t task2_stack[STACK_SIZE];
uint32_t task3_stack[STACK_SIZE];
TCB_t tcbidle, tcb1, tcb2, tcb3;
extern TCB_t volatile *current_task;
extern TCB_t volatile *next_task;
void Idle_Task(void)
{
    while (1)
    {
        __asm volatile("WFI \n");
    }
}
void Task1(void)
{
    while (1)
    {
        GPIO_Toggle(GPIOA, 1);
        OS_Delay(5000);
    }
}
void Task2(void)
{
    while (1)
    {
        GPIO_Toggle(GPIOA, 2);
        OS_Delay(1000);
    }
}
void Task3(void)
{
    while (1)
    {
        GPIO_Toggle(GPIOA, 3);
        OS_Delay(2000);
    }
}
int main(void)
{
    GPIO_EnableClock(GPIOA);
    GPIO_EnableClock(GPIOC);
    // GPIO_SetPin(GPIOA, 1, GPIO_MODE_OUTPUT_PULL_2MHZ);
    // GPIO_SetPin(GPIOA, 2, GPIO_MODE_OUTPUT_PULL_2MHZ);
    // GPIO_SetPin(GPIOA, 3, GPIO_MODE_OUTPUT_PULL_2MHZ);
    // OS_TaskCreate(&tcbidle, Idle_Task, idle_stack, STACK_SIZE);
    // OS_AddThread(&tcbidle);
    // OS_TaskCreate(&tcb1, Task1, task1_stack, STACK_SIZE);
    // OS_TaskCreate(&tcb2, Task2, task2_stack, STACK_SIZE);
    // OS_TaskCreate(&tcb3, Task3, task3_stack, STACK_SIZE);
    // OS_AddThread(&tcb1);
    // OS_AddThread(&tcb2);
    // OS_AddThread(&tcb3);
    // OS_Start();
    GPIO_SetPin(GPIOC, 13, GPIO_MODE_OUTPUT_PULL_50MHZ);
    GPIO_SetPin(GPIOA, 9, GPIO_MODE_AF_PUSH_PULL_50MHZ);
    GPIO_SetPin(GPIOA, 10, GPIO_MODE_INPUT_FLOATING);
    GPIO_WritePin(GPIOC, 13, 1);
    USART_Init(USART1, 8000000, 115200);
    USART_SendString(USART1, "\r\n=== STM32 BLUETOOTH READY ===\r\n");
    USART_SendString(USART1, "Gui phim 'tat' de TAT den.\r\n");
    USART_SendString(USART1, "Gui phim 'bat' de BAT den.\r\n");
    char cmd_buffer[16];
    while (1)
    {
        USART_Recieved_String(USART1, cmd_buffer, 16);
        if (strcmp(cmd_buffer, "bat") == 0)
        {
            GPIOC->BRR = (1 << 13);
        }
        else if (strcmp(cmd_buffer, "tat") == 0)
        {
            GPIOC->BSRR = (1 << 13);
        }
    }
    // while (1)
    // {
    //     for (uint16_t i = 0; i <= 1000; i++)
    //     {
    //         TIM_PWM_SetDuty(TIM2, 3, i);
    //         TIM_DelayMs(TIM2, 2);
    //     }
    //     TIM_DelayMs(TIM2, 200);
    //     for (int16_t i = 1000; i >= 0; i--)
    //     {
    //         TIM_PWM_SetDuty(TIM2, 3, i);
    //         TIM_DelayMs(TIM2, 2);
    //     }
    //     TIM_DelayMs(TIM2, 500);
    // }

    return 0;
}
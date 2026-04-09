#include <stdint.h>
#include "stm32f103.h"
#include "gpio.h"
#include "os.h"
#define STACK_SIZE 100
uint32_t task1_stack[STACK_SIZE];
uint32_t task2_stack[STACK_SIZE];

TCB_t tcb1;
TCB_t tcb2;
TCB_t tcb3;
extern TCB_t volatile *current_task;
extern TCB_t volatile *next_task;
void delay(volatile uint32_t count)
{
    while (count--)
    {
    }
}
void Task1(void)
{
    while (1)
    {
        GPIO_Toggle(GPIOA, 2);
        delay(5000000);
    }
}
void Task2(void)
{
    while (1)
    {
        GPIO_Toggle(GPIOA, 3);
        delay(500000);
    }
}

int main(void)
{
    GPIO_EnableClock(GPIOA);
    GPIO_SetPin(GPIOA, 4, GPIO_MODE_INPUT_PULLUD);
    GPIO_SetPin(GPIOA, 3, GPIO_MODE_OUTPUT_PULL_2MHZ);
    GPIO_SetPin(GPIOA, 2, GPIO_MODE_OUTPUT_PULL_2MHZ);
    OS_TaskCreate(&tcb1, Task1, task1_stack, STACK_SIZE);
    OS_TaskCreate(&tcb2, Task2, task2_stack, STACK_SIZE);
    current_task = &tcb1;
    next_task = &tcb2;
    OS_Start();
    return 0;
}
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
void Generic_Blink_Task(void *arg)
{
    int pin_number = (int)arg;
    while (1)
    {
        GPIO_Toggle(GPIOA, pin_number);
        OS_Delay(1000);
    }
}

int main(void)
{
    GPIO_EnableClock(GPIOA);
    GPIO_EnableClock(GPIOC);
    GPIO_SetPin(GPIOA, 1, GPIO_MODE_OUTPUT_PULL_2MHZ);
    GPIO_SetPin(GPIOA, 2, GPIO_MODE_OUTPUT_PULL_2MHZ);
    GPIO_SetPin(GPIOC, 13, GPIO_MODE_OUTPUT_PULL_2MHZ);
    OS_TaskCreate(&tcbidle, Idle_Task, NULL, idle_stack, STACK_SIZE);
    OS_AddThread(&tcbidle);
    OS_TaskCreate(&tcb1, Generic_Blink_Task, (void *)1, task1_stack, STACK_SIZE);
    OS_AddThread(&tcb1);
    OS_TaskCreate(&tcb2, Generic_Blink_Task, (void *)2, task2_stack, STACK_SIZE);
    OS_AddThread(&tcb2);
    OS_Start();
    return 0;
}
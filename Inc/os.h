#ifndef OS_H
#define OS_H
#include <stdint.h>
typedef struct
{
    uint32_t *sp; // Stack pointer of current task
} TCB_t;
void OS_TaskCreate(TCB_t *tcb, void (*task_func)(void), uint32_t *stack_base, uint32_t stack_size);
void OS_InitSysTick(uint32_t ticks);
void Systick_Handler(void);
__attribute__((naked)) void PendSV_Handler(void);
__attribute__((naked)) void SVCall_Handler(void);
void OS_Start(void);
#endif
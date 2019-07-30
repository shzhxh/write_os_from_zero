#include <stdint.h>
#include "encoding.h"
#include "clint.h"
#include "uarths.h"
#include "stdio.h"

# define TICK_NUM 100

extern volatile uint64_t ticks;        // tick counter
extern volatile uint64_t tick_cycles;

uintptr_t trap(uint64_t mcause, uint64_t epc, uint64_t *sp){
    uint64_t cause = (mcause<<1) >> 1;
    // printnum(mcause);    // szx debug
    // uarths_puts(" xxx ");// szx debug
    // printnum(cause);     // szx debug
    uint64_t core_id = current_coreid();

    /* handle interrupt */
    if((int64_t)mcause < 0){
        switch(cause){
            case IRQ_M_SOFT:
                if(++ticks % 1000000 == 0) uarths_puts("a0");   // szx debug
                break;
            case IRQ_M_TIMER:
                clint->mtimecmp[core_id] += tick_cycles;
                if(++ticks % TICK_NUM == 0) uarths_puts("ticks\n"); 
                break;
            case IRQ_M_EXT:
                if(++ticks % 1000000 == 0) uarths_puts("a1");   // szx debug
                break;
            default:
                if(++ticks % 1000000 == 0) uarths_puts("a");   // szx debug
                break;
        }
    }
    /* handle exception */
    else {
        switch(cause){
            case CAUSE_MISALIGNED_FETCH:
                if(++ticks % 1000000 == 0) uarths_puts("0");   // szx debug
                break;
            case CAUSE_FAULT_FETCH:
                if(++ticks % 1000000 == 0) uarths_puts("1");   // szx debug
                break;
            case CAUSE_ILLEGAL_INSTRUCTION:
                if(++ticks % 1000000 == 0) uarths_puts("2");   // szx debug
                break;
            case CAUSE_BREAKPOINT:
                if(++ticks % 1000000 == 0) uarths_puts("3");   // szx debug
                break;

            case CAUSE_MISALIGNED_LOAD:
                if(++ticks % 1000000 == 0) uarths_puts("4");   // szx debug
                break;
            case CAUSE_FAULT_LOAD:
                if(++ticks % 1000000 == 0) uarths_puts("5");   // szx debug
                break;
            case CAUSE_MISALIGNED_STORE:
                if(++ticks % 1000000 == 0) uarths_puts("6");   // szx debug
                break;
            case CAUSE_FAULT_STORE:
                if(++ticks % 1000000 == 0) uarths_puts("7");   // szx debug
                break;

            case CAUSE_USER_ECALL:
                if(++ticks % 1000000 == 0) uarths_puts("8");   // szx debug
                break;
            case CAUSE_SUPERVISOR_ECALL:
                if(++ticks % 1000000 == 0) uarths_puts("9");   // szx debug
                break;
            case CAUSE_HYPERVISOR_ECALL:
                if(++ticks % 1000000 == 0) uarths_puts("10 ");   // szx debug
                break;
            case CAUSE_MACHINE_ECALL:
                if(++ticks % 1000000 == 0) uarths_puts("11 ");   // szx debug
                break;
            default:
                if(++ticks % 1000000 == 0) uarths_puts("b");   // szx debug
                break;
        }
    }

    return epc;
}

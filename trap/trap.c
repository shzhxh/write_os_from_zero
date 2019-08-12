#include <stdint.h>
#include "encoding.h"
#include "clint.h"
#include "uarths.h"
#include "stdio.h"

# define TICK_NUM 1

extern volatile uint64_t ticks;        // tick counter
extern volatile uint64_t tick_cycles;

uintptr_t trap(uint64_t mcause, uint64_t epc, uint64_t *sp){
    uint64_t cause = (mcause<<1) >> 1;
    uint64_t core_id = current_coreid();

    /* handle interrupt */
    if((int64_t)mcause < 0){
        switch(cause){
            case IRQ_M_SOFT:
                uarths_puts("irq_soft\n");
                break;
            case IRQ_M_TIMER:
                clint->mtimecmp[core_id] += tick_cycles;
                if(++ticks % TICK_NUM == 0) uarths_puts("ticks\n"); 
                break;
            case IRQ_M_EXT:
                uarths_puts("irq_ext\n");
                break;
            default:
                uarths_puts("irq_unknown\n");
                break;
        }
    }
    /* handle exception */
    else {
        switch(cause){
            case CAUSE_MISALIGNED_FETCH:
                uarths_puts("exp_0\n");
                break;
            case CAUSE_FAULT_FETCH:
                uarths_puts("exp_1\n");
                break;
            case CAUSE_ILLEGAL_INSTRUCTION:
                uarths_puts("exp_2\n");
                break;
            case CAUSE_BREAKPOINT:
                uarths_puts("exp_3\n");
                break;

            case CAUSE_MISALIGNED_LOAD:
                uarths_puts("exp_4\n");
                break;
            case CAUSE_FAULT_LOAD:
                uarths_puts("exp_5\n");
                break;
            case CAUSE_MISALIGNED_STORE:
                uarths_puts("exp_6\n");
                break;
            case CAUSE_FAULT_STORE:
                uarths_puts("exp_7\n");
                break;

            case CAUSE_USER_ECALL:
                uarths_puts("exp_8\n");
                break;
            case CAUSE_SUPERVISOR_ECALL:
                uarths_puts("exp_9\n");
                break;
            case CAUSE_HYPERVISOR_ECALL:
                uarths_puts("exp_10\n");
                break;
            case CAUSE_MACHINE_ECALL:
                uarths_puts("exp_11\n");
                break;
            default:
                uarths_puts("exp_unknown\n");
                break;
        }
    }

    return epc;
}

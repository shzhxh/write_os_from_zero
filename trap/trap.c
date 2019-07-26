#include <stdint.h>
#include "encoding.h"
#include "clint.h"
#include "uarths.h"

# define TICK_NUM 1000000

extern volatile uint64_t ticks;        // tick counter
extern volatile uint64_t tick_cycles;

uintptr_t trap(uintptr_t mcause, uintptr_t epc, uintptr_t *sp){
    intptr_t cause = mcause;
    (cause << 1) >> 1;
    uint64_t core_id = current_coreid();

    if(++ticks % TICK_NUM == 0) uarths_puts("a");   // szx debug
    /* handle interrupt */
    if(mcause < 0){
        switch(cause){
            case IRQ_M_SOFT:
                break;
            case IRQ_M_TIMER:
                clint->mtimecmp[core_id] += tick_cycles;
                uarths_puts("szx: intr happens\n"); // szx debug 
                if(++ticks % TICK_NUM == 0) uarths_puts("ticks\n"); 
                break;
            case IRQ_M_EXT:
                break;
            default:
                break;
        }
    }
    /* handle exception */
    else {
        switch(cause){
            case CAUSE_MISALIGNED_FETCH:
                break;
            case CAUSE_FAULT_FETCH:
                break;
            case CAUSE_ILLEGAL_INSTRUCTION:
                break;
            case CAUSE_BREAKPOINT:
                break;

            case CAUSE_MISALIGNED_LOAD:
                break;
            case CAUSE_FAULT_LOAD:
                break;
            case CAUSE_MISALIGNED_STORE:
                break;
            case CAUSE_FAULT_STORE:
                break;

            case CAUSE_USER_ECALL:
                break;
            case CAUSE_SUPERVISOR_ECALL:
                break;
            case CAUSE_HYPERVISOR_ECALL:
                break;
            case CAUSE_MACHINE_ECALL:
                break;
            default:
                break;
        }
    }

    return epc;
}

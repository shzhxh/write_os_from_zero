#include "encoding.h"

uintptr_t trap(uintptr_t mcause, uintptr_t epc, uintptr_t *sp){
    intptr_t cause = (mcause << 1) >> 1;
    
    /* handle interrupt */
    if(mcause < 0){
        switch(cause){
            case IRQ_M_SOFT:
                break;
            case IRQ_M_TIMER:
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

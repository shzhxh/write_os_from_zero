#include "clint.h"
#include "encoding.h"

volatile uint64_t ticks;        // tick counter
volatile uint64_t tick_cycles;

volatile clint_t* const clint = (volatile clint_t*)0x02000000U;

int clint_timer_init(void){
    unsigned long core_id = current_coreid();
    ticks = 0;
    /* k210 cpu freq: 400MHz, tick per sec : 100 */
    tick_cycles = 390000000/10 - 1;

    clint->mtimecmp[core_id] = clint->mtime + tick_cycles;

    set_csr(mie, MIP_MTIP);
    set_csr(mstatus, MSTATUS_MIE);

    return 0;
}

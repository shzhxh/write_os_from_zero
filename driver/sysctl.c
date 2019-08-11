#include "sysctl.h"

#define SYSCTRL_CLOCK_FREQ_IN0 (26000000UL)

volatile sysctl_t *const sysctl = (volatile sysctl_t *)0x50440000U;

uint32_t sysctl_pll_get_freq(sysctl_pll_t pll){
    uint32_t freq_in = 0, freq_out = 0;
    uint32_t nr = 0, nf = 0, od = 0;
    uint8_t select = 0;

    switch(pll){
        case SYSCTL_PLL0:
            freq_in = SYSCTRL_CLOCK_FREQ_IN0;
            nr = sysctl->pll0.clkr0 + 1;
            nf = sysctl->pll0.clkf0 + 1;
            od = sysctl->pll0.clkod0 + 1;
            break;
        case SYSCTL_PLL1:
            freq_in = SYSCTRL_CLOCK_FREQ_IN0;
            nr = sysctl->pll1.clkr1 + 1;
            nf = sysctl->pll1.clkf1 + 1;
            od = sysctl->pll1.clkod1 + 1;
            break;
        case SYSCTL_PLL2:
            select = sysctl->pll2.pll_ckin_sel2;
            if(select==0) freq_in = SYSCTRL_CLOCK_FREQ_IN0;
            if(select==1) freq_in = sysctl_pll_get_freq(SYSCTL_PLL0);
            if(select==2) freq_in = sysctl_pll_get_freq(SYSCTL_PLL1);
            if(select>2) return 0;
            nr = sysctl->pll0.clkr0 + 1;
            nf = sysctl->pll0.clkf0 + 1;
            od = sysctl->pll0.clkod0 + 1;
            break;
        default:
            return 0;
    }

    freq_out = (double)freq_in / (double)nr * (double)nf / (double)od;
    return freq_out;
}

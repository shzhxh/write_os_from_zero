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

uint32_t sysctl_clock_get_freq(sysctl_clock_t clock){
    uint32_t source=0, result=0;

    switch(clock){
        case SYSCTL_CLOCK_IN0:
            source = SYSCTRL_CLOCK_FREQ_IN0;
            result = source;
            break;
        case SYSCTL_CLOCK_PLL0:
            source = sysctl_pll_get_freq(SYSCTL_CLOCK_PLL0);
            result = source;
            break;
        case SYSCTL_CLOCK_PLL1:
            source = sysctl_pll_get_freq(SYSCTL_CLOCK_PLL1);
            result = source;
            break;
        case SYSCTL_CLOCK_PLL2:
            source = sysctl_pll_get_freq(SYSCTL_CLOCK_PLL2);
            result = source;
            break;
        case SYSCTL_CLOCK_CPU:
            if(sysctl->clk_sel0.aclk_sel){
                source = sysctl_pll_get_freq(SYSCTL_PLL0) /
                    (2ULL << sysctl->clk_sel0.aclk_divider_sel);
            }
            else{
                source = SYSCTRL_CLOCK_FREQ_IN0;
            }
            result = source;
            break;
		case SYSCTL_CLOCK_SRAM0:
		case SYSCTL_CLOCK_SRAM1:
		case SYSCTL_CLOCK_APB0:
		case SYSCTL_CLOCK_APB1:
		case SYSCTL_CLOCK_APB2:
		case SYSCTL_CLOCK_ROM:
		case SYSCTL_CLOCK_DMA:
		case SYSCTL_CLOCK_AI:
		case SYSCTL_CLOCK_DVP:
		case SYSCTL_CLOCK_FFT:
		case SYSCTL_CLOCK_GPIO:
		case SYSCTL_CLOCK_SPI0:
		case SYSCTL_CLOCK_SPI1:
		case SYSCTL_CLOCK_SPI2:
		case SYSCTL_CLOCK_SPI3:
		case SYSCTL_CLOCK_I2S0:
		case SYSCTL_CLOCK_I2S1:
		case SYSCTL_CLOCK_I2S2:
		case SYSCTL_CLOCK_I2C0:
		case SYSCTL_CLOCK_I2C1:
		case SYSCTL_CLOCK_I2C2:
		case SYSCTL_CLOCK_UART1:
		case SYSCTL_CLOCK_UART2:
		case SYSCTL_CLOCK_UART3:
		case SYSCTL_CLOCK_AES:
		case SYSCTL_CLOCK_FPIOA:
		case SYSCTL_CLOCK_TIMER0:
		case SYSCTL_CLOCK_TIMER1:
		case SYSCTL_CLOCK_TIMER2:
		case SYSCTL_CLOCK_WDT0:
		case SYSCTL_CLOCK_WDT1:
		case SYSCTL_CLOCK_SHA:
		case SYSCTL_CLOCK_OTP:
		case SYSCTL_CLOCK_RTC:
		case SYSCTL_CLOCK_ACLK:
		case SYSCTL_CLOCK_HCLK:
        default:
            break;
        }
    return result;
}

#include "uarths.h"
#include "sysctl.h"

volatile uarths_t *const uarths = (volatile uarths_t *)0x38000000U;

/*
 * brief	Initialization UART
 * @return	0:success, other:fail
 */
void uarths_init(void){
	uint32_t freq = sysctl_clock_get_freq(SYSCTL_CLOCK_CPU);
	uint16_t div = freq / 115200 - 1;

	uarths->div.div = div;
	uarths->txctrl.txen = 1;
    uarths->rxctrl.rxen = 1;
	uarths->txctrl.txcnt = 0;
    uarths->rxctrl.rxcnt = 0;
	uarths->ip.txwm = 1;
    uarths->ip.rxwm = 1;
	uarths->ie.txwm = 0;
    uarths->ie.rxwm = 1;
}

static inline int uarths_putc(char c){
	while(uarths->txdata.full) continue;
	uarths->txdata.data = (uint8_t) c;
	return 0;
}


/*
 * brief	Put a char to UART
 * @c		the char to put
 * @return	@c : success, EOF : fail
 */
int uarths_putchar(char c){
	return uarths_putc(c);
}

/*
 * brief	Send a string to UART
 * @s		the string to send
 * @return	0 : success, other : fail
 */
int uarths_puts(const char *s){
	while(*s){
	       if(uarths_putchar(*s++) != 0) return -1;
	}
	return 0;
}


#include "uarths.h"

volatile uarths_t *const uarths = (volatile uarths_t *)0x38000000U;

/*
 * brief	Initialization UART
 * @return	0:success, other:fail
 */
void uarths_init(void){
	// FIXME : need to get the real frequency of CPU
#if 0
	uint32_t freq = 390000000UL;
	uint16_t div = freq / 115200 - 1;

	uarths->div.div = div;
#endif
	uarths->txctrl.txen = 1;
	uarths->txctrl.txcnt = 0;
	uarths->ip.txwm = 1;
	uarths->ie.txwm = 0;
}

/*
 * brief	Put a char to UART
 * @c		the char to put
 * @return	@c : success, EOF : fail
 */
int uarths_putchar(char c){
	while(uarths->txdata.full) continue;
	uarths->txdata.data = (uint8_t) c;
	return 0;
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


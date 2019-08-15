#include "string.h"
#include "uarths.h"
#include "clint.h"

int kern_init(void) __attribute__((noreturn));

int kern_init(void){
	extern char edata[], end[];
	memset(edata, 0, end - edata);

	uarths_init();
	uarths_puts("Hello World!\n");

    clint_timer_init();
	while(1);
}

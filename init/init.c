#include "string.h"
#include "uarths.h"

int kern_init(void) __attribute__((noreturn));

int kern_init(void){
	extern char edata[], end[];
	memset(edata, 0, end - edata);

	uarths_init();
	uarths_puts("Hello World!\n");

	while(1);
}

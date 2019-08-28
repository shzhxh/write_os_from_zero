#ifndef __DRIVER_UARTHS_H__
#define __DRIVER_UARTHS_H__

#include <stdint.h>

typedef struct _txdata{
	uint32_t data:8;	// [0:7] data
	uint32_t zero:23;	// [8:30] zero
	uint32_t full:1;	// [31] full status
} __attribute__((packed, aligned(4))) txdata_t;

typedef struct _rxdata{
	uint32_t data:8;	// [0:7] data
	uint32_t zero:23;	// [8:30] zero
	uint32_t empty:1;	// [31] empty status
} __attribute__((packed, aligned(4))) rxdata_t;

typedef struct _txctrl_t{
	uint32_t txen:1;	// [0] enable tx
	uint32_t nstop:1;	// [1] 0:one stop bit, 1:two stop bit
	uint32_t resv0:14;	// [2:15] reserved
	uint32_t txcnt:3;	// [16:18] threshold of interrupt triggers
	uint32_t resv1:13;	// [19:31] reserved
} __attribute__((packed, aligned(4))) txctrl_t;

typedef struct _rxctrl_t{
	uint32_t rxen:1;	// [0] enable rx
	uint32_t resv0:15;	// [1:15] reserved
	uint32_t rxcnt:3;	// [16:18] threshold of interrupt triggers
	uint32_t resv1:13;	// [19:31] reserved
} __attribute__((packed, aligned(4))) rxctrl_t;

typedef struct _ie{
	uint32_t txwm:1;	// [0] raised less than txcnt
	uint32_t rxwm:1;	// [1] raised greater than rxcnt
	uint32_t zero:30;	// [2:31] zero
} __attribute__((packed, aligned(4))) ie_t;

typedef struct _ip{
	uint32_t txwm:1;	// [0] raised less than txcnt
	uint32_t rxwm:1;	// [1] raised greater than rxcnt
	uint32_t zero:30;	// [2:31] zero
} __attribute__((packed, aligned(4))) ip_t;

typedef struct _div{
	uint32_t div:16;	// [0:15] baud rate divisor
	uint32_t zero:16;	// [16:31] zero
} __attribute__((packed, aligned(4))) _div_t;

typedef struct _uarths{
	txdata_t txdata;	// offset 0x00, transmit data register
	rxdata_t rxdata;	// offset 0x04, receive data register
	txctrl_t txctrl;	// offset 0x08, transmit control register
	rxctrl_t rxctrl;	// offset 0x0c, receive control register
	ie_t	ie;		// offset 0x10, UART interrupt enable
	ip_t	ip;		// offset 0x14, UART interrupt pending
	_div_t	div;		// offset 0x18, baud rate divisor
} __attribute__((packed, aligned(4))) uarths_t;

extern volatile uarths_t *const uarths;

/*
 * brief	Initialization UART
 * @return	0:success, other:fail
 */
void uarths_init(void);

/*
 * brief	Put a char to UART
 * @c		the char to put
 * @return	@c : success, EOF : fail
 */
int uarths_putchar(char c);

/*
 * brief	Send a string to UART
 * @s		the string to send
 * @return	0 : success, other : fail
 */
int uarths_puts(const char *s);


#endif /* __DRIVER_UARTHS_H__ */

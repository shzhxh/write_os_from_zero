#ifndef __DRIVER_CLINT_H__
#define __DRIVER_CLINT_H__

# include <stdint.h>

typedef struct _clint_msip{
    uint32_t msip : 1;
    uint32_t zero : 31;
}__attribute__((packed, aligned(4))) clint_msip_t;

typedef struct _clint{
    clint_msip_t msip[4095];    // MSIP Registers : 0x0 ~ 0x3ff8
    uint32_t    resv0;          // Reserved space 
    uint64_t    mtimecmp[4095]; // Timer compare Registers : 0x4000 ~ 0xbff0
    uint64_t    mtime;          // mtimer Register : 0xbff8
}__attribute__((packed, aligned(4))) clint_t;

extern volatile clint_t* const clint;

int clint_timer_init(void);

#endif /* __DRIVER_CLINT_H__ */

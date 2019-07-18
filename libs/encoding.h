#ifndef __ENCODING_H__
#define __ENCODING_H__

#define STORE   sd
#define LOAD    ld

#define REGBYTES    8

#define IRQ_M_SOFT   3
#define IRQ_M_TIMER  7
#define IRQ_M_EXT    11

#define CAUSE_MISALIGNED_FETCH     0x0
#define CAUSE_FAULT_FETCH          0x1
#define CAUSE_ILLEGAL_INSTRUCTION  0x2
#define CAUSE_BREAKPOINT           0x3
#define CAUSE_MISALIGNED_LOAD      0x4
#define CAUSE_FAULT_LOAD           0x5
#define CAUSE_MISALIGNED_STORE     0x6
#define CAUSE_FAULT_STORE          0x7
#define CAUSE_USER_ECALL           0x8
#define CAUSE_SUPERVISOR_ECALL     0x9
#define CAUSE_HYPERVISOR_ECALL     0xa
#define CAUSE_MACHINE_ECALL        0xb

#endif /* __ENCODING_H__ */

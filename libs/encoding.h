#ifndef __LIBS_ENCODING_H__
#define __LIBS_ENCODING_H__

#define MSTATUS_UIE         0x00000001U
#define MSTATUS_SIE         0x00000002U
#define MSTATUS_HIE         0x00000004U
#define MSTATUS_MIE         0x00000008U
#define MSTATUS_UPIE        0x00000010U
#define MSTATUS_SPIE        0x00000020U
#define MSTATUS_HPIE        0x00000040U
#define MSTATUS_MPIE        0x00000080U
#define MSTATUS_SPP         0x00000100U
#define MSTATUS_HPP         0x00000600U
#define MSTATUS_MPP         0x00001800U
#define MSTATUS_FS          0x00006000U
#define MSTATUS_XS          0x00018000U
#define MSTATUS_MPRV        0x00020000U
#define MSTATUS_PUM         0x00040000U
#define MSTATUS_MXR         0x00080000U
#define MSTATUS_VM          0x1F000000U
#define MSTATUS32_SD        0x80000000U
#define MSTATUS64_SD        0x8000000000000000U

#define STORE   sd
#define LOAD    ld

#define REGBYTES    8

#define IRQ_M_SOFT   3
#define IRQ_M_TIMER  7
#define IRQ_M_EXT    11

#define MIP_MSIP            (1U << IRQ_M_SOFT)
#define MIP_MTIP            (1U << IRQ_M_TIMER)
#define MIP_MEIP            (1U << IRQ_M_EXT)


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

#define read_csr(reg) ({ unsigned long __tmp; \
    asm volatile ("csrr %0, "#reg : "=r"(__tmp)); \
    __tmp; })

#define set_csr(reg, bit) ({ unsigned long __tmp; \
    asm volatile ("csrrs %0," #reg ", %1" : "=r"(__tmp) : "r"(bit)); \
    __tmp; })

#define current_coreid()    read_csr(mhartid)

#endif /* __LIBS_ENCODING_H__ */

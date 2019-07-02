#define KSTACKSIZE 4096	// Size of kernel stack

.globl _start
_start:
    j kern_entry
	.word 0xdeadbeef

kern_entry:
	csrw mideleg, 0
	csrw medeleg, 0
	csrw mie, 0		// Mask all interrupts

	csrr a0, mhartid	// Get CPU id

	la sp, __stack_start__	// Defined in kernel.ld
	addi t1, a0, 1
	li t2, KSTACKSIZE
	mul t1, t1, t2
	add sp, sp, t1	// sp = __stack_start__ + (cpuid+1)*KSTACKSIZE
	
	bnez a0, secondary_cpu_entry
	j primary_cpu_entry

primary_cpu_entry:
	tail kern_init 

secondary_cpu_entry:
	wfi

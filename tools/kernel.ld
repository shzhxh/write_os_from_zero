/* Simple linker script for the ucore kernel.
   See the GNU ld 'info' manual ("info ld") to learn the syntax. */

OUTPUT_ARCH(riscv)
ENTRY(_start)

BASE_ADDRESS = 0x80000000;
__STACKSIZE__ = 4096;

MEMORY
{
    /* 6M SRAM */
    SRAM : o = 0x80000000, l = 0x600000
}

SECTIONS
{
    /* Load the kernel at this address: "." means the current address */
    . = BASE_ADDRESS;

    .start :{
	*(.start);
    } > SRAM

    . = ALIGN(4);

    .text : {
        *(.text.kern_entry .text .stub .text.* .gnu.linkonce.t.*)
    } > SRAM

    PROVIDE(etext = .); /* Define the`` 'etext' symbol to this value */

    .rodata : {
        *(.rodata .rodata.* .gnu.linkonce.r.*)
    } > SRAM

    /* Adjust the address for the data segment to the next page */
    . = ALIGN(0x1000);

    /* The data segment */
    .data : {
        *(.data)
        *(.data.*)
    } > SRAM

    /* stack for dual core */
    .stack :
    {
      . = ALIGN(64);
      __stack_start__ = .;

      . += __STACKSIZE__ ;
      __stack_cpu0 = .;

      . += __STACKSIZE__ ;
      __stack_cpu1 = .;
    } > SRAM

    .sdata : {
        *(.sdata)
        *(.sdata.*)
    } > SRAM

    PROVIDE(edata = .);

    .bss : {
        *(.bss)
        *(.bss.*)
        *(.sbss*)
    } > SRAM

    PROVIDE(end = .);

    /DISCARD/ : {
        *(.eh_frame .note.GNU-stack)
    }
}

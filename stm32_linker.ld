ENTRY(Reset_Handler)

MEMORY
{
    FLASH(rx) : ORIGIN =0x08000000, LENGTH =1024K
    SRAM(rwx) : ORIGIN =0x20000000, LENGTH =128K
}

SECTIONS
{
    /* text section, to store the text sections of all the object files */
    .text : {
        *(.isr_vector)
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        _etext = .;            /* End of the text section */
    }> FLASH

    .data : {
        _sdata = .;          /* Start of the data section */
        *(.data)
        . = ALIGN(4);
        _edata = .;            /* Start of data section */
    }> SRAM AT> FLASH

    .bss : {
        _sbss = .;          /* Start of the BSS section */
        *(.bss)
        . = ALIGN(4);
        _ebss = .;          /* End of the BSS section */
    }> SRAM
}
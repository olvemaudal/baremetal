ENTRY(_start)

SECTIONS
{
    .text : {
        *(.text)
        *(.rodata)
    }
    .data : {
        *(.data)
    }
    .bss : {
        *(.bss)
        *(COMMON)
    }
}

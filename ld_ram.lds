MEMORY
{
    flash (rx)  : ORIGIN = 0x08000000, LENGTH = 1M
    sram1 (wx)  : ORIGIN = 0x20000000, LENGTH = 96K
    sram2 (wx)  : ORIGIN = 0x10000000, LENGTH = 32K
}

_stack = ORIGIN(sram2) + LENGTH(sram2);

ENTRY(_start)

SECTIONS
{
    /* Contient le programme */
    .text : {
        *(.text)
    } > sram1

    /* Contient les constantes */
    .rodata : {
        *(.rodata)
    }  > sram1

    /* Contient les data */
    .data : {
        *(.data)
    }  > sram1

    /* Contient les données non initialisées */
    _start_bss = .;
    .bss : {
        *(.bss)*(COMMON)
    }  > sram1
    _end_bss = .;
}

OUTPUT_FORMAT(elf32-i386)
ENTRY(_KiLoader)

SECTIONS
{
    . = 0x100000;
    .text : {
        *(.multiboot_header)  
        *(.text)        
    }
    .bss : {
        *(.bss) 
    }
}

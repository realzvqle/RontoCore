%define ALIGN    (1 << 0)
%define MEMINFO  (1 << 1)
%define FLAGS    (ALIGN | MEMINFO)
%define MAGIC    0x1BADB002
%define CHECKSUM (-(MAGIC + FLAGS))

section .multiboot_header
align 4
dd MAGIC
dd FLAGS
dd CHECKSUM

section .bss
align 16
stack_bottom:
resb 65536
stack_top:

section .data
loadmessage db "Loading RontoCores Kernel....", 10, 10, 0

section .text
global _KiLoader
extern KiTerminalClearScreen
extern KiTerminalPuts
extern KiInitializeHeap
extern KiEntry
_KiLoader:
    mov esp, stack_top
    call KiTerminalClearScreen
    push loadmessage
    call KiTerminalPuts
    add esp, 4
    call KiInitializeHeap
    call KiEntry
    cli
.halt:
    hlt
    jmp .halt


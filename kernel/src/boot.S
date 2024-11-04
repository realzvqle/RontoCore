.set ALIGN,    1<<0           
.set MEMINFO,  1<<1            
.set FLAGS,    ALIGN | MEMINFO  
.set MAGIC,    0x1BADB002       
.set CHECKSUM, -(MAGIC + FLAGS) 


.section .multiboot_header
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM


.section .bss
.align 16
stack_bottom:
.skip 65536 
stack_top:

.section .data 
loadmessage:
    .asciz "Loading AstaraOS Kernel....\n\n"
.section .text
.global _KiLoader

.type _KiLoader, @function
_KiLoader:	
	mov $stack_top, %esp
    call KiTerminalClearScreen
    push $loadmessage
    call KiTerminalPuts
    add $4, %esp
    call KiInitializeHeap
	call KiEntry
	cli
1:	hlt
	jmp 1b


.size _KiLoader, . - _KiLoader
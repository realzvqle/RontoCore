.section .multiboot
.align 4
.long 0x1BADB002      
.long 0x0              
.long -(0x1BADB002)   

.section .text
.global _start
_start:
    cli                
    mov $kernel_main, %eax
    call *%eax        
    hlt               

.section .multiboot
.align 4
.long 0x1BADB002      
.long 0x0              
.long -(0x1BADB002)   

.section .text
.global _KiLoader
_KiLoader:
    cli                
    mov $KiEntry, %eax
    call *%eax        
    hlt               

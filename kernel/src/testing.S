
.section .data

message:
    .asciz "Testing....\n"

.section .text

.global KiTest
.extern KiTerminalPuts

KiTest:
    # Preserve The Stack
    push %ebp                
    mov %esp, %ebp            
    push %ebx                 
    push %esi
    push %edi

    push $message
    call KiTerminalPuts
    add $4, %esp

    # Restore The Stack
    pop %edi
    pop %esi
    pop %ebx
    mov %ebp, %esp           
    pop %ebp   
    ret


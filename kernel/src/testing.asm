
section .data

message db "Loading Message", 10, 10, 0

section .text

global KiTest
extern KiTerminalPuts

KiTest:
    push ebp             
    mov ebp, esp   

    push message
    call KiTerminalPuts
    add esp, 4

    mov esp, ebp          
    pop ebp    
    ret


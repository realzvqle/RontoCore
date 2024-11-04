#include "shell/shell.h"
#include "terminal/terminal.h"


extern void KiTest();
void KiEntry() {
    KiTest();
    KiTerminalPuts("\nI Love NASM");
    

    KiKernelShellInit();

    while(1){continue;}
}
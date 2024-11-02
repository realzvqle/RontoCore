#include "malloc/malloc.h"
#include "shell/shell.h"
#include "terminal/terminal.h"



void KiEntry() {

    KiTerminalPuts("System Was Compiled On ");
    KiTerminalPuts(__TIMESTAMP__);
    KiTerminalPuts("\n");

    KiKernelShellInit();

    while(1){continue;}
}
#include "drivers/driver.h"
#include "malloc/malloc.h"
#include "shell/shell.h"
#include "terminal/terminal.h"


extern void KiTest();
void KiEntry() {
    KiTest();
    KiTerminalPuts("\nI Love NASM");
    KiTerminalPuts("System Was Compiled On ");
    KiTerminalPuts(__TIMESTAMP__);
    KiTerminalPuts("\n");

    KiKernelShellInit();

    while(1){continue;}
}
#include "malloc/malloc.h"
#include "terminal/terminal.h"
#include "drivers/ps2/ps2.h"


void KiEntry() {
    KiInitializeHeap();
    KiTerminalClearScreen();
    KiTerminalPuts("Hello World!\nWelcome to my Little OS that idk what ill do without =(");
    
    char* idk =  KiTerminalGets(512);
    KiTerminalPuts(idk);
    KiTerminalPutChar('\n');
    
}
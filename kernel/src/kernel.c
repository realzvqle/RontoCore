#include "malloc/malloc.h"
#include "terminal/terminal.h"



void KiEntry() {
    
    KiTerminalPuts("System Was Compiled On ");
    KiTerminalPuts(__TIMESTAMP__);
    KiTerminalPuts("\n");

    while(1){
        char* idk = KiTerminalGets(512);
        KiTerminalPuts(idk);
        KiFreeMemory(idk);
    }
    
}
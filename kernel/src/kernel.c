#include "malloc/malloc.h"
#include "terminal/terminal.h"



void KiEntry() {
    while(1){
        char* idk = KiTerminalGets(512);
        KiTerminalPuts(idk);
        KiFreeMemory(idk);
    }
    
}
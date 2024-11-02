#include "shell.h"
#include "../terminal/terminal.h"
#include "../malloc/malloc.h"
#include "../rtlfunc/rtlfunc.h"




void KiKernelShellInit(){
    while(1){
        char first[512];
        char second[512];
        char* idk = KiTerminalGets(1024);
        RtlSliceStrings(idk, ' ', first, second, 512, 512);
        KiTerminalPuts("FIRST - ");
        KiTerminalPuts(first);
        KiTerminalPuts(" SECOND - ");
        KiTerminalPuts(second);
        KiFreeMemory(idk);
    }
}
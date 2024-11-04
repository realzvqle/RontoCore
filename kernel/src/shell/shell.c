#include "shell.h"
#include "../terminal/terminal.h"
#include "../malloc/malloc.h"
#include "../rtlfunc/rtlfunc.h"
#include "../drivers/ps2/ps2.h"

static char* commands[] = {"echo", "clear", "ps2test", "help", "ERROR!"};




static inline void InterpretCommands(char* command, char* arguments){
    int cmdsize = sizeof(commands)/sizeof(commands[0]);
    for(int i = 0; i < cmdsize; i++){
        if(RtlStringCompare(command, commands[i])){
            switch(i){
                case 0:
                    KiTerminalPuts(arguments);
                    break;
                case 1:
                    KiTerminalClearScreen();
                    break;
                case 2:
                {
                    KiTerminalPuts("RontoCore PS/2 Driver Test\nClick SHIFT to Exit\n\n");
                    while(1){
                        char buffer[512];
                        int scan_code = Ps2ReadScanCodeFromPort();
                        if(scan_code == 42) break;
                        RtlIntegerToAsciiString(scan_code, buffer);
                        KiTerminalPuts(buffer);
                        KiTerminalPuts("\n");
                    }
                    break;
                }
                case 3:
                {
                    for(int i = 0; i < cmdsize; i++){
                        int j = 0;
                        if(i == 4) continue;
                        KiTerminalPuts(commands[i]);
                        KiTerminalPuts("   ");
                        j = i + 1;
                        if(j % 2 == 0) KiTerminalPuts("\n");
                    }
                    break;
                }
                case 4:
                    KiTerminalPuts(arguments);
                    while(1){continue;}
                    break;
                default:
                    KiTerminalPuts("Error: Undefined Area of Switch Has Been Called\n");
                    break;
            }
            return;
        }
    }
    KiTerminalPuts("Command not found, Please Type 'help' for a list of commands\n");
}


void KiKernelShellInit(){
    KiTerminalClearScreen();
    KiTerminalPuts("Welcome to RontoCore Operating System\nType Help for a list of commands!\n\n");
    while(1){   
        char first[512];
        char second[512];
        char* buffer = KiTerminalGets(1024);
        RtlSliceStrings(buffer, ' ', first, second, 512, 512);
        InterpretCommands(first, second);
        KiFreeMemory(buffer);
    }
}
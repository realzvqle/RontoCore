#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED




#include "../superheader.h"


void KiTerminalPuts(const char* str);
void KiTerminalPutChar(char c);
void KiTerminalClearScreen();
char* KiTerminalGets(size_t size);
#endif
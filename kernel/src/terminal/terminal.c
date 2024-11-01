#include "terminal.h"
#include "../drivers/ps2/ps2.h"
#include "../malloc/malloc.h"

volatile char* video_memory = (volatile char*) 0xB8000;

int cursor_x = 0; 
int cursor_y = 0;

void KiTerminalClearScreen() {
    for (int i = 0; i < 80 * 25; i++) {
        video_memory[i] = (char)0x0F00;
    }
    cursor_x = 0; 
    cursor_y = 0; 
}

void KiTerminalPutChar(char c){
    if(c == '\n'){
        cursor_x = 0;
        cursor_y++;
    }
    else{
        video_memory[cursor_y * 160 + cursor_x * 2] = c; 
        video_memory[cursor_y * 160 + cursor_x * 2 + 1] = 0x0F;
        cursor_x++;
    }
    if(cursor_x >= 80){
        cursor_x = 0;
        cursor_y++;
    }
    if (cursor_y >= 25) {
        cursor_y = 0;
    }
}

void KiTerminalPuts(const char* str) {
    while (*str) {
        KiTerminalPutChar(*str++);
    }
}

static inline char* ArrayAdder(size_t size) {
    char* array = (char*)KiAllocateMemory(size);
    if (!array) return NULL; 
    for (size_t jj = 0; jj < size; jj++) {
        array[jj] = '\0';  
    }

    char former_char = '\0'; 
    int index = 0;

    while (index < size - 1) { 
        char character = Ps2ReadKey();
        if (character == '\0') continue;  

        if (character == '\n') {
            break;  
        }

        array[index] = character; 
        char temp[2] = { character, '\0' };  
        KiTerminalPuts(temp);
        former_char = character;
        index++;
    }

    array[index] = '\0';  
    return array;
}


char* KiTerminalGets(int size){
    KiTerminalPuts("> ");
    char* result = ArrayAdder(size);
    if(result == NULL) return "fuck";
    return result;
}
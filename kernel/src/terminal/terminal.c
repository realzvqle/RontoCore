#include "terminal.h"
#include "../drivers/ps2/ps2.h"
#include "../malloc/malloc.h"

volatile char* video_memory = (volatile char*) 0xB8000;

int cursor_x = 0; 
int cursor_y = 0;

void KiTerminalClearScreen() {
    for (int i = 0; i < 800 * 250; i++) {
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
        KiTerminalClearScreen();
        cursor_y = 0;
    }
}

void KiTerminalPuts(const char* str) {
    while (*str) {
        KiTerminalPutChar(*str++);
    }
}

static inline char* ArrayAdder(size_t size) {
    static bool caps = false;
    char* array = KiAllocateMemory(size);
    if (!array) {
        return NULL;  
    }

    
    static char former_char;
    char character;
    int index = 0;
    while (index < (size - 1)) { 

        uint8_t scan_code = Ps2ReadScanCodeFromPort();
        if(scan_code == 14){
            if(index == 0) continue;
            array[index] = '\0';
            index--;
            video_memory[cursor_y * 160 + cursor_x-- * 2] = 'S'; 
            video_memory[cursor_y * 160 + cursor_x * 2 + 1] = 0x00;
            continue;
        }
        else if(scan_code == 58){
            if(caps == true) caps = false;
            else caps = true;
            continue;
        }

        else{
            if(caps == false) character = Ps2ScanCodeToCharacter(scan_code);
            else{
                if(scan_code == 28){
                    caps = false;
                    character = Ps2ScanCodeToCharacter(scan_code);
                }    
                else if(scan_code < 50){
                    char haracter = Ps2ScanCodeToCharacter(scan_code);
                    character = haracter - 32;
                }
                switch(scan_code){
                    case 57:
                        character = ' ';
                        break;
                    case 28:
                        character = '\n';
                        break;
                }
                
            }
            
        } 
        
        if(character == NULL){
            continue;
        }
        if (character == '\n') {
            array[index] = '\0';  
            break;
        }
        array[index] = character; 
        char temp[2];
        temp[0] = character;
        temp[1] = '\0';  
        index++;
        KiTerminalPuts(temp);
        former_char = character;
        
    }

    if (index == (size - 1)) {
        array[size - 1] = '\0';  
    }

    return array;
}

char* KiTerminalGets(size_t size){
    KiTerminalPuts("\n-> ");
    char* result = ArrayAdder(size);
    if(result == NULL) return "ERROR! MEMORY ALLOCATION FAILURE";
    KiTerminalPuts("\n");
    return result;
}

void KiTerminalTurnOffCursor() {
    KiOutByte(0x3D4, 0x0A); 
    KiOutByte(0x3D5, 0x20);

    KiOutByte(0x3D4, 0x0B);
    KiOutByte(0x3D5, 0x3F); 
}
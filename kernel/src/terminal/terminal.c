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
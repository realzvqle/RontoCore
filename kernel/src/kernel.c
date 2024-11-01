volatile char* video_memory = (volatile char*) 0xB8000;




void KiEntry() {
    int i = 0;
    while(1){
        i++;
        video_memory[i] = 'Q';
        i++;
        video_memory[i] = 0x09;
        i++;
        video_memory[i] = '\n';
        i++;
        video_memory[i] = 0x10;
    }
}
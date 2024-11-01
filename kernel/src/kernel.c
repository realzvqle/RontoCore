volatile char* video_memory = (volatile char*) 0xB8000;

void kernel_main() {
    video_memory[0] = 'Q';
    video_memory[1] = 0x07;
    video_memory[2] = 'i';
    video_memory[3] = 0x07;
}
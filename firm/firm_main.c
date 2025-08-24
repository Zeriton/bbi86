__attribute__((section(".text.head"), naked))
void _firm_start(void) {
    __asm__ volatile(
        "movl 0x1000, %esp\r\n"
        "hlt"
    );
}

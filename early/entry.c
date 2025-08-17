__attribute__((section(".entry"), naked))
void _entry(void) {
  __asm__ volatile("hlt");
}

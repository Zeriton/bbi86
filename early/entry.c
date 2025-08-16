__attribute__((section(".boot"), naked))
void _entry(void) {
  __asm__ volatile("hlt");
}

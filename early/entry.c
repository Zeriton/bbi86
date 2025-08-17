#include "../utils/uart16550.h"

__attribute__((section(".entry"), naked))
void _entry(void) {
  /*
	Unstable temporary stack test, remember DRAM
	has not been trained yet, and many other hardware
	initializations have not been run.

	In emulaters like QEMU, they don't really support
	silicon init, memory init, etc. So it's mostly just a
	guessing game from what is known to work.
  */
  __asm__ volatile(
    "movl 0x4F0, %esp\n"
	"call test\n"
    "hlt"
  );
}

void test(void) {
  /*
	Just to check if calling now works
	---but it should.
  */

  /*
	Realistically we shouldn't do this before DRAM init or even silicon init..
	but for emulation purposes it's fine.
  */

  uart_16550_write_safe('H');
  uart_16550_write_safe('e');
  uart_16550_write_safe('l');
  uart_16550_write_safe('l');
  uart_16550_write_safe('o');
  uart_16550_write_safe('!');
}

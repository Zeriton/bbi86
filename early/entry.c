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
}

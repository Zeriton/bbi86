#ifndef __BBI86_UTILS_BASIC_IO_H
#define __BBI86_UTILS_BASIC_IO_H

static inline unsigned char inb(unsigned short addr) {
  unsigned char result;
  __asm__ volatile(
    "inb %1, %0"
	: "=r" (result)
	: "Nd" (addr)
  );
  return result;
}

static inline void outb(unsigned short addr, unsigned char value) {
  __asm__ volatile(
    "outb %0, %1"
	:
	: "r" (value), "Nd" (addr)
  );
}

#endif /* __BBI86_UTILS_BASIC_IO_H */

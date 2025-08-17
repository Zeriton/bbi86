#ifndef __BBI86_UTILS_UART_16550_H
#define __BBI86_UTILS_UART_16550_H

#include "basic_io.h"

// TODO: Add MMIO support

#define uart_16550_is_thr_ready() (inb(UART_BASE_ADDRESS + 5) & 0x20)
#define uart_16550_is_data_ready() (inb(UART_BASE_ADDRESS + 5) & 0x01)
#define uart_16550_write(c) outb(UART_BASE_ADDRESS, c)

static inline void uart_16550_write_safe(unsigned char c) {
  while (!uart_16550_is_thr_ready()) {}
  uart_16550_write(c);
}

#endif /* __BBI86_UTILS_UART_16550_H */

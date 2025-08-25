#ifndef __BBI86_SCRIPTS_KCONFIG_LEXER_H
#define __BBI86_SCRIPTS_KCONFIG_LEXER_H

#include <stdint.h>

typedef struct {
    const char *contents;
    size_t pos;
} kconfig_lexer_t;

#endif /* __BBI86_SCRIPTS_KCONFIG_LEXER_H */

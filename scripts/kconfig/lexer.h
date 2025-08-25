#ifndef __BBI86_SCRIPTS_KCONFIG_LEXER_H
#define __BBI86_SCRIPTS_KCONFIG_LEXER_H

#include <stdint.h>

#include "types.h"
#include "token.h"

typedef enum {
    NONE = 0, 
    END,
} kconfig_lexer_state_t;

typedef struct {
    const KCONFIG_FAT_POINTER(char) *contents;
    size_t cursor_position;
    size_t cursor_row;
    size_t cursor_col;
    
    kconfig_lexer_state_t state;
} kconfig_lexer_t;

#define KCONFIG_LEXER_NEW(c)                    \
    (kconfig_lexer_t) {                         \
        .contents = c,                          \
        .cursor_position = 0,                   \
        .cursor_row = 1,                        \
        .cursor_col = 1,                        \
        .state = NONE,                          \
    }

int kconfig_lexer_lex(kconfig_lexer_t *lexer, kconfig_vector_t *tokens);

#endif /* __BBI86_SCRIPTS_KCONFIG_LEXER_H */

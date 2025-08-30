#ifndef __BBI86_SCRIPTS_KCONFIG_LEXER_H
#define __BBI86_SCRIPTS_KCONFIG_LEXER_H

#include "types.h"
#include "token.h"

typedef enum {
    NONE = 0,
    IDENT,
    NUM,
    
    END,
} kconfig_lexer_state_t;

typedef struct {
    const KCONFIG_FAT_POINTER(char) *contents;
    size_t index;
    size_t file_row, file_col;
    
    kconfig_lexer_state_t state;
} kconfig_lexer_t;

static inline kconfig_lexer_t kconfig_lexer_init(const KCONFIG_FAT_POINTER(char) *contents) {
    return (kconfig_lexer_t) {
        .contents = contents,
        .index = 0,
        
        .file_row = 1,
        .file_col = 1,

        .state = NONE,
    };
}

errorv_t kconfig_lexer_lex(kconfig_lexer_t *lexer, kconfig_vector_t *tokens);

#endif /* __BBI86_SCRIPTS_KCONFIG_LEXER_H */

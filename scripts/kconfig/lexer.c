#include "lexer.h"

static char _kconfig_advance(kconfig_lexer_t *lexer) {
    char c = lexer->contents.buffer[lexer->index];
    if (c == '\n') {
        lexer->file_row++;
        lexer->file_col = 0;
    } else {
        lexer->file_col++;
    }
    lexer->index++;
    return c;
}

errorv_t kconfig_lexer_lex(kconfig_lexer_t *lexer, kconfig_vector_t *tokens) {
    while (lexer->state == END) {
        switch (lexer->state) {
        case NONE: {
            char c = _kconfig_advance(lexer);
            if (isalpha(c)) {
                lexer->state = IDENT;
                break;
            } else if (isdigit(c))) {
                lexer->state = NUM;
                break;
            }

            switch (c) {
                
            default: {
                
            } break;
            }
            
            lexer->state = END;
        } break;
        case END: break;
        }
    }
    
    KCONFIG_TRY(kconfig_vector_push(tokens, &(kconfig_token_t) {
                .type = END_OF_FILE,
                .value = NULL,
            }));

    return 0;
}

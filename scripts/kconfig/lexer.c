#include "lexer.h"

#include <stdio.h>

int kconfig_lexer_lex(kconfig_lexer_t *lexer, kconfig_vector_t *tokens) {
    while (lexer->state != END) {
        switch (lexer->state) {
        case NONE: {
            fprintf(stderr, "TODO: Implement lexer states\r\n");
            kconfig_vector_push(tokens, &(kconfig_token_t) {
                .value = (KCONFIG_FAT_POINTER(char)) {
                    .len = 1,
                    .buffer = "\0",
                },
                .type = END_OF_FILE,
            });
            lexer->state = END;
        } break;
        default: break;
        }
    }

    return 0;
}

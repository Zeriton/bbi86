#include <stdio.h>

#include "types.h"
#include "args.h"
#include "file.h"
#include "lexer.h"

int main(int argc, char **argv) {
    kconfig_provided_t provided;
    KCONFIG_TRY(kconfig_extract_args(&argc, &argv, &provided));

    KCONFIG_FAT_POINTER(char) config_contents;
    KCONFIG_TRY(kconfig_read_to_string(provided.config_path, &config_contents));

    printf("config contents:\r\n%s\r\n", config_contents.buffer);

    kconfig_lexer_t lexer = kconfig_lexer_init(&config_contents);
    kconfig_vector_t tokens;
    KCONFIG_TRY(kconfig_vector_new(&tokens, sizeof(kconfig_token_t)));

    int result = 0;

    if ((result = kconfig_lexer_lex(&lexer, &tokens)))
        goto exit_result;
    
exit_result:
    KCONFIG_VECTOR_FREE(tokens);
    free(config_contents.buffer);
    return result;
}

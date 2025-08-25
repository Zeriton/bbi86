#include <stdio.h>

#include "types.h"
#include "args.h"
#include "file.h"
#include "lexer.h"

#define KCONFIG_HANDLE_RESULT_NOT_EQ(result, value) \
    { int r; if ((r = result) != value) return r; }

int main(int argc, char **argv) {
    int result = 0;
    
    kconfig_provided_t provided;
    KCONFIG_HANDLE_RESULT_NOT_EQ(
        kconfig_extract_args(&argc, &argv, &provided), 0)

    KCONFIG_FAT_POINTER(char) config_contents;
    KCONFIG_HANDLE_RESULT_NOT_EQ(
        kconfig_read_to_string(provided.config_path, &config_contents), 0)

    printf("config contents:\r\n%s\r\n", config_contents.buffer);

    kconfig_lexer_t lexer = KCONFIG_LEXER_NEW(&config_contents);

    kconfig_vector_t config_tokens;
    KCONFIG_HANDLE_RESULT_NOT_EQ(
        kconfig_vector_new(&config_tokens), 0)
    
    KCONFIG_HANDLE_RESULT_NOT_EQ(
        kconfig_lexer_lex(&lexer, &config_tokens), 0);

    fprintf(stderr, "TODO: implement parser\r\n");

    KCONFIG_VECTOR_DESTROY(config_tokens);
    free(config_contents.buffer);
    return result;
}

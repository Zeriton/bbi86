#include <stdio.h>

#include "types.h"
#include "args.h"
#include "file.h"

int main(int argc, char **argv) {
    kconfig_provided_t provided;
    int arg_extraction_result = kconfig_extract_args(&argc, &argv, &provided);
    if (arg_extraction_result < 0)
        return arg_extraction_result;

    KCONFIG_FAT_POINTER(char) config_contents;
    int config_read_result = kconfig_read_to_string(provided.config_path, &config_contents);
    if (config_read_result < 0)
        return config_read_result;

    printf("config contents:\r\n%s\r\n", config_contents.buffer);
    fprintf(stderr, "TODO: implement lexer & parser\r\n");

    free(config_contents.buffer);
    return 0;
}

#ifndef __BBI86_SCRIPTS_KCONFIG_ARGS_H
#define __BBI86_SCRIPTS_KCONFIG_ARGS_H

#include <stdio.h>
#include <string.h>

typedef struct {
    /* Position Arguments */
    const char *config_path;

    /* Flags */
    const char *output_dir;
} kconfig_provided_t;

/* Helper function to step to next arg */
static inline char *_kconfig_shift_arg(int *argc, char ***argv) {
    char *arg = **argv;
    (*argv)++;
    (*argc)--;
    return arg;
}

static inline void _kconfig_print_usage(const char *program) {
    fprintf(stderr, "usage: %s [CONFIG] ARG?..\r\n", program);
    fprintf(stderr, "arguments:\r\n");
    fprintf(stderr, "   -- '-o', args: [OUTPUT DIRECTORY], info: specifies the output directory\r\n");
}

/* Extracts what is needed from the arguments */
static int kconfig_extract_args(int *argc, char ***argv, kconfig_provided_t *provided) {
    const char *program = _kconfig_shift_arg(argc, argv);
    if (*argc == 0) {
        fprintf(stderr, "error: expected fulfilled position argument!\r\n");
        _kconfig_print_usage(program);
        return -1;
    }

    const char *config_path = _kconfig_shift_arg(argc, argv);
    (*provided).config_path = config_path;

    char *output_dir = "./";
    while (*argc > 0) {
        const char *arg = _kconfig_shift_arg(argc, argv);
        if (strcmp(arg, "-o") == 0) {
            if (*argc < 1) {
                fprintf(stderr, "error: expected positional argument(s) after flag '%s'\r\n", arg);
                _kconfig_print_usage(program);
                return -3;
            }

            char *dir = _kconfig_shift_arg(argc, argv);
            output_dir = dir;
        } else {
            fprintf(stderr, "error: invalid argument '%s'\r\n", arg);
            _kconfig_print_usage(program);
            return -2;
        }
    }

    (*provided).output_dir = output_dir;
    return 0;
}

#endif /* __BBI86_SCRIPTS_KCONFIG_ARGS_H */

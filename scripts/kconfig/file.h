#ifndef __BBI86_SCRIPTS_KCONFIG_FILE_H
#define __BBI86_SCRIPTS_KCONFIG_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "types.h"

int kconfig_read_to_string(const char *path, KCONFIG_FAT_POINTER(char) *fat_buffer) {
    FILE *stream = fopen(path, "r"); /* Open read-only file stream */
    if (!stream) {
        fprintf(stderr, "error: unable to open file ('%s')\r\n", path);
        return -1;
    }

    /* Get the size of the file, except the NULL terminator */
    fseek(stream, 0, SEEK_END); /* Set cursor to end */
    long size = ftell(stream);  /* Get cursor position, or in this case the file size */
    if (size < 0) {
        fprintf(stderr, "error: failed to fetch file ('%s') size\r\n", path);
        fclose(stream);
        return -2;
    } else if (size == 0) {
        /*
          If a file is empty, we should exit early as some
          libc file/memory definitions can cause some problems when zero...
          and it also doesn't waste CPU cycles..
        */
        *fat_buffer = (KCONFIG_FAT_POINTER(char)) {
            .len = 1,
            .buffer = '\0',
        };
        
        fclose(stream);
        return 0;
    }
    fseek(stream, 0, SEEK_SET); /* Set cursor to start */
    size_t buffer_size = size + 1;

    /* Create the read buffer */
    char *buffer = malloc(buffer_size);
    if (!buffer) {
        fprintf(stderr, "error: failed to allocate read buffer for file ('%s')\r\n", path);
        fclose(stream);
        return -3;
    }

    /* Read file to buffer */
    size_t read_result = fread(buffer, 1, buffer_size - 1, stream);
    if (read_result != buffer_size - 1) {
        fprintf(stderr, "error: failed to read file ('%s') to buffer\r\n", path);
        free(buffer);
        fclose(stream);
        return -4;
    }

    buffer[buffer_size] = '\0';
    
    *fat_buffer = (KCONFIG_FAT_POINTER(char)) {
        .len = buffer_size,
        .buffer = buffer,
    };

    fclose(stream);
    return 0;
}

#endif /* __BBI86_SCRIPTS_KCONFIG_FILE_H */

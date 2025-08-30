#ifndef __BBI86_SCRIPTS_KCONFIG_TYPES_H
#define __BBI86_SCRIPTS_KCONFIG_TYPES_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef size_t errorv_t;
#define KCONFIG_TRY(result) { errorv_t r; if ((r = result) != 0) return r; }

#define KCONFIG_FAT_POINTER_DEF(type)           \
    struct kconfig_fat_pointer_##type {         \
        size_t len;                             \
        type *buffer;                           \
    }

KCONFIG_FAT_POINTER_DEF(char);

#define KCONFIG_FAT_POINTER(type) struct kconfig_fat_pointer_##type

typedef struct {
    void *buffer;
    size_t item_size;
    size_t cap, len;
} kconfig_vector_t;

#define KCONFIG_VECTOR_FREE(vec) free(vec.buffer)

static inline errorv_t kconfig_vector_new(kconfig_vector_t *vec, size_t item_size) {
    size_t cap = 4;

    void *buffer = malloc(item_size * cap);
    if (!buffer) {
        fprintf(stderr, "error: unable to allocate buffer\r\n");
        return 1;
    }
    vec->buffer = buffer;

    vec->item_size = item_size;
    vec->cap = cap;
    vec->len = 0;

    return 0;
}

static inline void *kconfig_vector_index(kconfig_vector_t *vec, size_t index) {
    if (index >= vec->len) {
        fprintf(stderr, "error: index is out of bounds\r\n");
        return NULL;
    }
    
    return vec->buffer + vec->item_size * index;
}

errorv_t kconfig_vector_push(kconfig_vector_t *vec, void *item);
errorv_t kconfig_vector_pop(kconfig_vector_t *vec, void *pop_buffer);

#endif /* __BBI86_SCRIPTS_KCONFIG_TYPES_H */

#ifndef __BBI86_SCRIPTS_KCONFIG_TYPES_H
#define __BBI86_SCRIPTS_KCONFIG_TYPES_H

#include <stdint.h>
#include <stddef.h>

#define KCONFIG_FAT_POINTER_DEF(type)           \
    struct kconfig_fat_pointer_##type {         \
        size_t len;                             \
        type *buffer;                           \
    }

KCONFIG_FAT_POINTER_DEF(char);

#define KCONFIG_FAT_POINTER(type) struct kconfig_fat_pointer_##type

typedef struct {
    void **buffer; 
    size_t capacity;
    size_t length;
} kconfig_vector_t;

#define KCONFIG_VECTOR_INDEX(vector, index) (*(vector.buffer + index))
#define KCONFIG_VECTOR_DESTROY(vector) free(vector.buffer)

int kconfig_vector_new(kconfig_vector_t *vector);
int kconfig_vector_push(kconfig_vector_t *vector, void *item);
void *kconfig_vector_pop(kconfig_vector_t *vector);

#endif /* __BBI86_SCRIPTS_KCONFIG_TYPES_H */

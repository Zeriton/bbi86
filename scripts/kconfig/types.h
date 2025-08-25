#ifndef __BBI86_SCRIPTS_KCONFIG_TYPES_H
#define __BBI86_SCRIPTS_KCONFIG_TYPES_H

#include <stdint.h>

#define KCONFIG_FAT_POINTER_DEF(type)           \
    struct kconfig_fat_pointer_##type {         \
        size_t len;                             \
        type *buffer;                           \
    }

KCONFIG_FAT_POINTER_DEF(char);

#define KCONFIG_FAT_POINTER(type) struct kconfig_fat_pointer_##type

#endif /* __BBI86_SCRIPTS_KCONFIG_TYPES_H */

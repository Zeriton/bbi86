#ifndef __BBI86_SCRIPTS_KCONFIG_TOKEN_H
#define __BBI86_SCRIPTS_KCONFIG_TOKEN_H

#include "types.h"

typedef enum {
    /* Values */
    IDENT = 0,
    STRING,
    
    HEX,
    DECIMAL,

    /* Keywords */
    KEYWORD_MAINMENU,
    KEYWORD_CONFIG,
    KEYWORD_DEFAULT,

    /* Types */
    TYPE_HEX,
    TYPE_INT,

    END_OF_FILE,
} kconfig_token_type_t;

typedef struct {
    KCONFIG_FAT_POINTER(char) value;
    kconfig_token_type_t type;
} kconfig_token_t;

#endif /* __BBI86_SCRIPTS_KCONFIG_TOKEN_H */

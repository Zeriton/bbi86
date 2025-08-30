#include "types.h"

errorv_t kconfig_vector_push(kconfig_vector_t *vec, void *item) {
    if (vec->len == vec->cap) {
        size_t new_cap = vec->cap * 2; /* Growth rate of x2 */
        void *new_buffer = realloc(vec->buffer, new_cap);
        if (!new_buffer) {
            fprintf(stderr, "error: vector is too possibly fat\r\n");
            return 1;
        }
        vec->buffer = new_buffer;
        vec->cap = new_cap;
    }

    memcpy(vec->buffer + vec->item_size * vec->len, item, vec->item_size);
    vec->len += 1;

    return 0;
}

errorv_t kconfig_vector_pop(kconfig_vector_t *vec, void *pop_buffer) {
    if (vec->len == 0) {
        fprintf(stderr, "error: vector is milked clean, you cannot possibly strive for more\r\n");
        return 1;
    }

    vec->len -= 1;
    memcpy(pop_buffer, vec->buffer + vec->len * vec->item_size, vec->item_size);
    
    return 0;
}

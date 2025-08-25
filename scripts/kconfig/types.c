#include "types.h"

#include <stdio.h>
#include <stdlib.h>

int kconfig_vector_new(kconfig_vector_t *vector) {
    size_t capacity = 4;
    
    /* Allocate the buffer */
    void **buffer = malloc(sizeof(void *) * capacity);
    if (!buffer) {
        fprintf(stderr, "error: failed to allocate buffer for vector\r\n");
        return -1;
    }
    vector->buffer = buffer;

    /* Fill out the rest */
    vector->capacity = capacity;
    vector->length = 0;
    
    return 0;
}

int kconfig_vector_push(kconfig_vector_t *vector, void *item) {
    /*
      If the length reaches the vector capacity upon push, then
      to be able to do any pushes further we just got to expand it.
      In this case we will use a growth factor of 2.
    */
    if (vector->length == vector->capacity) {
        vector->capacity *= 2;
        void **buffer = realloc(vector->buffer, vector->capacity);
        if (!buffer) {
            fprintf(stderr, "error: failed to allocate larger buffer for vector\r\n");
            return -1;
        }
        vector->buffer = buffer;
    }

    size_t new_length = vector->length;
    *(vector->buffer + new_length) = item;
    vector->length = new_length + 1;

    return 0;
}

void *kconfig_vector_pop(kconfig_vector_t *vector) {
    if (vector->length == 0) {
        fprintf(stderr, "error: cannot pop any further, vector milked clean\r\n");
        return NULL;
    }

    void *item = *(vector->buffer + vector->length - 1);
    vector->length -= 1;
    
    return item;
}

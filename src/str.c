/**
 * Copyright (c) 2022 aiocat
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "str.h"

struct str* str_new() {
    // create new str
    struct str* str = malloc(sizeof(struct str));
    str->capacity = sizeof(char) * STR_CAP_S;
    str->length = 0;
    str->memory = malloc(str->capacity);

    // check if null
    if (str->memory == NULL) {
        return NULL;
    }

    *str->memory = 0;
    return str;
}

uint8_t str_push(struct str* str, const char* cstr) {
    // read c-style string and append to str
    size_t length = 0;
    for (; cstr[length] != '\0'; length++) {
        // re-alloc if no memory avaible for next push
        size_t avaible_mem = str->capacity - str->length;
        if (avaible_mem <= 1) {
            str->capacity += sizeof(char) * STR_CAP_S;
            char* reallocted = realloc(str->memory, str->capacity);

            if (reallocted == NULL) {
                *(str->memory + (str->length)) = 0;
                return 0;
            }

            str->memory = reallocted;
        }
        
        // push character
        *(str->memory + (str->length++)) = cstr[length];
    }

    // set \0
    *(str->memory + (str->length)) = 0;
    return 1;
}

const char str_pop(struct str* str) {
    // check if string empty
    if (str_is_empty(str) == 1) {
        return 0;
    }

    const char variable = str->memory[str->length--];
    str->memory[str->length] = 0;

    return variable;
}

const char str_last(struct str* str) {
    // check if string empty
    if (str_is_empty(str) == 1) {
        return 0;
    }

    return str->memory[str->length - 1];
}

void str_free(struct str* str) {
    str->capacity = 0;
    str->length = 0;

    free(str->memory);
    free(str);
}

struct str* str_from(const char* cstr) {
    // create new str
    struct str* string = str_new();

    // check if null
    if (string == NULL) {
        return NULL;
    }

    // push string
    if (str_push(string, cstr) == 0) {
        return NULL;
    }

    return string;
}

uint8_t str_is_empty(const struct str* str) {
    if (str->length == 0) {
        return 1;
    } else {
        return 0;
    }
}

size_t str_length(const struct str* str) {
    return str->length;
}

size_t str_capacity(const struct str* str) {
    return str->capacity;
}
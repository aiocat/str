/**
 * Copyright (c) 2022 aiocat
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "str.h"

struct str* 
str_new() {
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

uint8_t
str_push(struct str* str, const char* cstr) {
    // read c-style string and append to str
    size_t length = 0;
    for (; cstr[length] != '\0'; length++) {
        size_t avaible_mem = str->capacity - str->length;

        if (avaible_mem <= 1) {
            str->capacity += STR_CAP_S;
            char* reallocted = realloc(str->memory, sizeof(char) * str->capacity);

            if (reallocted == NULL) {
                *(str->memory + (str->length)) = 0;
                return 0;
            }

            str->memory = reallocted;
        }
        
        // push character
        *(str->memory + (str->length++)) = cstr[length];
    }

    *(str->memory + (str->length)) = 0;
    return 1;
}

const char
str_pop(struct str* str) {
    str->length--;

    const char variable = str->memory[str->length];
    str->memory[str->length] = 0;

    return variable;
}

void
str_free(struct str* str) {
    str->capacity = 0;
    str->length = 0;
    
    free(str->memory);
    free(str);
}
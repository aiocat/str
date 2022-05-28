/**
 * Copyright (c) 2022 aiocat
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "str.h"

struct str* 
new_str() {
    // create new str
    struct str* str = malloc(sizeof(struct str));
    str->capacity = STR_CAP_S + 1;
    str->length = 0;
    str->memory = malloc(str->capacity);

    // check if null
    if (str->memory == NULL) {
        return NULL;
    }

    *str->memory = 0;
    return str;
}

void
push_cstr(struct str* str, const char* cstr) {
    // read c-style string and append to str
    size_t length = 0;
    for (; cstr[length] != '\0'; length++) {
        size_t avaible_mem = str->capacity - str->length;

        if (avaible_mem == 0 || avaible_mem == 1) {
            str->capacity += STR_CAP_S;
            str->memory = realloc(str->memory, str->capacity);
        }
        
        // push character
        strcpy(str->memory + (str->length++), &cstr[length]);
    }
}
// Copyright (c) 2022 aiocat
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef STR_H
#define STR_H

#include <stdint.h>
#include <stdlib.h>

// define string capacity size
#ifndef STR_CAP_S
#define STR_CAP_S 1024
#endif

// This struct is contains allocted memory, length and capacity.
struct str {
    char* memory; // for keeping string memory.
    size_t length; // for string length.
    size_t capacity; // for memory capacity.
};

// create new empty string. will return null if malloc fails.
struct str* 
str_new();

// push c-style string. will realloc if too big for struct. returns 1 (one) if function returns successfully, otherwise it will return 0 (zero).
uint8_t
str_push(struct str* str, const char* cstr);

// remove last string and return it
const char
str_pop(struct str* str);

// safely de-alloc string from memory. use this when all of the operations done.
void
str_free(struct str* str);

#endif /* STR_H */
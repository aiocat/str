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

// push c-style string. will realloc if too big for struct.
uint8_t
str_push(struct str* str, const char* cstr);

// removes last string and returns it
const char
str_pop(struct str* str);

#endif /* STR_H */
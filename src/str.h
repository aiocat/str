// Copyright (c) 2022 aiocat
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef STR_H
#define STR_H

#include <stdint.h>
#include <string.h>
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
new_str();

// push c-style string. will realloc if too big for struct.
void
push_str(struct str* str, const char* cstr);

#endif /* STR_H */
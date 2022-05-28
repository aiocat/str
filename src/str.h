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
    char* memory; // for string memory.
    size_t length; // for string length.
    size_t capacity; // for memory capacity.
};

// create new empty string. will return null if fails.
struct str* str_new();

// create string from c-style string. will return null if fails.
struct str* str_from(const char* cstr);

// push c-style string. will realloc if too big for struct. returns 1 (one) if function returns successfully, otherwise it will return 0 (zero).
uint8_t str_push(struct str* str, const char* cstr);

// remove last char and return it. returns \0 (zero) if string is empty.
const char str_pop(struct str* str);

// get last char and return it. returns \0 (zero) if string is empty.
const char str_last(struct str* str);

// safely de-alloc string from memory. use this when all of the operations done.
void str_free(struct str* str);

// check if string is empty. will return 1 (one) if empty, otherwise it will return 0 (zero).
uint8_t str_is_empty(const struct str* str);

// return string length. this operation is O(1).
size_t str_length(const struct str* str);

// return string capacity. this operation is O(1).
size_t str_capacity(const struct str* str);

#endif /* STR_H */
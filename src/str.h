// Copyright (c) 2022 aiocat
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef STR_H
#define STR_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// define string capacity size
#ifndef STR_CAP_S
#define STR_CAP_S 1024
#endif

#define _STR_BUF_S sizeof(char) * STR_CAP_S
#define _STR_S sizeof(struct str)

// This struct is contains allocted memory, length and capacity.
struct str
{
    size_t length;   // for string length.
    size_t capacity; // for memory capacity.
    char *memory;    // for string memory.
};

// create new empty string. will return null if fails.
struct str *str_new();

// create string from c-style string. will return null if fails.
struct str *str_from(const char *cstr);

// push c-style string. will realloc if too big for struct. returns 1 (one) if function returns successfully, otherwise it will return 0 (zero).
uint8_t str_push(struct str *str, const char *cstr);

// remove last char and return it. returns -1 if string is empty.
char str_pop(struct str *str);

// get last char and return it. returns -1 if string is empty.
char str_last(struct str *str);

// safely de-alloc string from memory. use this when all of the operations done.
void str_free(struct str *str);

// check if string is empty. will return 1 (one) if empty, otherwise it will return 0 (zero).
uint8_t str_is_empty(const struct str *str);

// return string length.
size_t str_length(const struct str *str);

// return string capacity.
size_t str_capacity(const struct str *str);

// get character by index and return it. will return -1 if fails.
char str_at(const struct str *str, size_t index);

// remove character in given index and return it. will return -1 if fails.
char str_remove_at(struct str *str, size_t index);

// find a character and return the index. will return -1 if fails.
char str_remove_at(struct str *str, size_t index);

#endif /* STR_H */
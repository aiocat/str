/**
 * Copyright (c) 2022 aiocat
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <stdio.h>
#include "../src/str.c"

int
main(void) {
    struct str* string = new_str();
    push_cstr(string, "asd");

    printf("string: %s\n", string->memory);
    printf("cap: %zu\n", string->capacity);
    printf("length: %zu\n", string->length);
}
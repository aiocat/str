/**
 * Copyright (c) 2022 aiocat
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <stdio.h>
#define STR_CAP_S 10
#include "../src/str.c"

#define debug(x)                        \
    printf("string: %s\n", x->memory);  \
    printf("cap: %zu\n", x->capacity);  \
    printf("length: %zu\n", x->length); \
    puts("----------------------------------------");

int main(void)
{
    struct str *string = str_from("  damn\t");
    debug(string)

    str_trim(string);
    debug(string)

    printf("index: %zu\n", (size_t)str_find(string, 'n'));

    str_free(string);
}
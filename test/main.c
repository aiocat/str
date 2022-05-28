/**
 * Copyright (c) 2022 aiocat
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <stdio.h>
#define STR_CAP_S 10
#include "../src/str.c"

#define debug(x) \
    printf("string: %s\n", x->memory); \
    printf("cap: %zu\n", x->capacity); \
    printf("length: %zu\n", x->length); \
    puts("----------------------------------------"); \

int main(void) {
    struct str* string = str_from("damn");
    debug(string)

    str_remove_at(string, 2);
    debug(string)

    str_push(string, "\ndeneme osuruk");
    debug(string)

    str_free(string);
}
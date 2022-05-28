/**
 * Copyright (c) 2022 aiocat
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "str.h"

struct str *str_new()
{
    // create new str
    struct str *str = malloc(_STR_S);

    // check if null
    if (str == NULL)
        return NULL;

    str->capacity = _STR_BUF_S;
    str->length = 0;
    str->memory = malloc(str->capacity);

    // check if null
    if (str->memory == NULL)
    {
        free(str);
        return NULL;
    }

    *str->memory = 0;
    return str;
}

uint8_t str_push(struct str *str, const char *cstr)
{
    // read c-style string and append to str
    for (size_t length = 0; cstr[length] != '\0'; length++)
    {
        // re-alloc if no memory avaible for next push
        size_t avaible_mem = str->capacity - str->length;
        if (avaible_mem <= 1)
        {
            str->capacity += _STR_BUF_S;
            str->memory = realloc(str->memory, str->capacity);

            if (str->memory == NULL)
            {
                str->memory[str->length] = 0;
                return 0;
            }
        }

        // push character
        str->memory[str->length++] = cstr[length];
    }

    // set \0
    str->memory[str->length] = 0;
    return 1;
}

char str_pop(struct str *str)
{
    // check if string empty
    if (str->length == 0)
        return -1;

    char variable = str->memory[--str->length];
    str->memory[str->length] = 0;

    return variable;
}

char str_last(struct str *str)
{
    // check if string empty
    if (str->length == 0)
        return -1;

    return str->memory[str->length - 1];
}

void str_free(struct str *str)
{
    str->capacity = 0;
    str->length = 0;
    free(str->memory);
    free(str);
}

struct str *str_from(const char *cstr)
{
    // create new str
    struct str *string = str_new();

    // check if null
    if (string == NULL)
        return NULL;

    // push string
    if (str_push(string, cstr) == 0)
        return NULL;

    return string;
}

void str_reverse(struct str *str)
{
    for (size_t index = 0; index < str->length / 2; index++)
    {
        str->memory[index] ^= str->memory[str->length - index - 1];
        str->memory[str->length - index - 1] ^= str->memory[index];
        str->memory[index] ^= str->memory[str->length - index - 1];
    }
}

void str_trim(struct str *str)
{
    char *temp = str->memory;

    while (isspace(temp[str->length - 1]))
        temp[--str->length] = 0;
    while (*temp && isspace(*temp))
        ++temp, --str->length;

    memmove(str->memory, temp, str->length + 1);
}

uint8_t str_is_empty(const struct str *str)
{
    return str->length == 0;
}

char str_at(const struct str *str, size_t index)
{
    // check index size
    if (index >= str->length)
        return -1;

    return str->memory[index];
}

char str_remove_at(struct str *str, size_t index)
{
    char will_deleted = str_at(str, index);

    if (will_deleted == 0)
        return -1;

    // remove index and decrease length
    memmove(&str->memory[index], &str->memory[index + 1], str->length - index);
    str->length--;

    return will_deleted;
}

size_t str_length(const struct str *str)
{
    return str->length;
}

size_t str_capacity(const struct str *str)
{
    return str->capacity;
}
/*
** EPITECH PROJECT, 2023
** strlen_array
** File description:
** count line in array
*/

#include <stddef.h>

size_t arraylen(const char * const * const array)
{
    size_t len = 0;

    while (array[len])
        ++len;
    return len;
}

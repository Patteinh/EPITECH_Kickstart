/*
** EPITECH PROJECT, 2024
** strlen_array
** File description:
** count line in array
*/

#include <stddef.h>

size_t arraylen(const char *const array[])
{
    size_t len = 0;

    while (array[len])
        ++len;
    return len;
}

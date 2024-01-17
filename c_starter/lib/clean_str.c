/*
** EPITECH PROJECT, 2024
** clean_str.c
** File description:
** remove unwanted characters of string
*/

#include <string.h>
#include <stdlib.h>
#include <stddef.h>

char *clean_str(const char * const str, const char * const delim)
{
    size_t len = 0;
    const char *s = str;
    char *new_str = NULL;
    char *t = NULL;

    for (; *s; s++)
        if (!strchr(delim, *s))
            len++;
    new_str = malloc(len + 1);
    if (!new_str)
        return NULL;
    t = new_str;
    for (s = str; *s; s++)
        if (!strchr(delim, *s))
            *t++ = *s;
    *t = '\0';
    return new_str;
}

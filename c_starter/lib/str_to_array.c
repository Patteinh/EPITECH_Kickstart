/*
** EPITECH PROJECT, 2024
** str_to_array.c
** File description:
** split str to array with delim
*/

#include <string.h>
#include <stdlib.h>
#include <stddef.h>

char **str_to_array(const char * const str, const char * const delim)
{
    char **array = NULL;
    size_t nb_words = 0;

    for (int i = 0; str[i];) {
        for (; strchr((const char *)delim, str[i]) && str[i]; i++);
        if (!str[i])
            break;
        nb_words++;
        int j = i;
        for (; !strchr((const char *)delim, str[j]) && str[j]; j++);
        array = realloc(array, sizeof(*array) * (nb_words + 1));
        array[nb_words - 1] = strndup(&str[i], j - i);
        array[nb_words] = NULL;
        i = j;
    }
    return array;
}

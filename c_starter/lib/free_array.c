/*
** EPITECH PROJECT, 2023
** free_array
** File description:
** free array
*/

#include <stdlib.h>

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    if (array)
        free(array);
}

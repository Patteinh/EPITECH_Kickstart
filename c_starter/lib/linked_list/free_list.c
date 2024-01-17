/*
** EPITECH PROJECT, 2024
** free_list.c
** File description:
** free linked list
*/

#include <stdlib.h>

#include "lib.h"

void free_list(list_t *l)
{
    list_t *tmp;

    while (l) {
        tmp = l->next;
        free(l);
        l = tmp;
    }
}

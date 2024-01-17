/*
** EPITECH PROJECT, 2024
** listlen.c
** File description:
** get size of linked list
*/

#include "lib.h"

size_t listlen(const list_t *l)
{
    size_t len = 0;

    while (l) {
        l = l->next;
        len++;
    }
    return len;
}

/*
** EPITECH PROJECT, 2024
** get_node.c
** File description:
** get node of a linked list
*/

#include "lib.h"

list_t *get_front_node(list_t *l)
{
    return l;
}

list_t *get_back_node(list_t *l)
{
    if (!l)
        return NULL;
    while (l->next)
        l = l->next;
    return l;
}

list_t *get_node_at_position(list_t *l, const size_t pos)
{
    size_t length = listlen(l);

    if (!l || pos >= length)
        return NULL;
    if (pos == 0)
        return get_front_node(l);
    if (pos == length - 1)
        return get_back_node(l);
    for (size_t i = 0; i < pos && l; i++, l = l->next);
    return l;
}

/*
** EPITECH PROJECT, 2024
** delete_node.c
** File description:
** delete node of a linked list
*/

#include <stdlib.h>

#include "lib.h"

int del_front_node(list_t **l)
{
    if (!(*l))
        return FAILURE;
    list_t *tmp = *l;
    *l = (*l)->next;
    free(tmp);
    tmp = NULL;
    return SUCCESS;
}

int del_back_node(list_t **l)
{
    size_t length = listlen(*l);

    if (!(*l))
        return FAILURE;
    if (length == 1)
        return del_front_node(l);
    list_t *tmp = *l;
    while (tmp->next->next)
        tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
    return SUCCESS;
}

int del_node_at_position(list_t **l, const size_t pos)
{
    size_t length = listlen(*l);

    if (!(*l) || pos > length)
        return FAILURE;
    if (pos == 0)
        return del_front_node(l);
    if (pos == length)
        return del_back_node(l);
    list_t *tmp = *l;
    list_t *to_delete;
    for (size_t i = 0; i < pos; i++)
        tmp = tmp->next;
    to_delete = tmp->next;
    tmp->next = to_delete->next;
    free(to_delete);
    to_delete = NULL;
    return SUCCESS;
}

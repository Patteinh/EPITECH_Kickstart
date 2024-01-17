/*
** EPITECH PROJECT, 2024
** add_node.c
** File description:
** add node of a linked list
*/

#include <stdlib.h>
#include <stdio.h>

#include "lib.h"

list_t *create_node(void)
{
    list_t *new_node = malloc(sizeof(list_t));
    CERROR(!new_node, "malloc");
    new_node->next = NULL;
    return new_node;
}

int add_first_node(list_t **l)
{
    if (*l)
        return FAILURE;
    *l = create_node();
    return SUCCESS;
}

int add_front_node(list_t **l)
{
    list_t *new_node = create_node();
    new_node->next = *l;
    *l = new_node;
    return SUCCESS;
}

int add_back_node(list_t **l)
{
    if (!(*l))
        return add_first_node(l);
    list_t *tmp = *l;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = create_node();
    return SUCCESS;
}

int add_node_at_position(list_t **l, const size_t pos)
{
    size_t length = listlen(*l);

    if (pos > length)
        return FAILURE;
    if (pos == 0)
        return add_front_node(l);
    if (pos == length)
        return add_back_node(l);
    list_t *tmp = *l;
    for (size_t i = 0; i < pos - 1; i++)
        tmp = tmp->next;
    list_t *new_node = create_node();
    new_node->next = tmp->next;
    tmp->next = new_node;
    return SUCCESS;
}

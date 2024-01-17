/*
** EPITECH PROJECT, 2024
** lib.h
** File description:
** lib.h
*/

#pragma once

#include <stddef.h>

#define PERROR(e) fprintf(stderr, "Error: %s\n", e), exit(ERROR);
#define CERROR(is_error, e) ((is_error) ? (perror(e), exit(ERROR)) : SUCCESS)
#define M_UNUSED __attribute__((unused))

typedef struct list_s {
    struct list_s *next;
} list_t;

size_t arraylen(const char * const * const array);
char *clean_str(const char * const str, const char * const delim);
char **str_to_array(const char * const str, const char * const delim);
void free_array(char **array);

int add_first_node(list_t **l);
int add_front_node(list_t **l);
int add_back_node(list_t **l);
int add_node_at_position(list_t **l, const size_t pos);
list_t *get_front_node(list_t *l);
list_t *get_back_node(list_t *l);
list_t *get_node_at_position(list_t *l, const size_t pos);
int del_front_node(list_t **l);
int del_back_node(list_t **l);
int del_node_at_position(list_t **l, const size_t pos);
size_t listlen(const list_t *l);
void free_list(list_t *l);

static const int SUCCESS = 0;
static const int FAILURE = -1;
static const int ERROR = 84;

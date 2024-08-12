/*
** EPITECH PROJECT, 2024
** push_to_list
** File description:
** add a new element to a linked list
*/

#include "../lib/my/my.h"
#include "linked_list.h"

void push_to_end_of_list(linked_list_t **list, void *data)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    linked_list_t *tmp = *list;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if (*list == NULL) {
        *list = new_node;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
    new_node->prev = tmp;
}

void push_to_start_of_list(linked_list_t **list, void *data)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *list;
    *list = new_node;
}

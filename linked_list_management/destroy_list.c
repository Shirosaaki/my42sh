/*
** EPITECH PROJECT, 2024
** destroy_list
** File description:
** function to destroy a linked list
*/

#include "../lib/my/my.h"
#include "linked_list.h"

void destroy_list(linked_list_t **list)
{
    linked_list_t *tmp = *list;
    linked_list_t *prev = tmp;

    for (; tmp != NULL;){
        tmp = tmp->next;
        free(prev);
        prev = tmp;
    }
    free(tmp);
}

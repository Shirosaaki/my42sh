/*
** EPITECH PROJECT, 2023
** delete_in_list
** File description:
** deletes all nodes of a linked list containing data equal to the given one
*/

#include "../lib/my/my.h"
#include "linked_list.h"

int compare_function_str(void *data, void const *ref)
{
    if (my_strcmp((char *)data, (char *)ref) == 0)
        return 1;
    return 0;
}

int compare_function_char(void *data, void const *ref)
{
    if (*(char *)data == *(char *)ref)
        return 1;
    return 0;
}

int compare_function_int(void *data, void const *ref)
{
    if (*(int *)data == *(int *)ref)
        return 1;
    return 0;
}

void delete_in_list(linked_list_t **list, void const *ref, int (*cmp_fct)())
{
    linked_list_t *prev = NULL;
    linked_list_t *curr = *list;

    while (curr != NULL) {
        if (cmp_fct(curr->data, ref) == 1)
            break;
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
        return;
    if (prev == NULL)
        *list = curr->next;
    else
        prev->next = curr->next;
    free(curr);
}

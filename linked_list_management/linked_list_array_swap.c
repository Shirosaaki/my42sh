/*
** EPITECH PROJECT, 2024
** linked list array swap
** File description:
** function to swap linked lists and str array
*/

#include "../lib/my/my.h"
#include "linked_list.h"

char **linked_list_to_str_array(linked_list_t *list)
{
    char **array;
    linked_list_t *tmp = list;
    linked_list_t *tmpc = list;
    int len_list;

    for (len_list = 0; tmpc != NULL; len_list++)
        tmpc = tmpc->next;
    array = malloc(sizeof(char *) * (len_list + 1));
    array[len_list] = NULL;
    for (int i = 0; tmp != NULL; i++){
        array[i] = my_strdup((char *)tmp->data);
        tmp = tmp->next;
    }
    return array;
}

void str_array_to_linked_list(char **array, linked_list_t **list)
{
    char *zfeugy;

    for (int i = 0; array[i] != NULL; i++){
        zfeugy = my_strdup(array[i]);
        push_to_end_of_list(list, zfeugy);
    }
}

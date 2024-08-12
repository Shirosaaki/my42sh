/*
** EPITECH PROJECT, 2024
** Unalias
** File description:
** no
*/

#include "include/my.h"

void next_unaliast(alias_t *current, alias_t *previous, my_shell_t *my_shell)
{
    if (previous == NULL)
        my_shell->alias_list = current->next;
    else
        previous->next = current->next;
}

void unalias(char *name, my_shell_t *my_shell)
{
    alias_t *current = my_shell->alias_list;
    alias_t *previous = NULL;

    while (current != NULL){
        if (my_strcmp(current->name, name) == 0) {
            next_unaliast(current, previous, my_shell);
            free(current->name);
            free(current->command);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

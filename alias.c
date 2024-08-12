/*
** EPITECH PROJECT, 2024
** Alias
** File description:
** no
*/

#include "include/my.h"

void print_com_alias(alias_t *alias_list, char *name)
{
    alias_t *current = alias_list;

    while (current != NULL){
        if (current->name)
            printf("%s\n", current->command);
        current = current->next;
    }
}

void print_alias(alias_t *alias_list)
{
    alias_t *current = alias_list;

    while (current != NULL){
        printf("%s\t(%s)\n", current->name, current->command);
        current = current->next;
    }
}

int in_alias(char *name, alias_t *alias_list)
{
    alias_t *current = alias_list;

    while (current != NULL){
        if (my_strcmp(current->name, name) == 0)
            return 1;
        current = current->next;
    }
    return 0;
}

void add_alias(char *name, char *command, my_shell_t *my_shell)
{
    alias_t *new = malloc(sizeof(alias_t));
    alias_t *current = my_shell->alias_list;

    new->name = my_strdup(name);
    new->command = my_strdup(command);
    new->next = NULL;
    if (current == NULL) {
        my_shell->alias_list = new;
        return;
    }
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new;
}

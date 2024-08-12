/*
** EPITECH PROJECT, 2024
** Command with alias
** File description:
** no
*/

#include "include/my.h"

void com_unalias(my_shell_t *my_shell)
{
    char **com = my_str_to_word_array(my_shell->com, ' ');

    if (my_tablen(com) < 2) {
        printf("unalias : Too few arguments\n");
        return;
    }
    unalias(com[1], my_shell);
}

void alias_spe_next(char **tab, char *name,
    char *command, my_shell_t *my_shell)
{
    char *new = " ";
    int i = 3;

    while (alias_cmp(tab[i]) != 1) {
        command = my_strcat(command, " ");
        command = my_strcat(command, tab[i]);
        i++;
    }
    while (tab[i] != NULL) {
        new = my_strcat(new, tab[i]);
        new = my_strcat(new, " ");
        i++;
    }
    free(tab);
    add_alias(name, command, my_shell);
    continue_alias(my_shell, new);
}

void alias_spe(char *com, my_shell_t *my_shell)
{
    char *alias = "alias ";
    char *command;
    char *name;
    char **tab = my_str_to_word_array(com, ' ');

    name = my_strdup(tab[1]);
    command = my_strdup(tab[2]);
    if (tab[3] != NULL) {
        alias_spe_next(tab, name, command, my_shell);
        return;
    }
    add_alias(name, command, my_shell);
    free(tab);
}

void com_alias(my_shell_t *my_shell)
{
    char **com = my_str_to_word_array(my_shell->com, ' ');
    alias_t *current;

    if (com[1] == NULL) {
        print_alias(my_shell->alias_list);
        return;
    }
    if (com[2] == NULL && in_alias(com[1], my_shell->alias_list) == 1)
        print_com_alias(my_shell->alias_list, com[1]);
    if (my_tablen(com) > 2)
        alias_spe(my_shell->com, my_shell);
}

void my_alias(my_shell_t *my_shell)
{
    char **com = my_str_to_word_array(my_shell->com, ' ');

    if (my_strcmp("alias", com[0]) == 0) {
        com_alias(my_shell);
        return;
    } else if (my_strcmp("unalias", com[0]) == 0) {
        com_unalias(my_shell);
        return;
    }
}

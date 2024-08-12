/*
** EPITECH PROJECT, 2024
** Execute alias
** File description:
** no
*/

#include "include/my.h"


char *get_alias_command(char *name, alias_t *alias_list)
{
    alias_t *current = alias_list;

    while (current != NULL) {
        if (my_strcmp(current->name, name) == 0){
            return current->command;
        }
        current = current->next;
    }
    return NULL;
}

int execute_alias(char *command, alias_t *alias_list, my_shell_t *my_shell)
{
    char **com = my_str_to_word_array(command, ' ');
    char *alias_command = NULL;

    if (com[0] == NULL)
        return 0;
    alias_command = get_alias_command(com[0], alias_list);
    if (alias_command == NULL)
        return 0;
    if (alias_command != NULL)
        com = my_str_to_word_array(alias_command, ' ');
    exec(com, my_shell);
    return 1;
}

int get_print(my_shell_t *my_shell)
{
    if (my_strcmp(my_shell->com, "env") == 0) {
        print_list(my_shell->my_env);
        return 1;
    }
    if (execute_alias(my_shell->com, my_shell->alias_list, my_shell) == 1)
        return 1;
    if (my_strstr(my_shell->com, "alias") != -1) {
        my_alias(my_shell);
        return 1;
    }
    return 0;
}

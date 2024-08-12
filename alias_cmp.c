/*
** EPITECH PROJECT, 2024
** Alias cmp
** File description:
** no
*/

#include "include/my.h"

int alias_cmp(char *com)
{
    if (com == NULL)
        return (1);
    if (my_strcmp(com, ">>") == 0 || my_strcmp(com, "<<") == 0)
        return (1);
    if (my_strcmp(com, "&&") == 0)
        return (1);
    if (my_strcmp(com, "||") == 0)
        return (1);
    if (my_strcmp(com, "|") == 0)
        return (1);
    if (my_strcmp(com, ";") == 0)
        return (1);
    if (my_strcmp(com, ">") == 0 || my_strcmp(com, "<") == 0)
        return (1);
    return (0);
}

void continue_alias(my_shell_t *my_shell, char *new)
{
    if (new[0] == ' ')
        return;
    my_shell->com = my_strdup(new);
    my_shell->argvs = my_str_to_word_array(new, ' ');
    my_shell->len = my_tablen(my_shell->argvs);
    exec(my_shell->argvs, my_shell);
}

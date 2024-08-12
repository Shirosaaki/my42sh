/*
** EPITECH PROJECT, 2024
** choose_env_print
** File description:
** choose_env_print
*/
#include "include/my.h"

char *rm_first_space(char *str)
{
    char *new = malloc(sizeof(char) * my_strlen(str));
    int i = 0;
    int j = 0;

    for (; str[i] == ' '; i++);
    for (; str[i] != '\0'; i++) {
        new[j] = str[i];
        j++;
    }
    new[j] = '\0';
    free(str);
    return new;
}

void next_for_loop(my_shell_t *my_shell)
{
    for (my_env_t *tmp = my_shell->my_env; tmp != NULL; tmp = tmp->next)
        if (my_strcmp(tmp->name, "PATH") == 0) {
            my_shell->path = malloc(1);
            free(my_shell->path);
            my_shell->path = my_str_to_word_array(tmp->value, ':');
        }
}

int exec_semicolon(char **com, my_shell_t *my_shell)
{
    int r = 0;

    for (int i = 0; com[i] != NULL; i++)
        r = exec(my_str_to_word_array(com[i], ' '), my_shell);
    free_tab(com);
    return r;
}

int exec_pipe(char **tab, my_shell_t *my_shell)
{
    int fd[2];
    int save = dup(STDOUT_FILENO);
    int save_in = dup(STDIN_FILENO);
    int pid;
    int r = 0;

    for (int i = 0; tab[i + 1] != NULL; i++) {
        pipe(fd);
        pid = fork();
        handle_pipe(fd, pid, tab[i], my_shell);
    }
    r = exec(my_str_to_word_array(tab[my_tablen(tab) - 1], ' '), my_shell);
    dup2(save, STDOUT_FILENO);
    dup2(save_in, STDIN_FILENO);
    close(save);
    close(save_in);
    free_tab(tab);
    return r;
}

int nex_to_loop(my_shell_t *my_shell)
{
    char **tab;
    int result = 0;

    if (my_find_c(my_shell->com, ';') != -1) {
        tab = my_str_to_word_array(my_shell->com, ';');
        for (int i = 0; tab[i] != NULL; i++) {
            my_shell->com = tab[i];
            result = nex_to_loop(my_shell);
        }
        return result;
    }
    result = handle_special_commands(my_shell);
    if (result != -1)
        return result;
    if (is_glob_pattern(my_str_to_word_array(my_shell->com, ' ')) != 0)
        return my_glob(my_shell);
    return exec(my_str_to_word_array(my_shell->com, ' '), my_shell);
}

/*
** EPITECH PROJECT, 2024
** exev
** File description:
** exec
*/
#include "include/my.h"

int handle_special_commands(my_shell_t *my_shell)
{
    if (my_find_c(my_shell->com, '|') != -1)
        return exec_pipe(my_str_to_word_array(my_shell->com, '|'), my_shell);
    if (my_find_c(my_shell->com, '>') != -1)
        return exec_redirection(my_str_to_word_array(my_shell->com, '>'),
            my_shell);
    if (my_find_c(my_shell->com, '<') != -1)
        return exec_redirection_g(my_str_to_word_array(my_shell->com, '<'),
            my_shell);
    if (my_find_c(my_shell->com, '&') != -1 &&
        my_shell->com[my_find_c(my_shell->com, '&') + 1] == '&')
        return exec_semicolon(my_str_to_word_array(my_shell->com, '&'),
            my_shell);
    return -1;
}

void handle_pipe(int *fd, int pid, char *tab_i, my_shell_t *my_shell)
{
    if (pid == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        exec(my_str_to_word_array(tab_i, ' '), my_shell);
        exit(0);
    } else {
        waitpid(pid, NULL, 0);
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
    }
}

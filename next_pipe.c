/*
** EPITECH PROJECT, 2024
** pipe
** File description:
** pipe
*/
#include "include/my.h"

int other_other_exec_redirection_g(char **com, my_shell_t *my_shell,
    commandes_t *commande, int length)
{
    int fd;
    int save = dup(STDIN_FILENO);
    int pid;

    fd = open("redi", O_CREAT | O_WRONLY, 0666);
    for (; commande->next != NULL; commande = commande->next)
        dprintf(fd, "%s\n", commande->com);
    close(fd);
    fd = open("redi", O_RDONLY);
    pid = fork();
    if (pid == 0) {
        dup2(fd, STDIN_FILENO);
        close(fd);
        exec(my_str_to_word_array(com[0], ' '), my_shell);
    } else {
        waitpid(pid, NULL, 0);
        dup2(save, STDIN_FILENO);
        close(save);
    }
    free_tab(com);
}

int other_exec_redirection_g(char **com, my_shell_t *my_shell)
{
    commandes_t *commande = malloc(sizeof(commandes_t));
    commandes_t *tmp = commande;
    char *tmp_com = NULL;
    size_t len = 0;
    int length = 0;

    while (1) {
        printf("? ");
        tmp_com = my_get_line(tmp_com, my_shell);
        if (my_strcmp(tmp_com, com[1]) == 0)
            break;
        tmp->com = malloc(sizeof(char) * (my_strlen(tmp_com) + 1));
        tmp->com = my_strcpy(tmp->com, tmp_com);
        tmp->next = malloc(sizeof(commandes_t));
        tmp = tmp->next;
        length++;
    }
    tmp->next = NULL;
    return other_other_exec_redirection_g(com, my_shell, commande, length);
}

int exec_redirection_g(char **com, my_shell_t *my_shell)
{
    int fd;
    int save = dup(STDIN_FILENO);
    int pid;

    com[1] = rm_first_space(com[1]);
    if (my_shell->com[my_find_c(my_shell->com, '<') + 1] == '<')
        return other_exec_redirection_g(com, my_shell);
    fd = open(com[1], O_RDONLY);
    pid = fork();
    if (pid == 0) {
        dup2(fd, STDIN_FILENO);
        close(fd);
        exec(my_str_to_word_array(com[0], ' '), my_shell);
    } else {
        waitpid(pid, NULL, 0);
        dup2(save, STDIN_FILENO);
        close(save);
    }
    free_tab(com);
    return 0;
}

int next_exec_redirection(int pid, int save, int fd)
{
    waitpid(pid, NULL, 0);
    close(save);
    close(fd);
    dup2(save, STDOUT_FILENO);
}

int exec_redirection(char **com, my_shell_t *my_shell)
{
    int fd;
    int save = dup(STDOUT_FILENO);
    int pid;

    com[1] = rm_first_space(com[1]);
    if (my_shell->com[my_find_c(my_shell->com, '>') + 1] == '>')
        fd = open(com[1], O_CREAT | O_WRONLY | O_APPEND, 0666);
    else
        fd = open(com[1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
    pid = fork();
    if (pid == 0) {
        dup2(fd, STDOUT_FILENO);
        close(fd);
        exit(exec(my_str_to_word_array(com[0], ' '), my_shell));
    } else
        next_exec_redirection(pid, save, fd);
    free_tab(com);
    return 0;
}

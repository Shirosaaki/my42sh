/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "include/my.h"

void disable_raw_mode(void)
{
    struct termios term;

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;
    term.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    printf("\x1B[0m");
    exit(0);
}

int pars(char **argvs, char **path, char **env)
{
    char *tmp = NULL;
    int r = -1;

    if (my_strcmp(argvs[0], "cd") == 0)
        return 50;
    if (my_strcmp(argvs[0], "cd-") == 0)
        return 53;
    if (my_strcmp(argvs[0], "setenv") == 0)
        return 51;
    if (my_strcmp(argvs[0], "unsetenv") == 0)
        return 52;
    if (my_strcmp(argvs[0], "history") == 0)
        return 54;
    for (int i = 0; path != NULL && path[i] != NULL && r == -1; i++) {
        tmp = my_strcat(path[i], "/");
        tmp = my_strcat(tmp, argvs[0]);
        r = execve(tmp, argvs, env);
    }
    return r;
}

void print_shell(char **com, size_t len, my_shell_t *my_shell)
{
    if (isatty(STDIN_FILENO) == 1)
        printf("\x1B[36m%s $> ", getcwd(NULL, 0));
    *com = my_get_line(*com, my_shell);
}

void exec_start(my_shell_t *my_shell)
{
    int fd = open(".42shrc", O_RDONLY);
    struct stat file_stat;
    int r = 0;
    int stat = 0;
    char *line = NULL;
    char **tab = NULL;

    if (fd == -1)
        return;
    fstat(fd, &file_stat);
    line = (char *)malloc(file_stat.st_size + 1);
    r = read(fd, line, file_stat.st_size);
    line[file_stat.st_size] = '\0';
    tab = my_str_to_word_array(line, '\n');
    for (int i = 0; tab[i] != NULL; i++) {
        my_shell->com = rm_last_n(tab[i]);
        if (get_print(my_shell) == 0)
            nex_to_loop(my_shell);
    }
    close(fd);
    free_tab(tab);
    free(line);
}

int save_history(linked_list_t **history)
{
    int fd = open(".42sh_history", O_CREAT | O_WRONLY, 0666);

    if (fd == -1)
        return 84;
    for (linked_list_t *tmp = *history; tmp != NULL; tmp = tmp->next){
        write(fd, ((history_t *)(tmp->data))->command, my_strlen(
        ((history_t *)(tmp->data))->command));
        write(fd, "\n", 1);
    }
    close(fd);
    return 0;
}

int get_old_history(my_shell_t *my_shell)
{
    int fd = open(".42sh_history", O_RDONLY);
    struct stat file_stat;
    int r = 0;
    char *line = NULL;
    char **tab = NULL;

    if (fd == -1)
        return 84;
    fstat(fd, &file_stat);
    line = (char *)malloc(file_stat.st_size + 1);
    r = read(fd, line, file_stat.st_size);
    line[file_stat.st_size] = '\0';
    tab = my_str_to_word_array(line, '\n');
    for (int i = 0; tab[i] != NULL; i++)
        add_to_history(&(my_shell->history), my_strdup(tab[i]), time(NULL));
    close(fd);
    free_tab(tab);
    free(line);
    return 0;
}

int loop(my_shell_t my_shell)
{
    my_shell.old_pwd = getcwd(NULL, 0);
    my_shell.len = 0;
    while (1) {
        if (my_shell.my_env != NULL)
            next_for_loop(&my_shell);
        print_shell(&my_shell.com, my_shell.len, &my_shell);
        if (my_strcmp(my_shell.com, "exit") == 0)
            return save_history(&(my_shell.history));
        if (get_print(&my_shell) == 0)
            nex_to_loop(&my_shell);
        if (strncmp(my_shell.com, "history", 7) != 0)
            add_to_history(&(my_shell.history), my_strdup(my_shell.com),
            time(NULL));
    }
    free_list(my_shell.my_env);
    free(my_shell.old_pwd);
    free_tab(my_shell.path);
    free(my_shell.com);
    return 0;
}

int main(int ac, char **av, char **env)
{
    char *com = "\n";
    my_shell_t my_shell;
    char **tab = NULL;
    my_shell.history = NULL;

    if (env[0] != NULL) {
        tab = my_str_to_word_array(env[0], '=');
        my_shell.my_env = init_list(tab[0], tab[1]);
        free(tab);
        for (int i = 1; env[i] != NULL; i++) {
            tab = my_str_to_word_array(env[i], '=');
            my_shell.my_env = my_setenv(my_shell.my_env, tab[0], tab[1], 0);
            free(tab);
        }
    }
    my_shell.com = com;
    my_shell.env = env;
    next_for_loop(&my_shell);
    exec_start(&my_shell);
    get_old_history(&my_shell);
    signal(SIGINT, handle_sigint);
    my_shell.index = get_history_len(my_shell.history) + 1;
    loop(my_shell);
    disable_raw_mode();
}

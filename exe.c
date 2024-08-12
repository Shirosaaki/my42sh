/*
** EPITECH PROJECT, 2024
** exe
** File description:
** exe
*/
#include "include/my.h"

int next_next_next_exec(char **argvs, my_shell_t *my_shell, int r)
{
    if (WEXITSTATUS(r) == 53)
        my_cd(argvs, my_shell->path, &my_shell->old_pwd);
    if (WEXITSTATUS(r) == 54){
        add_to_history(&(my_shell->history), my_strdup(my_shell->com),
        time(NULL));
        history(my_shell->history, argvs);
    }
}

int next_next_exec(char **argvs, my_shell_t *my_shell, int r)
{
    if (WEXITSTATUS(r) == 51) {
        if (my_tablen(argvs) > 3) {
            printf("setenv: Too many arguments.\n");
            return 1;
        }
        if (argvs[1] != NULL)
            my_shell->my_env = my_setenv(my_shell->my_env, argvs[1],
                argvs[2], 1);
        else
            print_list(my_shell->my_env);
    }
    if (WEXITSTATUS(r) == 52) {
        if (argvs[1] != NULL)
            my_shell->my_env = unsetenv_multi(my_shell->my_env, argvs);
        else
            printf("unsetenv: Too few arguments.\n");
    }
    if (WEXITSTATUS(r) == 53 || WEXITSTATUS(r) == 54)
        next_next_next_exec(argvs, my_shell, r);
}

int next_exec(char **argvs, my_shell_t *my_shell, int r, int pid)
{
    if (WEXITSTATUS(r) == 50 || WEXITSTATUS(r) == 51 || WEXITSTATUS(r) == 52
        || WEXITSTATUS(r) == 53 || WEXITSTATUS(r) == 54)
        if (WEXITSTATUS(r) == 50)
            my_cd(argvs, my_shell->path, &my_shell->old_pwd);
        else
            next_next_exec(argvs, my_shell, r);
    if (WTERMSIG(r) == SIGSEGV) {
            printf("Segmentation fault");
        if (WCOREDUMP(r))
            printf(" (core dumped)");
        printf("\n");
        return 139;
    }
    if (WEXITSTATUS(r) == 255) {
        printf("%s: Command not found.\n", argvs[0]);
    }
    return WEXITSTATUS(r);
}

int exec(char **argvs, my_shell_t *my_shell)
{
    int pid = fork();
    int status = 0;
    int r = 0;

    if (pid == 0) {
        r = execve(argvs[0], argvs, my_shell->env);
        if (r == -1 && end_of_file(argvs[0], ".sh") != 1) {
            exit(pars(argvs, my_shell->path, my_shell->env));
        } else
            exit(scripting(argvs[0]));
        exit(r);
    } else {
        waitpid(pid, &r, 0);
        next_exec(argvs, my_shell, r, pid);
    }
    free(argvs);
    return 0;
}

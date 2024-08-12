/*
** EPITECH PROJECT, 2024
** myCd
** File description:
** myCd
*/
#include "include/my.h"

int is_file(const char *path)
{
    struct stat path_stat;

    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

void handle_sigint(int sig)
{
    if (sig != EOF)
        printf("\n$> ");
    else
        exit(0);
}

int return_to_root(char **old_pwd)
{
    char *act = getcwd(NULL, 0);
    char *final = act;
    char *str = NULL;
    int n = 0;
    int i = 0;

    *old_pwd = act;
    while (my_strcmp(act, "/") != 0) {
        chdir("..");
        act = getcwd(NULL, 0);
    }
    for (i; n != 3; i++)
        if (final[i] == '/')
            n++;
    str = malloc(sizeof(char) * i);
    my_strncpy(str, final, i);
    chdir(str);
    return 0;
}

int cd_tirer(char **old_pwd)
{
    char *tmp = getcwd(NULL, 0);
    char *act = getcwd(NULL, 0);

    while (my_strcmp(act, "/") != 0) {
        chdir("..");
        act = getcwd(NULL, 0);
    }
    chdir(*old_pwd);
    *old_pwd = tmp;
    return 0;
}

int my_cd(char **argvs, char **path, char **old_pwd)
{
    int len = my_tablen(argvs);

    if ((len == 2 && argvs[1][0] == '-') ||
        my_strcmp(argvs[0], "cd-") == 0) {
        return cd_tirer(old_pwd);
    }
    if (len == 1)
        return return_to_root(old_pwd);
    *old_pwd = getcwd(NULL, 0);
    if (chdir(argvs[1]) != 0) {
        printf("%s", argvs[1]);
        if (is_file(argvs[1]) != 1)
            printf(": No such file or directory.\n");
        else
            printf(": Not a directory.");
        exit(1);
    }
    return 0;
}

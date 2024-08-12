/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-42sh-matheo.campanella
** File description:
** globbings
*/

#include "include/my.h"

int is_glob_pattern(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][0] == '*'
        || tab[i][0] == '?'
        || tab[i][0] == '['
        || tab[i][0] == ']')
            return i;
    }
    return 0;
}

char *res_setup(char **tab, char *res, glob_t globbuf, int i)
{
    res = malloc(sizeof(char) * 1024);
    res = my_strcpy(res, tab[0]);
    for (int j = 1; j < i; j++) {
        res = my_strcat(res, " ");
        res = my_strcat(res, tab[j]);
    }
    for (int j = 0; j < globbuf.gl_pathc; j++) {
        res = my_strcat(res, " ");
        res = my_strcat(res, globbuf.gl_pathv[j]);
    }
    return res;
}

int my_glob(my_shell_t *my_shell)
{
    glob_t globbuf;
    int r = 0;
    char **tab = my_str_to_word_array(my_shell->com, ' ');
    int i = is_glob_pattern(tab);
    char *res;

    if (glob(tab[i], GLOB_NOCHECK | GLOB_TILDE, NULL, &globbuf) != 0) {
        printf("Error with glob\n");
        return 1;
    }
    res = res_setup(tab, res, globbuf, i);
    exec(my_str_to_word_array(res, ' '), my_shell);
    free(res);
    free(tab);
    globfree(&globbuf);
    return 0;
}

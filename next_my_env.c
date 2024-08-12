/*
** EPITECH PROJECT, 2024
** next enf
** File description:
** next env
*/
#include "include/my.h"

void free_list(my_env_t *my_envt)
{
    while (my_envt != NULL) {
        free(my_envt->name);
        free(my_envt->value);
        my_envt = my_envt->next;
    }
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

my_env_t *unsetenv_multi(my_env_t *my_env, char **argvs)
{
    for (int i = 1; argvs[i] != NULL; i++)
        my_env = remove_from_list(my_env, argvs[i]);
    return my_env;
}

int verif_setenv(char *name, char *value, int n)
{
    if ((my_strisalpha(name) == 0) && n == 1) {
        printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if ((my_strisalpha(name) == 1) && n == 1) {
        printf("setenv: Variable name must contain alphanumeric");
        printf(" characters.\n");
        return 1;
    }
    return 0;
}

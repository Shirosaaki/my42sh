/*
** EPITECH PROJECT, 2024
** rm
** File description:
** rm
*/
#include "my.h"

char **rm_first_tab(char **tab)
{
    int i = 0;
    char **new_tab = malloc(sizeof(char *) * my_tablen(tab));

    for (i = 0; tab[i + 1] != NULL; i++)
        new_tab[i] = tab[i + 1];
    new_tab[i] = NULL;
    return new_tab;
}

char **rm_last_tab(char **tab)
{
    int i = 0;
    char **new_tab = malloc(sizeof(char *) * my_tablen(tab));

    for (i = 0; tab[i] != NULL; i++)
        new_tab[i] = tab[i];
    new_tab[i - 1] = NULL;
    return new_tab;
}

char **rm_n_first_tab(char **tab, int n)
{
    for (int i = 0; i < n; i++)
        tab = rm_first_tab(tab);
    return tab;
}

char **rm_n_last_tab(char **tab, int n)
{
    for (int i = 0; i < n; i++)
        tab = rm_last_tab(tab);
    return tab;
}

/*
** EPITECH PROJECT, 2024
** my_tab
** File description:
** my_tab
*/
#include "my.h"

int my_tablen(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return 0;
    for (; tab[i] != NULL; i++);
    return i;
}

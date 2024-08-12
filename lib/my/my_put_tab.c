/*
** EPITECH PROJECT, 2024
** my_put_tab
** File description:
** my_put_tab
*/
#include "my.h"

void my_put_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}

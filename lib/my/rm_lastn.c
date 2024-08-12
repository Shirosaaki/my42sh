/*
** EPITECH PROJECT, 2024
** rm_last\n
** File description:
** rmall
*/
#include "my.h"

char *rm_last_space(char *str)
{
    int i = my_strlen(str) - 1;

    str[i] = '\0';
    return str;
}

char *rm_last_n(char *str)
{
    int i = my_strlen(str) - 1;

    if (str[i] == '\n')
        str[i] = '\0';
    i = my_strlen(str) - 1;
    if (i <= 0)
        return str;
    if (str[i] == ' ')
        str[i] = '\0';
    return str;
}

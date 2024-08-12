/*
** EPITECH PROJECT, 2024
** my
** File description:
** my
*/
#include "my.h"

int my_find_c(char *str, char c)
{
    if (str == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return i;
    return -1;
}

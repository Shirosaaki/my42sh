/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** program who display string
*/
#include "my.h"

int my_putstr(char const *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}

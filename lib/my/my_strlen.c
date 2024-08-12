/*
** EPITECH PROJECT, 2023
** my strlen
** File description:
** program who return the number of letter in string
*/
#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (i; str[i] != '\0'; i++);
    return i;
}

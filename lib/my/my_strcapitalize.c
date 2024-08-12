/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** p in b
*/
#include "my.h"

void next_capitalize(char *str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] -= 32;
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '-' || str[i] == '+') {
            next_capitalize(str, i + 1);
        }
        i++;
    }
    return (str);
}

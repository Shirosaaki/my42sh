/*
** EPITECH PROJECT, 2024
** my_strisalpha
** File description:
** my_strisalpha
*/
#include "my.h"

int my_strisalpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')
            && (str[i] < '0' || str[i] > '9') && str[i] != '@' && str[i] != '#'
            && str[i] != '*' && str[i] != '&' && i == 0)
            return 0;
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')
            && (str[i] < '0' || str[i] > '9') && str[i] != '@' && str[i] != '#'
            && str[i] != '*' && str[i] != '&' && i != 0)
            return 1;
    }
    return 2;
}

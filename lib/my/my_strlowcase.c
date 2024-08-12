/*
** EPITECH PROJECT, 2023
** lowcase
** File description:
** program
*/
#include "my.h"

char *my_strlowcase(char *strc)
{
    char *str = malloc(sizeof(strc));

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    }
    str[my_strlen(strc) + 1] = '\0';
    return str;
}

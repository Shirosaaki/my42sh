/*
** EPITECH PROJECT, 2023
** my_str_is_alpha
** File description:
** my_str_isalpha
*/
#include "my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
            return (0);
        i++;
    }
    return (1);
}

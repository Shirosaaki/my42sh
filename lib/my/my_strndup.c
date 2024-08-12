/*
** EPITECH PROJECT, 2024
** my_strndup
** File description:
** my_strndup
*/
#include "my.h"

char *my_strndup(char const *src, int n)
{
    int i = 0;
    char *str = malloc(sizeof(char *) * (n + 1));

    if (src == NULL)
        return NULL;
    if (str == NULL)
        return NULL;
    for (; i < n && src[i] != '\0'; i++)
        str[i] = src[i];
    if (i < n)
        str[i + 1] = '\0';
    return str;
}

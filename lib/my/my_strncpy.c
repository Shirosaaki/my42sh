/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** jsp
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (i; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    if (i < n)
        dest[i + 1] = '\0';
    return dest;
}

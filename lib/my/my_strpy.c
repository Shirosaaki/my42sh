/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** program who copies a string to another
*/
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    while (dest[i] != '\0' || src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** jsp
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int j = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    if (tmp == NULL)
        return NULL;
    for (; dest[j] != '\0'; j++)
        tmp[j] = dest[j];
    for (; src[j - i] != '\0'; j++)
        tmp[j] = src[j - i];
    tmp[j] = '\0';
    return tmp;
}

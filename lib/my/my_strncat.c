/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** program
*/
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);
    int j = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    while (j <= nb && src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

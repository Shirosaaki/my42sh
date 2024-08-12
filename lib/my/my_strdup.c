/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** my_strdup
*/
#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int len_src = my_strlen(src);
    char *result = malloc(sizeof(char *) * (len_src + 1));

    if (src == NULL)
        return NULL;
    if (result == NULL)
        return NULL;
    for (; i < len_src; i++)
        result[i] = src[i];
    result[i] = '\0';
    return result;
}

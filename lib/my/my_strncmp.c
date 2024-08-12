/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** jsp what doing this program
*/
#include "my.h"


int my_strncmp(char const *s1, char const *s2, int n)
{
    if (s1 == NULL || s2 == NULL)
        return 84;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}

/*
** EPITECH PROJECT, 2024
** Strstr
** File description:
** no
*/

#include "include/my.h"

int next_strstr(char *curr, char *comp, int i)
{
    int j = 0;

    for (j = 0; comp[j] != '\0'; j++){
        if (curr[i + j] != comp[j])
            break;
    }
    if (comp[j] == '\0')
        return i;
    return -1;
}

int my_strstr(char *curr, char *comp)
{
    int i = 0;

    for (i = 0; curr[i] != '\0'; i++){
        if (curr[i] == comp[0] && next_strstr(curr, comp, i) != -1)
                return i;
    }
    return -1;
}

/*
** EPITECH PROJECT, 2023
** my get nbr
** File description:
** program who display the first number of string
*/
#include "my.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int neg = 1;
    int compt = 0;

    for (int i = 0; (str[i] == '+') || (str[i] == '-'); i++) {
        if (str[i] == '-') {
            neg = neg * -1;
        }
        compt += 1;
    }
    for (int i = compt; (str[i] >= '0') && (str[i] <= '9'); i++) {
        if (str[i] != '\0') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
        } else {
            return (nb * neg);
        }
    }
    return (nb * neg);
}

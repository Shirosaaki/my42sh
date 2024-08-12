/*
** EPITECH PROJECT, 2023
** my compute square root
** File description:
** program who return the square root of number
*/
#include "my.h"

int suite(int nb)
{
    int t = 0;

    for (int i = 1; i < nb; i++){
        t = nb / i;
        if ((int)t == (int)i) {
            return i;
        }
    }
    return 0;
}

int my_compute_square_root(int nb)
{
    if (nb == 1) {
        return 1;
    }
    if (nb == (int)nb) {
        return suite(nb);
    } else {
        return 0;
    }
}

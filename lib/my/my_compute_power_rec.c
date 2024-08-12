/*
** EPITECH PROJECT, 2023
** my compute power rec
** File description:
** program who return the power of number
*/
#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p > 0) {
        return (nb * my_compute_power_rec(nb, p - 1));
    } else if (p == 0) {
        return 1;
    } else {
        return 0;
    }
    return 0;
}

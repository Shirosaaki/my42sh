/*
** EPITECH PROJECT, 2023
** my_putnbr
** File description:
** program who display number
*/
#include "my.h"

int my_put_nbr(int nb)
{
    if (nb >= 10)
        my_put_nbr(nb / 10);
    if (nb <= -10) {
        my_putchar('-');
        my_put_nbr(nb * (-1) / 10);
    }
    if (nb < 0 && nb > -10) {
        my_putchar('-');
        my_putchar('0' + (nb * -1));
        return 0;
    }
    my_putchar((nb % 10) + 48);
    return 0;
}

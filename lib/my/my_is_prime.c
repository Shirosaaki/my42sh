/*
** EPITECH PROJECT, 2023
** my is prime
** File description:
** program who return 1 if the number is prime and 0 if the number isn't prime
*/
#include "my.h"

int my_is_prime(int nb)
{
    int is_prime = 1;

    if (nb < 0 || nb == 1 || nb == 0)
        return 0;
    for (int i = 2; i < nb; i++) {
        if (nb % i >= 1)
            is_prime = 1;
        else
            return 0;
    }
    return is_prime;
}

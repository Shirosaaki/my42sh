/*
** EPITECH PROJECT, 2023
** my find prime sup
** File description:
** program who return somethings
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    int result = 0;
    int prime = 0;

    for (int i = nb; i > 2; i--) {
        prime = my_is_prime(i);
        if (prime == 1 && i > result) {
            result = i;
        }
    }
    return result;
}

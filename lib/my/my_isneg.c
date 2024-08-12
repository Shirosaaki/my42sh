/*
** EPITECH PROJECT, 2023
** isneg or no ?
** File description:
** program for view if a number is negative or positive
*/
#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar(78);
    else
        my_putchar(80);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** program who display c
*/
#include "my.h"

void my_putchar(char c)
{
    if (c == '\0')
        return;
    write(1, &c, 1);
}

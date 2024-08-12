/*
** EPITECH PROJECT, 2023
** swap variable
** File description:
** program who sweap two integer content
*/
#include "my.h"

void my_swap(int *a, int *b)
{
    int a1 = *a;
    int b1 = *b;

    *a = b1;
    *b = a1;
}

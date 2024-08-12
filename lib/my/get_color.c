/*
** EPITECH PROJECT, 2023
** get_color
** File description:
** program who return the int value of rgb color
*/
#include "my.h"

struct color {
    int r;
    int g;
    int b;
};

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int color = 0;
    struct color my_color;

    my_color.r = red;
    my_color.g = green;
    my_color.b = blue;
    color = (my_color.r << 16) + (my_color.g << 8) + my_color.b;
    return color;
}

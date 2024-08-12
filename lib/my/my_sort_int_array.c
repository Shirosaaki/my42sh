/*
** EPITECH PROJECT, 2023
** my_sort_int_array
** File description:
** jsp
*/
#include "my.h"

void next_sort(int *array, int i, int j, int tmp)
{
    if (array[i] > array[j]) {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    while (i < size) {
        j = i + 1;
        while (j < size) {
            next_sort(array, i, j, tmp);
            j++;
        }
        i++;
    }
}

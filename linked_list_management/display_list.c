/*
** EPITECH PROJECT, 2024
** display_list
** File description:
** displays a linked list
*/

#include "../lib/my/my.h"
#include "linked_list.h"

void display_function_str(void *data)
{
    my_putstr((char *)data);
}

void display_function_char(void *data)
{
    my_putchar(*(char *)data);
}

void display_function_int(void *data)
{
    my_put_nbr(*(int *)data);
}

void display_list(linked_list_t *list, void (*disp_fct)())
{
    for (; list != NULL; list = list->next) {
        disp_fct(list->data);
        my_putchar('\n');
    }
}

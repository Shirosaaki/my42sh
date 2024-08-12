/*
** EPITECH PROJECT, 2024
** unit
** File description:
** unit
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return i;
}

Test(my_tablen, test_my_tablen)
{
    char *tab[4] = {"Hello", "World", "!", NULL};

    cr_assert_eq(my_tablen(tab), 3);
}

Test(my_tablen, test_my_tablen2)
{
    char *tab[4] = {NULL, "World", "!", NULL};

    cr_assert_eq(my_tablen(tab), 0);
}

Test(my_tablen, test_my_tablen3)
{
    char *tab[4] = {"Hello", "World", "!", "Hello World"};

    cr_assert_eq(my_tablen(tab), 4);
}

Test(my_tablen, test_my_tablen4)
{
    char *tab[4] = {NULL, NULL, NULL, NULL};

    cr_assert_eq(my_tablen(tab), 0);
}

Test(my_tablen, test_my_tablen5)
{
    char *tab[4] = {"Hello", "World", "!", "Hello World", NULL};

    cr_assert_eq(my_tablen(tab), 4);
}

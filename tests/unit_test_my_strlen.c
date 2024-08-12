/*
** EPITECH PROJECT, 2024
** unit
** File description:
** unit
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>
#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}

Test(my_strlen, test_my_strlen)
{
    cr_assert_eq(my_strlen("hello"), 5);
    cr_assert_eq(my_strlen(""), 0);
    cr_assert_eq(my_strlen("\n\t"), 2);
    cr_assert_eq(my_strlen(NULL), 0);
}

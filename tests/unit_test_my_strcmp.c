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

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 1;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return 1;
        i++;
    }
    if (s1[i] != s2[i])
        return 1;
    return 0;
}

Test(my_strcmp, test_my_strcmp)
{
    cr_assert_eq(my_strcmp("hello", "hello"), 0);
    cr_assert_eq(my_strcmp("hello", "world"), 1);
    cr_assert_eq(my_strcmp("", ""), 0);
    cr_assert_eq(my_strcmp("hello", ""), 1);
    cr_assert_eq(my_strcmp("", "hello"), 1);
    cr_assert_eq(my_strcmp(NULL, "hello"), 1);
    cr_assert_eq(my_strcmp("hello", NULL), 1);
    cr_assert_eq(my_strcmp(NULL, NULL), 1);
}
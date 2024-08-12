/*
** EPITECH PROJECT, 2024
** unit
** File description:
** unit
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_find_c(char *str, char c)
{
    if (str == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return i;
    return -1;
}

Test(my_find_c, test_my_find_c)
{
    cr_assert_eq(my_find_c("Hello", 'e'), 1);
    cr_assert_eq(my_find_c("Hello", 'H'), 0);
    cr_assert_eq(my_find_c("Hello", 'o'), 4);
    cr_assert_eq(my_find_c("Hello", 'l'), 2);
    cr_assert_eq(my_find_c("Hello", 'z'), -1);
    cr_assert_eq(my_find_c("Hello", ' '), -1);
    cr_assert_eq(my_find_c("Hello", '\0'), -1);
    cr_assert_eq(my_find_c("Hello", '\n'), -1);
    cr_assert_eq(my_find_c("Hello", '\t'), -1);
    cr_assert_eq(my_find_c(NULL, 'u'), -1);
    cr_assert_eq(my_find_c(NULL, '\0'), -1);
    cr_assert_eq(my_find_c("Hello", (char)NULL), -1);
}
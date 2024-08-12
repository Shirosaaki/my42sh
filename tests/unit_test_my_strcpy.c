/*
** EPITECH PROJECT, 2024
** unit
** File description:
** unit
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (dest[i] != '\0' || src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

Test(my_strcpy, test_my_strcpy)
{
    char dest[6] = {0};
    char *src = "Hello";

    cr_assert_str_eq(my_strcpy(dest, src), "Hello");
}

Test(my_strcpy, test_my_strcpy2)
{
    char dest[6] = {0};
    char *src = "World";

    cr_assert_str_eq(my_strcpy(dest, src), "World");
}

Test(my_strcpy, test_my_strcpy3)
{
    char dest[12] = {0};
    char *src = "Hello World";

    cr_assert_str_eq(my_strcpy(dest, src), "Hello World");
}

Test(my_strcpy, test_my_strcpy4)
{
    char dest[1] = {0};
    char *src = "";

    cr_assert_str_eq(my_strcpy(dest, src), "");
}

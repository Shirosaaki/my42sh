/*
** EPITECH PROJECT, 2024
** unit
** File description:
** untit
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>
#include <unistd.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    if (dest == NULL)
        return src;
    if (src == NULL)
        return dest;
    for (; dest[i] != '\0'; i++);
    for (; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return dest;
}

Test(my_strcat, test_my_strcat)
{
    char dest[100] = "hello";
    char src[] = " world";

    cr_assert_str_eq(my_strcat(dest, src), "hello world");
    cr_assert_str_eq(my_strcat(dest, ""), "hello world");
    cr_assert_str_eq(my_strcat(dest, " world"), "hello world world");
    cr_assert_str_eq(my_strcat(dest, NULL), dest);
    cr_assert_str_eq(my_strcat(NULL, src), src);
}

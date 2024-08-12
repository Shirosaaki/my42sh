/*
** EPITECH PROJECT, 2024
** unit
** File description:
** unut
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}

char *my_strdup(char const *src)
{
    int i = 0;
    int len_src = my_strlen(src);
    char *result = malloc(sizeof(char *) * (len_src + 1));

    if (src == NULL)
        return NULL;
    if (result == NULL)
        return NULL;
    for (; i < len_src; i++)
        result[i] = src[i];
    result[i] = '\0';
    return result;
}

Test(my_strdup, test_my_strdup)
{
    cr_assert_str_eq(my_strdup("Hello"), "Hello");
    cr_assert_str_eq(my_strdup("World"), "World");
    cr_assert_str_eq(my_strdup("Hello World"), "Hello World");
    cr_assert_str_eq(my_strdup(""), "");
}
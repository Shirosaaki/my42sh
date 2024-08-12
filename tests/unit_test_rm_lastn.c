/*
** EPITECH PROJECT, 2024
** unit
** File description:
** unit
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

char *rm_last_space(char *str)
{
    int i = my_strlen(str) - 1;

    str[i] = '\0';
    return str;
}

char *rm_last_n(char *str)
{
    char *rm_last_n(char *str);
    int i = strlen(str) - 1;
    char *new_str = strdup(str);

    while (i >= 0 && (new_str[i] == '\n' || new_str[i] == ' ')) {
        if (new_str[i] == ' ')
            new_str = rm_last_space(new_str);
        else
            new_str[i] = '\0';
        i--;
    }

    return new_str;
}


Test(rm_last_n, test_rm_last_n1)
{
    cr_assert_str_eq(rm_last_n("Hello\n"), "Hello");
}

Test(rm_last_n, test_rm_last_n2)
{
    cr_assert_str_eq(rm_last_n("Hello "), "Hello");
}

Test(rm_last_n, test_rm_last_n3)
{
    cr_assert_str_eq(rm_last_n("Hello"), "Hello");
}

Test(rm_last_n, test_rm_last_n4)
{
    cr_assert_str_eq(rm_last_n("Hello\n "), "Hello");
}

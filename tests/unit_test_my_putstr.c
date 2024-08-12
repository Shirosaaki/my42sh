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

void my_putstr(char const *str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
}

Test(my_putstr, test_my_putstr1)
{
    cr_redirect_stdout();
    my_putstr("hello");
    cr_assert_stdout_eq_str("hello");
}

Test(my_putstr, test_my_putstr2)
{
    cr_redirect_stdout();
    my_putstr("");
    cr_assert_stdout_eq_str("");
}

Test(my_putstr, test_my_putstr3)
{
    cr_redirect_stdout();
    my_putstr("\n\t");
    cr_assert_stdout_eq_str("\n\t");
}

Test(my_putstr, test_my_putstr4)
{
    cr_redirect_stdout();
    my_putstr(NULL);
    cr_assert_stdout_eq_str("");
}

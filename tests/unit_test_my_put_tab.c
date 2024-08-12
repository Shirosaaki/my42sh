/*
** EPITECH PROJECT, 2024
** unit
** File description:
** unit
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

void my_put_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++)
            write(1, &tab[i][j], 1);
        write(1, "\n", 1);
    }
}

Test(my_put_tab, test_my_put_tab)
{
    cr_redirect_stdout();
    char *tab[4] = {"Hello", "World", "!", NULL};
    my_put_tab(tab);
    cr_assert_stdout_eq_str("Hello\nWorld\n!\n");
}

Test(my_put_tab, test_my_put_tab2)
{
    cr_redirect_stdout();
    char *tab[4] = {NULL, "World", "!", NULL};
    my_put_tab(tab);
    cr_assert_stdout_eq_str("");
}

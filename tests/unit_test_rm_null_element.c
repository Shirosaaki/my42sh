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

char **rm_null_element_array(char **array)
{
    int i = 0;
    int j = 0;
    char **new_array = NULL;

    for (i = 0; array[i] != NULL; i++)
        if (array[i][0] != '\0')
            j++;
    new_array = malloc(sizeof(char *) * (j + 1));
    j = 0;
    for (i = 0; array[i] != NULL; i++) {
        if (array[i][0] != '\0') {
            new_array[j] = strdup(array[i]);
            new_array[j] = rm_last_n(new_array[j]);
            j++;
        }
    }
    new_array[j] = NULL;
    return new_array;
}

Test(rm_null_element_array, test_rm_null_element_array1)
{
    char *array[] = {"Hello", "", "World", NULL};
    char **new_array = rm_null_element_array(array);

    cr_assert_str_eq(new_array[0], "Hello");
    cr_assert_str_eq(new_array[1], "World");
    cr_assert_null(new_array[2]);
}

Test(rm_null_element_array, test_rm_null_element_array2)
{
    char *array[] = {"Hello", "World", NULL};
    char **new_array = rm_null_element_array(array);

    cr_assert_str_eq(new_array[0], "Hello");
    cr_assert_str_eq(new_array[1], "World");
    cr_assert_null(new_array[2]);
}

Test(rm_null_element_array, test_rm_null_element_array3)
{
    char *array[] = {"Hello", "", "", "World", NULL};
    char **new_array = rm_null_element_array(array);

    cr_assert_str_eq(new_array[0], "Hello");
    cr_assert_str_eq(new_array[1], "World");
    cr_assert_null(new_array[2]);
}

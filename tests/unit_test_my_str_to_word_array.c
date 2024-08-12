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

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (src == NULL)
        return NULL;
    for (; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

int my_strlen_array(char **array)
{
    int i = 0;

    if (array == NULL)
        return 0;
    for (; array[i] != NULL; i++);
    return i;
}

char **rm_null_element_array(char **array)
{
    int i = 0;
    int j = 0;
    char **new_array = malloc(sizeof(char *) * (my_strlen_array(array) + 1));

    if (new_array == NULL)
        return NULL;
    for (; array[i] != NULL; i++) {
        if (my_strlen(array[i]) != 0) {
            new_array[j] = array[i];
            j++;
        }
    }
    new_array[j] = NULL;
    free(array);
    return new_array;
}

int lenget(int end, int start, char const *str)
{
    int length = 0;

    if (str[end + 1] == '\0')
        length = end - start + 1;
    else
        length = end - start;
    return length;
}

char **word(char *str, char **array, int *i, char c)
{
    int start = 0;
    int end = 0;
    int length = 0;

    while (str[end] != '\0') {
        if (str[end] == '\n' || str[end] == c || str[end + 1] == '\0'
            || str[end] == '\t') {
            length = lenget(end, start, str);
            array[*i] = malloc(sizeof(char) * (length + 1));
            my_strncpy(array[*i], &str[start], length);
            array[*i][length] = '\0';
            start = end + 1;
            *i += 1;
        }
        end++;
    }
    return array;
}

int count_word_letter(char const *str, char c)
{
    int count = 0;

    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count += 1;
    return count;
}

char **my_str_to_word_array(char *str, char c)
{
    int i = 0;
    int count = count_word_letter(str, c);
    char **array = malloc(sizeof(char *) * (count + 2));

    if (array == NULL || str == NULL)
        return NULL;
    array = word(str, array, &i, c);
    array[i] = NULL;
    array = rm_null_element_array(array);
    return array;
}

Test(my_str_to_word_array, test_my_str_to_word_array1)
{
    char *str = "Hello World";
    char **array = my_str_to_word_array(str, ' ');

    cr_assert_str_eq(array[0], "Hello");
    cr_assert_str_eq(array[1], "World");
    cr_assert_null(array[2]);
}

Test(my_str_to_word_array, test_my_str_to_word_array2)
{
    char *str = "Hello World";
    char **array = my_str_to_word_array(str, 'o');

    cr_assert_str_eq(array[0], "Hell");
    cr_assert_str_eq(array[1], " W");
    cr_assert_str_eq(array[2], "rld");
    cr_assert_null(array[3]);
}

Test(my_str_to_word_array, test_my_str_to_word_array3)
{
    char *str = "Hello World";
    char **array = my_str_to_word_array(str, 'z');

    cr_assert_str_eq(array[0], "Hello World");
    cr_assert_null(array[1]);
}

Test(my_str_to_word_array, test_my_str_to_word_array4)
{
    char *str = "Hello World";
    char **array = my_str_to_word_array(str, (char)NULL);

    cr_assert_str_eq(array[0], "Hello World");
    cr_assert_null(array[1]);
}

Test(my_str_to_word_array, test_my_str_to_word_array5)
{
    char *str = "Hello World";
    char **array = my_str_to_word_array(NULL, ' ');

    cr_assert_null(array);
}

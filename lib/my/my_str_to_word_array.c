/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** program who transform a string to array
*/
#include "my.h"

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
            rm_last_n(array[*i]);
            start = end + 1;
            *i += 1;
        }
        end++;
    }
    return array;
}

int count_word_letter(char const *str, char c)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == c || str[i] == '\n' || str[i] == '\t')
            count++;
        i++;
    }
    return count;
}

char **my_str_to_word_array(char *str, char c)
{
    int i = 0;
    int count = count_word_letter(str, c);
    char **array = malloc((count + 2) * sizeof(char *));

    if (array == NULL || str == NULL)
        return NULL;
    if (str[0] == '\0') {
        array[0] = NULL;
        return array;
    }
    array = word((char *)str, array, &i, c);
    array[i] = NULL;
    array = rm_null_element_array(array);
    return array;
}

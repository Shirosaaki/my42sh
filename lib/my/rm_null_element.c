/*
** EPITECH PROJECT, 2024
** rm_null_element_array
** File description:
** idem
*/
#include "my.h"

char **rm_null_element_array(char **array)
{
    int i = 0;
    int j = 0;
    char **new_array = malloc(sizeof(char *) * (my_tablen(array) + 1));

    if (new_array == NULL)
        return NULL;
    for (i = 0; array[i] != NULL; i++) {
        if (array[i][0] != '\0') {
            new_array[j] = my_strdup(array[i]);
            j++;
        }
    }
    new_array[j] = NULL;
    free_tab(array);
    return new_array;
}

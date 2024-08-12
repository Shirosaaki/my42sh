/*
** EPITECH PROJECT, 2024
** file for my_env
** File description:
** file for my_env
*/
#include "include/my.h"

void print_list(my_env_t *list)
{
    my_env_t *tmp = list;

    while (tmp != NULL) {
        printf("%s", tmp->name);
        printf("=");
        if (tmp->value == NULL)
            printf("%s", "");
        else
            printf("%s", tmp->value);
        printf("\n");
        tmp = tmp->next;
    }
}

my_env_t *init_list(char *name, char *value)
{
    my_env_t *new = malloc(sizeof(my_env_t));

    new->name = name;
    if (value == NULL)
        new->value = "";
    else
        new->value = value;
    new->next = NULL;
    return new;
}

my_env_t *add_to_list(my_env_t *list, char *name, char *value)
{
    my_env_t *new = malloc(sizeof(my_env_t));
    my_env_t *tmp = list;

    new->name = name;
    if (value == NULL)
        new->value = "";
    else
        new->value = value;
    new->value = value;
    new->next = NULL;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return list;
}

my_env_t *remove_from_list(my_env_t *list, char *name)
{
    my_env_t *tmp = list;
    my_env_t *prev = list;

    if (tmp == NULL)
        return list;
    if (my_strcmp(tmp->name, name) == 0) {
        list = list->next;
        free(tmp);
        return list;
    }
    while (tmp != NULL && my_strcmp(tmp->name, name) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return list;
    prev->next = tmp->next;
    free(tmp);
    return list;
}

my_env_t *my_setenv(my_env_t *list, char *name, char *value, int n)
{
    my_env_t *tmp = list;

    if (name == NULL)
        return list;
    if (verif_setenv(name, value, n) == 1)
        return list;
    if (list == NULL)
        return init_list(name, value);
    while (tmp != NULL && my_strcmp(tmp->name, name) != 0)
        tmp = tmp->next;
    if (tmp == NULL)
        return add_to_list(list, name, value);
    tmp->value = value;
    return list;
}

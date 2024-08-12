/*
** EPITECH PROJECT, 2024
** history
** File description:
** history
*/

#include "../linked_list_management/linked_list.h"
#include "../include/my.h"

int my_ll_len(linked_list_t *list)
{
    linked_list_t *tmp = list;
    int i = 0;

    for (; tmp != NULL; tmp = tmp->next)
        i++;
    return i;
}

void add_to_history(linked_list_t **history, char *command, time_t time)
{
    struct tm tm = *localtime(&time);
    history_t *new_node = malloc(sizeof(history_t));

    new_node->command = my_strdup(command);
    new_node->time = tm;
    new_node->index = 1;
    for (linked_list_t *tmp = *history; tmp != NULL; tmp = tmp->next){
        if (tmp->next == NULL)
            new_node->index = ((history_t *)(tmp->data))->index + 1;
    }
    push_to_end_of_list(history, (void *)(new_node));
}

void display_history(linked_list_t *history, void (*disp_fct)())
{
    for (linked_list_t *tmp = history; tmp != NULL; tmp = tmp->next){
        printf("\t%i\t%02d:%02d\t%s\n", ((history_t *)(tmp->data))->index,
        ((history_t *)(tmp->data))->time.tm_hour,
        ((history_t *)(tmp->data))->time.tm_min,
        ((history_t *)(tmp->data))->command);
    }
}

int history(linked_list_t *hist, char **args)
{
    display_history(hist, *display_function_str);
}

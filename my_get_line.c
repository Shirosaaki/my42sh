/*
** EPITECH PROJECT, 2024
** tes
** File description:
** test
*/
#include "include/my.h"

void handle_delete_key(char *line, int *cursor, int *end)
{
    if (*cursor > 0) {
        for (int i = *cursor - 1; i < *end; i++)
            line[i] = line[i + 1];
        (*cursor)--;
        (*end)--;
    }
}

void handle_enter_key(int *cursor, int *end)
{
    if (isatty(STDIN_FILENO) == 1)
        printf("\n");
    *cursor = 0;
    *end = 0;
}

void handle_default_key(char c, char *line, int *cursor, int *end)
{
    if (*end < 1024 - 1) {
        for (int i = *end; i > *cursor; i--)
            line[i] = line[i - 1];
        line[*cursor] = c;
        (*cursor)++;
        (*end)++;
    }
}

void next_line(char **line, my_shell_t *my_shell)
{
    int c = 0;

    while (c != '\n') {
        c = getchar();
        if (c == 4 || c == -1)
            disable_raw_mode();
        if (c == '\033') {
            handle_arrow_keys(getchar(), my_shell, line);
            print_line(*line, my_shell->cursor, my_shell->end, my_shell);
        } else {
            my_shell->index = get_history_len(my_shell->history) + 2;
        }
        if (c == 127) {
            handle_delete_key(*line, &my_shell->cursor, &my_shell->end);
            print_line(*line, my_shell->cursor, my_shell->end, my_shell);
        }
        if (c != '\033' && c != 127 && c != '\n') {
            handle_default_key(c, *line, &my_shell->cursor, &my_shell->end);
            print_line(*line, my_shell->cursor, my_shell->end, my_shell);
        }
    }
}

char *my_get_line(char *line, my_shell_t *my_shell)
{
    my_shell->cursor = 0;
    my_shell->end = 0;
    enable_raw_mode();
    if (my_strcmp(line, "\n") != 0)
        free(line);
    line = malloc(sizeof(char) * 1024);
    next_line(&line, my_shell);
    line[my_shell->end] = '\0';
    while (line[0] == '\0') {
        printf("\n");
        print_line(line, my_shell->cursor, my_shell->end, my_shell);
        next_line(&line, my_shell);
        line[my_shell->end] = '\0';
    }
    if (line[my_shell->end - 1] == '\n')
        line[my_shell->end - 1] = '\0';
    handle_enter_key(&my_shell->cursor, &my_shell->end);
    rm_last_n(line);
    return line;
}

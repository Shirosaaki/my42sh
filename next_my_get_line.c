/*
** EPITECH PROJECT, 2024
** test
** File description:
** test
*/
#include "include/my.h"

void enable_raw_mode(void)
{
    struct termios term;

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

void print_line(char *line, int cursor, int end, my_shell_t *my_shell)
{
    if (isatty(STDIN_FILENO) == 1)
        printf("\r\033[2K%s $> ", getcwd(NULL, 0));
    else
        return;
    for (int i = 0; i < end; i++)
        putchar(line[i]);
    for (int i = 0; i < end - cursor; i++)
        printf("\033[1D");
}

int get_history_len(linked_list_t *history)
{
    linked_list_t *tmp = history;
    int i = 0;

    for (; tmp != NULL; tmp = tmp->next)
        i++;
    return i;
}

void backup_line(my_shell_t *my_shell, int up, char **line)
{
    linked_list_t *tmp = my_shell->history;

    if (tmp == NULL)
        return;
    my_shell->index += up;
    if (my_shell->index < 1)
        my_shell->index = 1;
    if (my_shell->index > get_history_len(my_shell->history))
        my_shell->index = get_history_len(my_shell->history);

    while (((history_t *)(tmp->data))->index != my_shell->index)
        tmp = tmp->next;
    *line = strdup(((history_t *)(tmp->data))->command);
    my_shell->cursor = strlen(*line);
    my_shell->end = strlen(*line);
    print_line(*line, my_shell->cursor, my_shell->end, my_shell);
}

void handle_arrow_keys(char c, my_shell_t *my_shell, char **line)
{
    c = getchar();
    switch (c) {
        case 'C':
            if (my_shell->cursor < my_shell->end)
                (my_shell->cursor)++;
            break;
        case 'D':
            if (my_shell->cursor > 0)
                (my_shell->cursor)--;
            break;
        case 'A':
            backup_line(my_shell, -1, line);
            break;
        case 'B':
            backup_line(my_shell, 1, line);
            break;
    }
}

/*
** EPITECH PROJECT, 2024
** my_h
** File description:
** my_h
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <sys/syscall.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <time.h>
    #include "../linked_list_management/linked_list.h"
    #include <termios.h>
    #include <unistd.h>
    #include <string.h>
    #include <glob.h>

typedef struct commandes_s {
    char *com;
    struct commandes_s *next;
} commandes_t;

typedef struct my_env_s {
    char *name;
    char *value;
    struct my_env_s *next;
} my_env_t;

typedef struct alias_s {
    char *name;
    char *command;
    struct alias_s *next;
} alias_t;

typedef struct history_s {
    char *command;
    struct tm time;
    int index;
} history_t;

typedef struct my_shell_s {
    char *old_pwd;
    char **path;
    char **env;
    char **argvs;
    char *com;
    char *line;
    int cursor;
    int end;
    int index;
    char old_c;
    size_t len;
    linked_list_t *history;
    my_env_t *my_env;
    alias_t *alias_list;
} my_shell_t;

char *rm_last_n(char *str);
int my_glob(my_shell_t *my_shell);
int is_glob_pattern(char **tab);
char **my_str_to_word_array(char *str, char separator);
int my_strcmp(char const *s1, char const *s2);
void my_putstr(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
void my_put_tab(char **tab);
int my_cd(char **argvs, char **path, char **old_pwd);
int my_tablen(char **tab);
void my_putchar(char c);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
void handle_sigint(int sig);
int exec(char **argvs, my_shell_t *my_shell);
int pars(char **argvs, char **path, char **env);
void print_shell(char **com, size_t len, my_shell_t *my_shell);
void get_line_while(char **com, size_t len, my_shell_t *my_shell);
char *my_strdup(char const *src);
void print_list(my_env_t *list);
my_env_t *init_list(char *name, char *value);
my_env_t *add_to_list(my_env_t *list, char *name, char *value);
my_env_t *remove_from_list(my_env_t *list, char *name);
my_env_t *my_setenv(my_env_t *list, char *name, char *value, int n);
int next_exec(char **argvs, my_shell_t *my_shell, int r, int pid);
int nex_to_loop(my_shell_t *my_shell);
char **rm_n_first_tab(char **tab, int n);
int my_strisalpha(char *str);
int verif_setenv(char *name, char *value, int n);
int my_find_c(char *str, char c);
char *rm_first_space(char *str);
char *rm_last_n(char *str);
int exec_redirection(char **com, my_shell_t *my_shell);
int exec_pipe(char **com, my_shell_t *my_shell);
int exec_semicolon(char **com, my_shell_t *my_shell);
int exec_redirection_g(char **com, my_shell_t *my_shell);
int other_exec_redirection(char **com, my_shell_t *my_shell);
my_env_t *unsetenv_multi(my_env_t *list, char **argvs);
void free_list(my_env_t *list);
void free_tab(char **tab);
char *my_strndup(char const *src, int n);
int history(linked_list_t *hist, char **args);
void add_to_history(linked_list_t **history, char *command, time_t time);
void display_history(linked_list_t *history, void (*disp_fct)());
void enable_raw_mode(void);
void print_line(char *line, int cursor, int end, my_shell_t *my_shell);
void handle_arrow_keys(char c, my_shell_t *my_shell, char **line);
void handle_delete_key(char *line, int *cursor, int *end);
void handle_enter_key(int *cursor, int *end);
void handle_default_key(char c, char *line, int *cursor, int *end);
void my_alias(my_shell_t *my_shell);
void unalias(char *name, my_shell_t *my_shell);
void print_alias(alias_t *alias_list);
void print_com_alias(alias_t *alias_list, char *name);
int in_alias(char *name, alias_t *alias_list);
void add_alias(char *name, char *command, my_shell_t *my_shell);
void next_line(char **line, my_shell_t *my_shell);
char *my_get_line(char *line, my_shell_t *my_shell);
int scripting(char *path);
int end_of_file(char *path, char *end);
int my_strstr(char *curr, char *comp);
int get_print(my_shell_t *my_shell);
void next_for_loop(my_shell_t *my_shell);
int alias_cmp(char *com);
void continue_alias(my_shell_t *my_shell, char *new);
int execute_alias(char *com, alias_t *alias_list, my_shell_t *my_shell);
void handle_pipe(int *fd, int pid, char *tab_i, my_shell_t *my_shell);
int handle_special_commands(my_shell_t *my_shell);
void disable_raw_mode(void);
int get_history_len(linked_list_t *history);

#endif /* !MY_H_ */

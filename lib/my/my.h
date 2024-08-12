/*
** EPITECH PROJECT, 2024
** my h
** File description:
** myh
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <string.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>

int get_color(unsigned char red, unsigned char green, unsigned char blue);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strisalpha(char *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char const *src);
char **my_str_to_word_array(char *str, char separator);
void my_swap(int *a, int *b);
int my_tablen(char **tab);
char **rm_null_element_array(char **array);
char *my_strdup(char const *src);
char *rm_last_n(char *str);
char *my_strndup(char const *src, int n);
void free_tab(char **tab);

#endif /*MY_H*/

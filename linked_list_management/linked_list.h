/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** header file
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

    #include <sys/wait.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <string.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <errno.h>

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
    struct linked_list_s *prev;
} linked_list_t;

void push_to_start_of_list(linked_list_t **, void *);

void push_to_end_of_list(linked_list_t **, void *);

void display_list(linked_list_t *, void (*disp_fct)());

void display_function_str(void *);

void display_function_char(void *);

void display_function_int(void *);

void delete_in_list(linked_list_t **, void const *, int (*cmp_fct)());

int compare_function_str(void *, void const *);

int compare_function_char(void *, void const *);

int compare_function_int(void *, void const *);

void destroy_list(linked_list_t **);

char **linked_list_to_str_array(linked_list_t *);

void str_array_to_linked_list(char **, linked_list_t **);

#endif /* LINKED_LIST_H_ */

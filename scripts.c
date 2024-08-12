/*
** EPITECH PROJECT, 2024
** scripts
** File description:
** scripts
*/
#include "include/my.h"

int next_end_of_file(char *file, char *end, int i, int j)
{
    if (file[i] == end[j]) {
        j++;
        if (end[j] == '\0')
            return (1);
    } else
        j = 0;
    return j;
}

int end_of_file(char *file, char *end)
{
    int i = 0;
    int j = 0;

    while (file[i] != '\0') {
        j = next_end_of_file(file, end, i, j);
        if (j == 1)
            return 1;
        i++;
    }
    return (0);
}

int scripting(char *path)
{
    int fd;
    size_t len = 0;
    char *buff;
    struct stat statbuf;
    int size;

    path += 2;
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return 84;
    fstat(fd, &statbuf);
    size = statbuf.st_size;
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    buff[size + 1] = '\0';
    close(fd);
    system(buff);
    printf("\n");
    free(buff);
    return 0;
}

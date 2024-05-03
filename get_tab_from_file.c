/*
** EPITECH PROJECT, 2024
** get_tab_from_file
** File description:
** tab_from_file
*/

#include "include/stumper.h"

int count_cara(char *const filepath)
{
    struct stat buff;
    int a = 0;

    if (stat(filepath, &buff) == -1)
        return 0;
    a = buff.st_size;
    return a;
}

char **get_tab(char *str)
{
    int b = count_cara(str);
    int fd;
    ssize_t bytesRead;
    char *buffer = malloc(sizeof(char) * (b) + 1);
    char **tab;
    int cmp = 0;

    fd = open(str, O_RDONLY);
    bytesRead = read(fd, buffer, b);
    buffer[bytesRead] = '\0';
    tab = my_str_to_word_array_condition(buffer, "\n");
    free(buffer);
    return tab;
}
/*
** EPITECH PROJECT, 2023
** lolo
** File description:
** lala
*/

#ifndef ORGINIZED_H
    #define ORGINIZED_H

    #include "stddef.h"
    #include "stdio.h"
    #include "stdlib.h"
    #include "string.h"
    #include "sys/stat.h"
    #include "fcntl.h"
    #include "unistd.h"
    #include <time.h>

typedef struct stumper_s{
    int index;
}stumper_t;

void init_struct(stumper_t *duo, int ac, char **av);
int error_handling(int ac, char **av);
char **my_str_to_word_array_condition(char *str, char *condition);
char **get_tab(char *str);
char **bubble_sort(char **, char **);

#endif

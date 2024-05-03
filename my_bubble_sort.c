/*
** EPITECH PROJECT, 2024
** textcount
** File description:
** bubble_sort
*/

#include "include/stumper.h"

char **give_array(char **tab, char *str, char **letter)
{
    char *str_two;

    for (int j = 0; tab[j] != NULL; j++) {
        if (tab[j + 1] != NULL && atoi(tab[j]) < atoi(tab[j + 1])) {
            str = tab[j];
            str_two = letter[j];
            tab[j] = tab[j + 1];
            letter[j] = letter[j + 1];
            tab[j + 1] = str;
            letter[j + 1] = str_two;
        }
    }
    return tab;
}

char **bubble_sort(char **tab, char **array)
{
    char *str;

    for (int i = 0; tab[i] != NULL; i++) {
        give_array(tab, str, array);
    }
}

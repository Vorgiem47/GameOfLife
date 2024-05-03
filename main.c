/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "include/stumper.h"

int get_x(char **tab, int *i, int *k)
{
    int cmp = 0;

    if (*i - 1 >= 0 && tab[*i - 1][*k] == 'X') {
        cmp++;
    }
    if (*i - 1 >= 0 && tab[*i - 1][*k - 1] == 'X') {
        cmp++;
    }
    if (*i - 1 >= 0 && tab[*i - 1][*k + 1] == 'X') {
        cmp++;
    }
    if (tab[*i + 1] != NULL && tab[*i + 1][*k] == 'X') {
        cmp++;
    }
    if (tab[*i + 1] != NULL && tab[*i + 1][*k - 1] == 'X') {
        cmp++;
    }
    if (tab[*i + 1] != NULL && tab[*i + 1][*k + 1] == 'X') {
        cmp++;
    }
    if (tab[*i][*k + 1] != '\0' && tab[*i][*k + 1] == 'X') {
        cmp++;
    }
    if (*k - 1 >= 0 && tab[*i][*k - 1] == 'X') {
        cmp++;
    }
    return cmp;
}

int **be_tab(char **tab)
{
    int cmp;
    char *str;

    for (cmp = 0; tab[cmp] != NULL; cmp++);

    int **array = malloc(sizeof(int *) * (cmp + 1));
    for (int i = 0; tab[i] != NULL; i++) {
        array[i] = malloc(sizeof(int) * (strlen(tab[i]) + 1));
    }
    return array;
}

int main(int ac, char **av)
{
    stumper_t *duo = malloc(sizeof(stumper_t));
    char **tab = get_tab(av[1]);
    int **array = be_tab(tab);
    int x = 0;
    int o = 0;

    if (error_handling(ac, av) == 84)
        return 84;
    init_struct(duo, ac, av);
    for (int j = 0; j != atoi(av[2]); j++) {
        for (int i = 0; tab[i] != NULL; i++) {
            for (int k = 0; tab[i][k] != '\0'; k++) {
                x = get_x(tab, &i, &k);
                array[i][k] = x;
            }
        }
        for (int i = 0; tab[i] != NULL; i++) {
            for (int k = 0; tab[i][k] != '\0'; k++) {
                if (tab[i][k] == '.' && array[i][k] == 3) {
                    tab[i][k] = 'X';
                    continue;
                }
                if (tab[i][k] == 'X' && (array[i][k] == 0 || array[i][k] == 1)) {
                    tab[i][k] = '.';
                    continue;
                }
                if (tab[i][k] == 'X' && (array[i][k] >= 4 && array[i][k] <= 8)) {
                    tab[i][k] = '.';
                    continue;
                }
            }
        }
        for (int i = 0; tab[i] != NULL; i++) {
            printf("%s\n", tab[i]);
        }
        printf("\n");
        usleep(100000);
    }
}

/*
** EPITECH PROJECT, 2018
** m_intuses
** File description:
** m_intuses
*/

#include <stdlib.h>
#include "../../include/my.h"
#include <stdio.h>

int m_intlen(int *array)
{
    int i = 0;

    while (array[i] != -1)
        ++i;
    return (i);
}

int *m_intcat(int *array, int new_i)
{
    int *n_array = malloc(sizeof(int) * (m_intlen(array) + 2));
    int i;

    for (i = 0; array[i] != -1; ++i)
        n_array[i] = array[i];
    n_array[i] = new_i;
    n_array[i + 1] = -1;
    free(array);
    return (n_array);
}
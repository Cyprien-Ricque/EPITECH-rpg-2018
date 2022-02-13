/*
** EPITECH PROJECT, 2018
** m_puts
** File description:
** m_puts
*/

#include <unistd.h>
#include <stddef.h>
#include "../../include/my.h"
#include <stdlib.h>
#include <stdio.h>

void free_array(char **array)
{
    for (int i = 0; array && array[i]; ++i)
        free(array[i]);
    if (array)
        free(array);
}
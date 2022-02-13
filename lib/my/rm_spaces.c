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

void move(char *str, int i)
{
    for (;str[i]; ++i)
        str[i] = str[i + 1];
}

void rm_spaces(char *str)
{
    if (!str)
        return;
    for (int i = 0; str[i]; ++i)
        if (str[i] == ' ')
            move(str, i);
}
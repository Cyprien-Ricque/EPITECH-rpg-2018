/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

void m_scpy(char const *src, char *dest, char ch)
{
    int c;

    if (src == NULL)
        dest[0] = 0;
    for (c = 0; c < m_slen(src) && src[c] != ch; ++c)
        dest[c] = src[c];
    dest[c] = '\0';
}
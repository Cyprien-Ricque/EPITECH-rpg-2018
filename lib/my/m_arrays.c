/*
** EPITECH PROJECT, 2018
** my_strtoarray
** File description:
** my_strtoarray
*/

#include <stdlib.h>
#include "../../include/my.h"
#include <stddef.h>
#include <stdio.h>

char *m_arrays(char **array, char c)
{
    char *str = malloc(sizeof(char) * 1);

    str[0] = 0;
    if (!array)
        return (NULL);
    for (int i = 0; array[i]; ++i) {
        str = m_scat(str, array[i], m_slen(str), 0);
        if (array[i + 1])
            str = m_scat(str, &c, m_slen(str), 1);
    }
    return (str);
}
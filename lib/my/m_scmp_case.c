/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_ctrcmp
*/

#include <stdio.h>
#include "../../include/my.h"

char *min(char *str)
{
    if (!str)
        return (NULL);
    for (int i = 0; str[i]; ++i)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] -= ('a' - 'A');
    return (str);
}

int m_scmp_case(char const *str1a, char const *str2a, char lim)
{
    char *str1 = min(m_sdup(str1a, 0));
    char *str2 = min(m_sdup(str2a, 0));

    if (!str1 || !str2)
        return (84);
    for (int i = 0; !((!str1[i] || str1[i] == lim) &&
        (!str2[i] || str2[i] == lim)); ++i) {
        if (str1[i] > str2[i])
            return (1);
        if (str1[i] < str2[i])
            return (-1);
    }
    return (0);
}
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

char *m_cleans(char *str, bool tfree)
{
    char *news;
    int i = 0;

    if (!str)
        return (NULL);
    news = malloc(sizeof(char) * (m_slen(str) + 1));
    for (; *str != '\0' && (*str == ' ' || *str == '\t'); str++);
    for (; *str != '\0'; str++, ++i) {
        if (*str != '\t' && *str != ' ')
            news[i] = *str;
        else
            str[1] != ' ' && str[1] != '\t' && str[1] != '\0' ? news[i] = ' ' :
                i--;
    }
    news[i] = 0;
    if (tfree == true)
        free(str);
    return (news);
}
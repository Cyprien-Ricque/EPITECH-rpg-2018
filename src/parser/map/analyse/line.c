/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char is_class(char *str)
{
    for (int i = 0; str[i]; ++i)
        if (str[i] == '{' || str[i] == '}')
            return (TRUE);
        else if (str[i] == ':')
            return (FALSE);
    return (FALSE);
}

char is_data(char *str)
{
    for (int i = 0; str[i]; ++i)
        if (str[i] == '{' || str[i] == '}')
            return (FALSE);
        else if (str[i] == ':')
            return (TRUE);
    return (FALSE);
}

char is_comment(char *str)
{
    if (m_slen(str) == 0)
        return (TRUE);
    if (str[0] == '/' && str[1] == '/')
        return (TRUE);
    return (FALSE);
}

char line(char *str, char *save)
{
    if (is_comment(str) == TRUE)
        return (2);
    if (is_class(str) == TRUE)
        return (0);
    if (is_data(str) == TRUE)
        return (1);
    error(save);
    return (84);
}
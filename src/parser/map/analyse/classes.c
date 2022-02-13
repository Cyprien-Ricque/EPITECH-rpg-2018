/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include <my.h>
#include "my_rpg.h"

const char *all_classes[] =
{
        "legend", "landscape", "units", "team", "maps", "size", "data",
        "basic", "fast", "strong", "rotation", NULL
};

char add_class(char *str, char *save, char *statement)
{
    rm_spaces(str);
    if (m_slen(str) == 2) {
        statement[m_slen(statement) + 1] = 0;
        statement[m_slen(statement)] = str[0];
        return (SUCCESS);
    }
    for (int i = 0; all_classes[i]; ++i) {
        if (!m_scmp_case(str, all_classes[i], '{')) {
            statement[m_slen(statement) + 1] = 0;
            statement[m_slen(statement)] = (char)(-i - 3);
            return (SUCCESS);
        }
    }
    return (error(save));
}

char new_c(char *str, char *save, char *statement)
{
    for (int i = 0; str[i]; ++i) {
        if (str[i] == '{' && i == 0) {
            error(save);
            return (FAILURE);
        }
        else if (str[i] == '{')
            return (add_class(str, save, statement));
    }
    return (SUCCESS);
}

char end_classe(char *statement, char *save)
{
    if (!statement || m_slen(statement) == 1)
        return (error(save));
    statement[m_slen(statement) - 1] = 0;
    return (SUCCESS);
}

char end(char *str, char *save, char *statement)
{
    for (int i = 0; str[i]; ++i)
        if (str[i] == '}' && m_slen(str) > 1)
            return (error(save));
        else if (str[i] == '}')
            return (end_classe(statement, save));
    return (SUCCESS);
}
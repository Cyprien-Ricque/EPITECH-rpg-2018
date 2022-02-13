/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char back_left(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) != 11)
        return (error(save));
    s->tmp_p.back_left = str[10];
    return (SUCCESS);
}

char back_right(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) != 12)
        return (error(save));
    s->tmp_p.back_right = str[11];
    return (SUCCESS);
}

char front_right(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) != 13)
        return (error(save));
    s->tmp_p.front_right = str[12];
    return (SUCCESS);
}

char front_left(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) != 12)
        return (error(save));
    s->tmp_p.front_left = str[11];
    return (SUCCESS);
}
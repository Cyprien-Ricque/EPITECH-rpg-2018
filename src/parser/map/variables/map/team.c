/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char red_p(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) != 5)
        return (error(save));
    s->tmp_p.red = str[4];
    return (SUCCESS);
}

char blue_p(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) != 6)
        return (error(save));
    s->tmp_p.blue = str[5];
    return (SUCCESS);
}
/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char water_p(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) != 7)
        return (error(save));
    s->tmp_p.water = str[6];
    return (SUCCESS);
}

char flat_p(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) != 6)
        return (error(save));
    s->tmp_p.flat = str[5];
    return (SUCCESS);
}

char mountain_p(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) != 8)
        return (error(save));
    s->tmp_p.mountain = str[7];
    return (SUCCESS);
}
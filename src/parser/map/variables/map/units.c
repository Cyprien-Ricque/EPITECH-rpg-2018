/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char basic_p(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) != 7)
        return (error(save));
    s->tmp_p.basic = str[6];
    return (SUCCESS);
}

char fast_p(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) != 6)
        return (error(save));
    s->tmp_p.fast = str[5];
    return (SUCCESS);
}

char strong_p(summary_t *s, UNUSED char *str, UNUSED char *statement,
    char *save)
{
    if (m_slen(str) != 8)
        return (error(save));
    s->tmp_p.strong = str[7];
    return (SUCCESS);
}

char shop(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) != 6)
        return (error(save));
    s->tmp_p.shop = str[5];
    return (SUCCESS);
}
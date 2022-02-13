/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char attack_p(summary_t *s, char *str, char *statement, char *save)
{
    if (init_units(s, statement) == FAILURE)
        return (FAILURE);
    if (m_slen(str) < 8)
        return (error(save));
    str = &(str[7]);
    if (m_sisnb(str, POSITIVE) == FAILURE)
        return (error(save));
    s->rpg_wd->units[find_pos(s, statement)]->attack = m_getnb(str);
    return (SUCCESS);
}

char life_p(summary_t *s, char *str, char *statement, char *save)
{
    if (init_units(s, statement) == FAILURE)
        return (FAILURE);
    if (m_slen(str) < 6)
        return (error(save));
    str = &(str[5]);
    if (m_sisnb(str, POSITIVE) == FAILURE)
        return (error(save));
    s->rpg_wd->units[find_pos(s, statement)]->life = m_getnb(str);
    init_units(s, statement);
    return (SUCCESS);
}

char moves_p(summary_t *s, char *str, char *statement, char *save)
{
    if (init_units(s, statement) == FAILURE)
        return (FAILURE);
    if (m_slen(str) < 7)
        return (error(save));
    str = &(str[6]);
    if (m_sisnb(str, POSITIVE) == FAILURE)
        return (error(save));
    s->rpg_wd->units[find_pos(s, statement)]->moves = m_getnb(str);
    init_units(s, statement);
    return (SUCCESS);
}

char defense_p(summary_t *s, char *str, char *statement, char *save)
{
    if (init_units(s, statement) == FAILURE)
        return (FAILURE);
    if (m_slen(str) < 9)
        return (error(save));
    str = &(str[8]);
    if (m_sisnb(str, POSITIVE) == FAILURE)
        return (error(save));
    s->rpg_wd->units[find_pos(s, statement)]->defense = m_getnb(str);
    init_units(s, statement);
    return (SUCCESS);
}
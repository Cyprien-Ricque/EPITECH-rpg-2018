/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char size_x_p(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) < 8)
        return (error(save));
    str = &(str[7]);
    if (m_sisnb(str, POSITIVE) == FAILURE)
        return (error(save));
    s->tmp_p.size_x = m_getnb(str);
    return (SUCCESS);
}

char size_y_p(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) < 8)
        return (error(save));
    str = &(str[7]);
    if (m_sisnb(str, POSITIVE) == FAILURE)
        return (error(save));
    s->tmp_p.size_y = m_getnb(str);
    return (SUCCESS);
}

char size_z_p(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) < 8)
        return (error(save));
    str = &(str[7]);
    if (m_sisnb(str, POSITIVE) == FAILURE)
        return (error(save));
    s->tmp_p.size_z = m_getnb(str);
    return (SUCCESS);
}

char units_size(summary_t *s)
{
    if (s->tmp_p.size != 3)
        return (error("Invalid units number"));
    s->rpg_wd->units = malloc(sizeof(perso_t) * (s->tmp_p.size + 1));
    if (!s->rpg_wd->units)
        return (FAILURE);
    for (int i = 0; i <= s->tmp_p.size; ++i)
        s->rpg_wd->units[i] = NULL;
    return (SUCCESS);
}

char size(summary_t *s, char *str, char *statement, char *save)
{
    if (m_slen(str) < 6)
        return (error(save));
    str = &(str[5]);
    if (m_sisnb(str, POSITIVE) == FAILURE)
        return (error(save));
    s->tmp_p.size = m_getnb(str);
    if (statement[0] == FILE_UNITS && statement[1] == UNITS &&
        units_size(s) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
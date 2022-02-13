/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

int find_pos(summary_t *s, char *statement)
{
    int pos = 0;

    while (s->rpg_wd->units[pos] &&
        s->rpg_wd->units[pos]->type != statement[m_slen(statement) - 1])
        ++pos;
    return (pos);
}

char init_units(summary_t *s, char *statement)
{
    int pos;

    if (!s->rpg_wd->units)
        return (error("invalid unity number"));
    pos = find_pos(s, statement);
    if (!s->rpg_wd->units[pos]) {
        s->rpg_wd->units[pos] = malloc(sizeof(perso_t));
        if (!s->rpg_wd->units[pos])
            return (FAILURE);
        s->rpg_wd->units[pos]->type = statement[m_slen(statement) - 1];
    }
    return (SUCCESS);
}
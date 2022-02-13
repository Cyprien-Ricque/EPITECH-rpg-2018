/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char map_p(summary_t *s, char *str, char *statement, char *save)
{
    int map = 0;

    str = &(str[1]);
    if (str[0] == ' ' || str[0] == '\t')
        str = &(str[1]);
    if (init_map_p(s, save) == FAILURE)
        return (FAILURE);
    while (s->rpg_wd->maps[map] &&
        s->rpg_wd->maps[map]->name != statement[m_slen(statement) - 2])
        ++map;
    if (init_actual_map_p(s, map, statement) == FAILURE)
        return (FAILURE);
    if (create_map_landscape(s->rpg_wd->maps[map], str, &s->tmp_p) == FAILURE)
        return (FAILURE);
    if (create_map_units(s->rpg_wd->maps[map], str, &s->tmp_p) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
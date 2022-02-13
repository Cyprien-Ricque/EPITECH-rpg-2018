/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char is_name(char c, tmp_pt *tmp)
{
    for (int i = 0; tmp->names[i]; ++i)
        if (c == tmp->names[i])
            return (SUCCESS);
    return (FAILURE);
}

char assignement_l(char c, float *obj, int pos, tmp_pt *tmp)
{
    if (c != tmp->water && c != tmp->flat && c != tmp->mountain &&
        is_name(c, tmp) == FAILURE)
        return (error("invalid landscape"));
    if (c == tmp->water)
        obj[pos] = 0;
    if (c == tmp->flat)
        obj[pos] = 1;
    if (is_name(c, tmp) == SUCCESS)
        obj[pos] = 1;
    if (c == tmp->mountain)
        obj[pos] = 2;
    return (SUCCESS);
}

void assignement_next(char c, tmp_pt *tmp, map_t *map)
{
    if (is_name(c, tmp) == SUCCESS)
        map->next = c;
}

char init_landscape(map_t *map, tmp_pt *tmp, int pos)
{
    if (pos + 1 > tmp->size_y)
        return (FAILURE);
    map->map[pos + 1] = NULL;
    map->map[pos] = malloc(sizeof(float) * (tmp->size_x + 1));
    return (SUCCESS);
}

char create_map_landscape(map_t *map, char *str, tmp_pt *tmp)
{
    int pos = m_alen((void **)map->map);
    int i = 0;
    int x;

    if (init_landscape(map, tmp, pos) == FAILURE)
        return (FAILURE);
    if (!map->map[pos])
        return (FAILURE);
    for (x = 0; str[i] && x < tmp->size_x; ++x, ++i) {
        if (assignement_l(str[i], map->map[pos], x, tmp) == FAILURE)
            return (FAILURE);
        assignement_next(str[i], tmp, map);
        map->map[pos][x + 1] = -1;
        while (str[i + 1] &&
            (str[i] != ' ' || (str[i + 1] && str[i + 1] == ' ')))
            ++i;
    }
    if (x != tmp->size_x)
        return (FAILURE);
    return (SUCCESS);
}
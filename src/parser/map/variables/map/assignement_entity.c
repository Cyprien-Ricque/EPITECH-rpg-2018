/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char assignement_ut(char c, entity_t *obj, int pos, tmp_pt *tmp)
{
    if (c != tmp->water && c != tmp->flat && c != tmp->mountain &&
        is_name(c, tmp) == FAILURE)
        return (error("Invalid landscape"));
    if (c == tmp->water)
        obj[pos].type = WATER;
    if (c == tmp->flat)
        obj[pos].type = FLAT;
    if (is_name(c, tmp) == SUCCESS)
        obj[pos].type = LINK;
    if (c == tmp->mountain)
        obj[pos].type = MOUNTAIN;
    return (SUCCESS);
}

char assignement_by_type(char *c, entity_t *obj, int pos, tmp_pt *tmp)
{
    c++;
    if (obj[pos].perso->type == SHOP) {
        obj[pos].perso->team = 0;
    } else {
        if (team_assignement(c, obj, pos, tmp) == FAILURE)
            return (FAILURE);
        c++;
    }
    if (rotation_assignement(c, obj, pos, tmp) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

char assignement_u(char *c, entity_t *obj, int pos, tmp_pt *tmp)
{
    obj[pos].perso = NULL;
    if (*c == ' ' || !*c)
        return (SUCCESS);
    if (*c != tmp->basic && *c != tmp->fast && *c != tmp->strong &&
        *c != tmp->shop)
        return (error("invalid units"));
    obj[pos].perso = malloc(sizeof(perso_t));
    class_assignement(*c, obj, pos, tmp);
    return (assignement_by_type(c, obj, pos, tmp));
}

char create_map_units(map_t *map, char *str, tmp_pt *tmp)
{
    int pos = m_alen((void **)map->entity);
    int i = 0;

    map->entity[pos] = malloc(sizeof(entity_t) * (tmp->size_x + 1));
    if (!map->entity[pos])
        return (FAILURE);
    map->entity[pos + 1] = NULL;
    for (int x = 0; str[i] && x < tmp->size_x; ++x, ++i) {
        if (assignement_ut(str[i], map->entity[pos], x, tmp) == FAILURE)
            return (FAILURE);
        if (assignement_u(&(str[i + 1]), map->entity[pos], x, tmp) == FAILURE)
            return (FAILURE);
        while (str[i + 1] &&
            (str[i] != ' ' || (str[i + 1] && str[i + 1] == ' ')))
            ++i;
    }
    return (SUCCESS);
}
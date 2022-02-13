/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "world.h"
#include "my.h"

char fill_data(entity_t *entity, perso_t **perso)
{
    if (entity->perso && entity->perso->type != SHOP) {
        for (int i = 0; perso[i]; ++i)
            if (perso[i]->type == entity->perso->type) {
                entity->perso->moves = perso[i]->moves;
                entity->perso->attack = perso[i]->attack;
                entity->perso->life = perso[i]->life;
                entity->perso->defense = perso[i]->defense;
                return (SUCCESS);
            }
    } else {
        return (SUCCESS);
    }
    return (error("error: Type unknown"));
}

char along_maps(map_t *map, perso_t **units)
{
    for (int j = 0; map->entity[j]; ++j) {
        for (int i = 0; i < map->st.size.x; ++i) {
            if (fill_data(&map->entity[j][i], units) == FAILURE)
                return (FAILURE);
        }
    }
    return (SUCCESS);
}

char complete_units_data(rpg_wd_t *rpg_wd)
{
    for (int i = 0; rpg_wd->maps[i]; ++i) {
        if (along_maps(rpg_wd->maps[i], rpg_wd->units) == FAILURE)
            return (FAILURE);
    }
    return (SUCCESS);
}
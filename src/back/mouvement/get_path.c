/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Created by charles,
*/

#include "movement.h"

int get_direction_incrementation(int direction)
{
    if (direction == TOP || direction == RIGHT)
        return -1;
    if (direction == BOT || direction == LEFT)
        return 1;
    return 0;
}

void get_x_path(map_t *map, int pos, int direction)
{
    int direction_incre = get_direction_incrementation(direction);
    int x = (int)map->entity_mvt.movement[pos].x;
    int y = (int)map->entity_mvt.movement[pos].y;
    entity_t **ent = map->entity;

    if (((ent[y][x + direction_incre].perso != NULL &&
        (ent[y][x + direction_incre].perso->type != SHOP
        && ent[y][x + direction_incre].perso->team != BLUE)) ||
        ent[y][x + direction_incre].perso == NULL) &&
        is_water(ent, y, x + direction_incre, map->st.size) == FALSE &&
        is_moutain(ent, y, x + direction_incre, map->st.size) == FALSE) {
        map->entity_mvt.movement[pos + 1].x = x + direction_incre;
        map->entity_mvt.movement[pos + 1].y = y;
        map->entity_mvt.movement[pos].z = direction;
    }
}

void get_y_path(map_t *map, int pos, int direction)
{
    int direction_incre = get_direction_incrementation(direction);
    int x = (int)map->entity_mvt.movement[pos].x;
    int y = (int)map->entity_mvt.movement[pos].y;
    entity_t **ent = map->entity;

    if (((ent[y + direction_incre][x].perso != NULL &&
        (ent[y + direction_incre][x].perso->type != SHOP
        && ent[y + direction_incre][x].perso->team != BLUE)) ||
        ent[y + direction_incre][x].perso == NULL) &&
        is_water(ent, y + direction_incre, x, map->st.size) == FALSE &&
        is_moutain(ent, y + direction_incre, x, map->st.size) == FALSE) {
        map->entity_mvt.movement[pos + 1].x = x;
        map->entity_mvt.movement[pos + 1].y = y + direction_incre;
        map->entity_mvt.movement[pos].z = direction;
    }
}

void get_path(map_t *map, int pos)
{
    int direction;

    direction = get_next_direction(map->mouse, map->entity_mvt.movement[pos]);
    if (direction == BOT || direction == TOP)
        get_x_path(map, pos, direction);
    else if (direction == LEFT || direction == RIGHT)
        get_y_path(map, pos, direction);
}
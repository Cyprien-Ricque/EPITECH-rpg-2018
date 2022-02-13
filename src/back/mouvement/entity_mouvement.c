/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Created by charles,
*/

#include "movement.h"

static int init_movement(struct entity_movement *mvt, map_t map)
{
    int nb_mvt;

    mvt->entity.x = map.mouse.x;
    mvt->entity.y = map.mouse.y;
    nb_mvt = map.entity[(int)mvt->entity.y][(int)mvt->entity.x].perso->moves;
    mvt->movement = malloc(sizeof(sfVector3f) * (nb_mvt + 2));
    if (!mvt->movement)
        return 84;
    for (int i = 0; i <= nb_mvt + 1; i++) {
        mvt->movement[i].x = -1;
        mvt->movement[i].y = -1;
    }
    mvt->movement[0].x = mvt->entity.x;
    mvt->movement[0].y = mvt->entity.y;
    return 0;
}

int is_next_to(sfVector3f mvt, map_t *map)
{
    int x_gap = get_gap((int)mvt.x, (int)map->mouse.x);
    int y_gap = get_gap((int)mvt.y, (int)map->mouse.y);

    if ((x_gap == 1 && y_gap == 0) || (y_gap == 1 && x_gap == 0))
        return 0;
    return 1;
}

void get_identical_path(map_t *map, int *nb_mvt)
{
    int i = 1;
    mvt_t mvt = map->entity_mvt;

    if (map->entity[(int)mvt.entity.y][(int)mvt.entity.x].perso != NULL)
        *nb_mvt = map->entity[(int)mvt.entity.y][(int)mvt.entity.x]
        .perso->moves;
    for (i = 0; mvt.movement[i].x != -1 && (mvt.movement[i].x != map->mouse.x
        || mvt.movement[i].y != map->mouse.y) &&
        is_next_to(mvt.movement[i], map) == 1; i++);
    i++;
    for (i = i; i <= *nb_mvt; i++) {
        map->entity_mvt.movement[i].x = -1;
        map->entity_mvt.movement[i].y = -1;
    }
}

int get_path_pos(mvt_t mvt)
{
    int n = 0;

    while (mvt.movement[n].x != -1)
        n++;
    return n;
}

int entity_movement(map_t *map)
{
    int pos;
    int nb_mvt = 0;

    if (map->entity_mvt.movement == NULL &&
        init_movement(&map->entity_mvt, *map) == 84)
        return FAILURE;
    get_identical_path(map, &nb_mvt);
    pos = get_path_pos(map->entity_mvt) - 1;
    if ((map->entity_mvt.movement[pos].x == map->mouse.x &&
        map->entity_mvt.movement[pos].y == map->mouse.y) ||
        (map->entity[(int)map->entity_mvt.movement[pos].y]
        [(int)map->entity_mvt.movement[pos].x].perso != NULL &&
        map->entity[(int)map->entity_mvt.movement[pos].y]
        [(int)map->entity_mvt.movement[pos].x].perso->team == RED)
        || pos >= nb_mvt)
        return 0;
    get_path(map, pos);
    return 0;
}
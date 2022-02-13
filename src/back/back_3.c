/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** MUL_my_rpg_2018,
*/


#include "movement.h"

void move_tank(summary_t *s, mtime_t *t)
{
    float actual_time;

    if (s->map.entity_mvt.save_time == -1)
        s->map.entity_mvt.save_time = t->seconds;
    actual_time = t->seconds - s->map.entity_mvt.save_time;
    if (!s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time]
        .y)][(int)(s->map.entity_mvt.movement[(int)actual_time].x)].perso &&
        s->map.entity_mvt.movement[1].x != -1 && actual_time - 1 >= 0) {
        s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time].y)]
        [(int)(s->map.entity_mvt.movement[(int)actual_time].x)].perso =
        s->map.entity[(int)(s->map.entity_mvt.movement[
        (int)actual_time - 1].y)][(int)(s->map.entity_mvt.movement[
        (int)actual_time - 1].x)].perso;
        s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time -
        1].y)][(int)(s->map.entity_mvt.movement[(int)actual_time -
        1].x)].perso = NULL;
    }
    tank_assignement(s, actual_time);
}

int user_move(map_t *map, int clicked)
{
    map->entity_mvt.save_time = -1;
    if (clicked == false && map->entity_mvt.movement &&
        map->entity_mvt.movement[1].x != -1)
        map->entity_mvt.status = USER_MOVE;
    if (clicked == true && (map->entity_mvt.movement != NULL ||
        (map->entity_mvt.movement == NULL &&
        map->entity[(int)map->mouse.y][(int)map->mouse.x].perso != NULL &&
        map->entity[(int)map->mouse.y][(int)map->mouse.x].perso->type !=
        SHOP && map->entity[(int)map->mouse.y][(int)map->mouse.x]
        .perso->type != SHOP && map->entity[(int)map->mouse.y][(int)
        map->mouse.x].perso->team != RED))) {
        entity_movement(map);
    }
    return (0);
}

void assignement_ai(map_t *map, int y, int x, int e)
{
    map->entity_mvt.movement[e + 1].x = x;
    map->entity_mvt.movement[e + 1].y = y;
    map->entity_mvt.movement[e + 1].z = BACK_LEFT;
    map->entity_mvt.movement[e + 2].x = -1;
    map->entity_mvt.movement[e + 2].y = -1;
    map->entity_mvt.movement[e].z = BACK_LEFT;
}

char go_to2(map_t *map, sfVector2f pos, int y, int x)
{
    map->entity_mvt.movement = malloc(sizeof(sfVector2f) * 100);
    int e = 0;

    if (!map->entity_mvt.movement)
        return (FAILURE);
    for (; pos.x < x || pos.x > x || pos.y < y || pos.y > y; ++e) {
        map->entity_mvt.movement[e].x = pos.x;
        map->entity_mvt.movement[e].y = pos.y;
        pos = xy_assignement2(&pos, y, x);
        assignement_ai(map, y, x, e);
    }
    if (good_path(map) == FALSE) {
        free(map->entity_mvt.movement);
        map->entity_mvt.movement = NULL;
        return (FAILURE);
    }
    return (SUCCESS);
}

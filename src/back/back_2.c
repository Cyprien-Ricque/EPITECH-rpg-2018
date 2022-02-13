/*
** EPITECH PROJECT, 2019
** back_2
** File description:
** back_2
*/

#include "movement.h"

char good_path(map_t *map)
{
    for (int i = 0; map->entity_mvt.movement[i].x != -1; ++i)
        map->entity_mvt.movement[i].z = get_next_direction(
            map->entity_mvt.movement[i + 1], map->entity_mvt.movement[i]);
    for (int i = 1; map->entity_mvt.movement[i].x != -1; ++i) {
        map->entity_mvt.movement[i].z = get_next_direction(
            map->entity_mvt.movement[i + 1], map->entity_mvt.movement[i]);
        if (is_moutain(map->entity, (int)map->entity_mvt.movement[i].y,
            (int)map->entity_mvt.movement[i].x, map->st.size) == TRUE ||
            is_water(map->entity, (int)map->entity_mvt.movement[i].y,
            (int)map->entity_mvt.movement[i].x, map->st.size) == TRUE
            || (map->entity[(int)map->entity_mvt.movement[i].y]
            [(int)map->entity_mvt.movement[i].x].perso &&
            map->entity[(int)map->entity_mvt.movement[i].y]
            [(int)map->entity_mvt.movement[i].x].perso->type != SHOP
            && map->entity[(int)map->entity_mvt.movement[i].y]
            [(int)map->entity_mvt.movement[i].x].perso->team == RED)) {
            return (FALSE);
        }
    }
    return (TRUE);
}

char go_to(map_t *map, sfVector2f pos, int y, int x)
{
    sfVector2f save = pos;
    int e = 0;

    map->entity_mvt.movement = malloc(sizeof(sfVector2f) * 100);
    for (; pos.x < x || pos.x > x || pos.y < y || pos.y > y; ++e) {
        map->entity_mvt.movement[e].x = pos.x;
        map->entity_mvt.movement[e].y = pos.y;
        pos = xy_assignement(&pos, y, x);
        assignement_ai(map, y, x, e);
    }
    if (good_path(map) == FALSE) {
        free(map->entity_mvt.movement);
        map->entity_mvt.movement = NULL;
        return (go_to2(map, save, y, x));
    }
    return (SUCCESS);
}

char tank_around(map_t *map, int j, int i)
{
    sfVector2f pos = {i, j};

    for (int y = j - 5; y <= j + 5; ++y) {
        for (int x = i - 5; x <= i + 5; ++x) {
            if (x >= 0 && y >= 0 && x < map->st.size.x - 1 &&
                y < map->st.size.y - 1 && map->entity[y][x].perso &&
                map->entity[y][x].perso->type != SHOP &&
                map->entity[y][x].perso->team == BLUE)
                if (go_to(map, pos, y, x) == SUCCESS)
                    return (SUCCESS);
        }
    }
    return (FAILURE);
}

void ai_move(summary_t *s)
{
    s->map.entity_mvt.save_time = -1;
    for (int j = 0; j < s->map.st.size.y - 1; ++j) {
        for (int i = 0; i < s->map.st.size.x - 1; ++i)
            if (s->map.entity[j][i].perso &&
                s->map.entity[j][i].perso->type != SHOP &&
                s->map.entity[j][i].perso->team == RED)
                if (tank_around(&s->map, j, i) == SUCCESS) {
                    s->map.entity_mvt.status = AI_MOVE;
                    return;
                }
    }
    s->map.entity_mvt.movement = NULL;
    s->map.entity_mvt.status = USER_TURN;
    s->turn.ia_turn = FALSE;
}

int game_back(summary_t *s, int clicked, mtime_t *t)
{
    if (s->win.event.type == sfEvtKeyPressed &&
        s->win.event.key.code == sfKeyEscape && s->map.entity_mvt.movement
        != NULL) {
        free(s->map.entity_mvt.movement);
        s->map.entity_mvt.movement = NULL;
        return 0;
    }
    if (s->map.entity_mvt.status == USER_TURN && s->map.mouse.x != -1 &&
        s->map.mouse.y != -1)
        user_move(&s->map, clicked);
    if (s->map.entity_mvt.status == AI_TURN)
        ai_move(s);
    if ((s->map.entity_mvt.status == USER_MOVE ||
        s->map.entity_mvt.status == AI_MOVE))
        move_tank(s, t);
    return (0);
}
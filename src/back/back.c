/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Back
*/

#include "movement.h"

void check_fight2(summary_t *s, float actual_time)
{
    if (s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time].y)]
    [(int)(s->map.entity_mvt.movement[(int)actual_time].x)].perso &&
        s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time].y)]
        [(int)(s->map.entity_mvt.movement[(int)actual_time].x)].perso->type !=
            SHOP &&
        (s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time].y)]
        [(int)(s->map.entity_mvt.movement[(int)actual_time].x)].perso->team ==
            BLUE && s->map.entity_mvt.status == AI_MOVE)) {
        set_figth2(s, actual_time);
    }
}

void check_fight(summary_t *s, float actual_time)
{
    if (s->map.entity_mvt.movement[(int)actual_time].y == -1 ||
        s->map.entity_mvt.movement[(int)actual_time].x == -1)
        return;
    if (s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time].y)]
    [(int)(s->map.entity_mvt.movement[(int)actual_time].x)].perso &&
        s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time].y)]
        [(int)(s->map.entity_mvt.movement[(int)actual_time].x)].perso->type !=
            SHOP &&
        (s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time].y)]
        [(int)(s->map.entity_mvt.movement[(int)actual_time].x)].perso->team ==
            RED && s->map.entity_mvt.status == USER_MOVE)) {
        set_figth1(s, actual_time);
    }
    check_fight2(s, actual_time);
}

void last_move2(summary_t *s, float actual_time)
{
    if (actual_time > 1)
        s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time].y)]
        [(int)(s->map.entity_mvt.movement[(int)actual_time].x)].
        perso->rotation = (char)(s->map.entity_mvt.movement
        [(int)actual_time - 1].z);
    s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time].y)]
    [(int)(s->map.entity_mvt.movement[(int)actual_time].x)].perso->percent = 0;
    s->map.entity_mvt.movement = NULL;
    if (s->turn.ia_turn == false)
            s->turn.ia_turn = true;
    else if (s->turn.ia_turn == true)
            s->turn.ia_turn = false;
    s->turn.f_call = true;
}

void last_move(summary_t *s, float actual_time)
{
    if (s->map.entity_mvt.movement[(int)actual_time + 1].x == -1 ||
        s->map.entity_mvt.movement[(int)actual_time + 1].y == -1 ||
        s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time +
            1].y)][(int)(s->map.entity_mvt.movement[(int)actual_time +
            1].x)].perso) {
        check_fight(s, actual_time + 1);
        if (s->map.entity_mvt.status == AI_MOVE)
            s->map.entity_mvt.status = USER_TURN;
        else
            s->map.entity_mvt.status = AI_TURN;
        if (s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time
            ].y)][(int)(s->map.entity_mvt.movement[(int)actual_time].x)]
            .perso == NULL)
            return;
        last_move2(s, actual_time);
    }
}

void tank_assignement(summary_t *s, float actual_time)
{
    s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time].y)]
    [(int)(s->map.entity_mvt.movement[(int)actual_time].x)].perso->rotation =
        (char)(s->map.entity_mvt.movement[(int)actual_time].z);
    s->map.entity[(int)(s->map.entity_mvt.movement[(int)actual_time].y)]
    [(int)(s->map.entity_mvt.movement[(int)actual_time].x)].perso->percent =
        actual_time - (int)actual_time;
    last_move(s, actual_time);
}
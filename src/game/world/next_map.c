/*
** EPITECH PROJECT, 2019
** next_map
** File description:
** next_map
*/

#include "my_rpg.h"

void go_to_next_map(summary_t *s)
{
    for (int i = 0; s->rpg_wd->maps[i]; ++i) {
        if (s->rpg_wd->maps[i]->name == s->map.next) {
            s->map = *s->rpg_wd->maps[i];
            s->map.entity_mvt.status = USER_TURN;
            s->map.entity_mvt.movement = NULL;
            s->turn.ia_turn = FALSE;
            pass_to_history(s);
            return;
        }
    }
}

int check_next_map(summary_t *s, int j, int i)
{
    if (s->map.entity_mvt.movement == NULL &&
        s->map.entity[j][i].type == LINK &&
        s->map.entity[j][i].perso &&
        s->map.entity[j][i].perso->type != SHOP &&
        s->map.entity[j][i].perso->team == BLUE) {
        if (s->map.name == 'd')
            return SUCCESS;
        go_to_next_map(s);
    }
    return FAILURE;
}

int next_map(summary_t *s)
{
    for (int j = 0; j < s->map.st.size.y - 1; ++j) {
        for (int i = 0; i < s->map.st.size.x - 1; ++i) {
            if (check_next_map(s, j, i) == SUCCESS)
                return SUCCESS;
        }
    }
    return FAILURE;
}

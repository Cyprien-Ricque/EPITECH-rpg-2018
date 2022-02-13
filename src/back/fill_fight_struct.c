/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Created by charles,
*/

#include "my_rpg.h"

void fill_fight_struct(summary_t *s, sfVector2f atk_pos,
    sfVector2f def_pos)
{
    s->fight.life_after_fight[0] = getl(s->map.entity, atk_pos, def_pos,
        BLUE);
    s->fight.life_after_fight[1] = getl(s->map.entity, def_pos, atk_pos,
        RED);
    s->fight.background[0] = get_back(s->map.entity, atk_pos, def_pos,
        BLUE);
    s->fight.background[1] = get_back(s->map.entity, def_pos, atk_pos,
        RED);
    s->fight.type[0] = get_unit_type(s->map.entity, atk_pos, def_pos,
        BLUE);
    s->fight.type[1] = get_unit_type(s->map.entity, def_pos, atk_pos,
        RED);
}

void life_after_fitgh(summary_t *s, sfVector2f *atk_pos, sfVector2f *def_pos,
    perso_t *save)
{
    s->map.entity[(int)(*def_pos).y][(int)(*def_pos).x].perso->life -= (int)(
        s->map.entity[(int)(*atk_pos).y][(int)(*atk_pos).x].perso->attack *
            ((float)s->map.entity[(int)(*def_pos).y][(int)(*def_pos).x].
            perso->defense / 70));
    s->map.entity[(int)(*atk_pos).y][(int)(*atk_pos).x].perso->life -= (int)(
        save->attack * ((float)s->map.entity[(int)(*def_pos).y][(int)(*def_pos)
        .x].perso->defense / 100));
}
/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** new tank
*/

#include "my_rpg.h"
#include "my.h"

void put_tank_on_map(summary_t *s, int j, int i, int e)
{
    if (s->inv.tanks_nb[e / 3] <= 0)
        return;
    s->inv.tanks_nb[e / 3]--;
    s->map.entity[j][i].perso = malloc(sizeof(perso_t));
    s->map.entity[j][i].perso->defense = s->rpg_wd->units[e / 3]->defense;
    s->map.entity[j][i].perso->life = s->rpg_wd->units[e / 3]->life;
    s->map.entity[j][i].perso->attack = s->rpg_wd->units[e / 3]->attack;
    s->map.entity[j][i].perso->team = s->rpg_wd->units[e / 3]->team;
    s->map.entity[j][i].perso->type = s->rpg_wd->units[e / 3]->type;
    s->map.entity[j][i].perso->rotation = s->rpg_wd->units[e / 3]->rotation;
    s->map.entity[j][i].perso->percent = s->rpg_wd->units[e / 3]->percent;
    s->map.entity[j][i].perso->moves = s->rpg_wd->units[e / 3]->moves;
}

char is_free(summary_t *s, int j, int i)
{
    if (j < s->map.st.size.y - 1 && i < s->map.st.size.x - 1 && j > 0 &&
        i > 0 && is_moutain(s->map.entity, j, i, s->map.st.size) == FALSE &&
        is_water(s->map.entity, j, i, s->map.st.size) == FALSE &&
        !s->map.entity[j][i].perso) {
        return (TRUE);
    }
    return (FALSE);
}

void place_new(summary_t *s, int j, int i, int e)
{
    for (int y = j - 1; y <= j + 1; ++y) {
        for (int x = i - 1; x <= i + 1; ++x) {
            if (is_free(s, y, x) == TRUE)
                return (put_tank_on_map(s, y, x, e));
        }
    }
}

void new_tank_map(summary_t *s, int e)
{
    if (s->shop.tanks_price[e])
    for (int j = 0; j < s->map.st.size.y; ++j) {
        for (int i = 0; i < s->map.st.size.x; ++i) {
            if (s->map.entity[j][i].perso &&
                s->map.entity[j][i].perso->type == SHOP)
                return (place_new(s, j, i, e));
        }
    }
}

void new_tank_from_inv(summary_t *s, int i)
{
    if (mouse_in_rectangle(s, s->shop.tanks[i]) == TRUE &&
        s->win.mouse.z == FALSE && s->win.prev_mouse.z == TRUE) {
        new_tank_map(s, i);
    }
}
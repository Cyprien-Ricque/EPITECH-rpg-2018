/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Created by charles,
*/

#include "my_rpg.h"
#include "movement.h"

sfVector2f get_entity(sfVector3f *movement, int pos)
{
    sfVector2f entity_pos;

    entity_pos.x = movement[pos].x;
    entity_pos.y = movement[pos].y;
    return entity_pos;
}

char getl(entity_t **entity, sfVector2f atk_pos, sfVector2f def_pos, char team)
{
    char life;
    if (entity[(int)atk_pos.y][(int)atk_pos.x].perso->team == team)
        life = entity[(int)atk_pos.y][(int)atk_pos.x].perso->life;
    else
        life = entity[(int)def_pos.y][(int)def_pos.x].perso->life;
    if (life <= 0)
        life = 0;
    if (life < 20 && life > 0)
        return 1;
    return life / 20;
}

char get_back(entity_t **entity, sfVector2f atk_pos, sfVector2f def_pos,
    char team)
{
    if (entity[(int)atk_pos.y][(int)atk_pos.x].perso->team == team)
        return entity[(int)atk_pos.y][(int)atk_pos.x].type;
    else
        return entity[(int)def_pos.y][(int)def_pos.x].type;

}

char get_unit_type(entity_t **entity, sfVector2f atk_pos, sfVector2f def_pos,
    char team)
{
    char type;

    if (entity[(int)atk_pos.y][(int)atk_pos.x].perso->team == team)
        type = entity[(int)atk_pos.y][(int)atk_pos.x].perso->type;
    else
        type = entity[(int)def_pos.y][(int)def_pos.x].perso->type;
    if (type == -12)
        return 0;
    if (type == -11)
        return 2;
    if (type == -10)
        return 1;
    return type;
}

int fight_calcul(summary_t *s)
{
    int pos = get_path_pos(s->map.entity_mvt) - 1;
    sfVector2f atk_pos = get_entity(s->map.entity_mvt.movement, pos - 1);
    sfVector2f def_pos = get_entity(s->map.entity_mvt.movement, pos);
    perso_t *save = s->map.entity[(int)def_pos.y][(int)def_pos.x].perso;

    s->fight.life[0] = getl(s->map.entity, atk_pos, def_pos, BLUE);
    s->fight.life[1] = getl(s->map.entity, def_pos, atk_pos, RED);
    life_after_fitgh(s, &atk_pos, &def_pos, save);
    fill_fight_struct(s, atk_pos, def_pos);
    if ((s->map.entity[(int)atk_pos.y][(int)atk_pos.x].perso->team == BLUE
        && s->map.entity[(int)def_pos.y][(int)def_pos.x].perso->life <= 0)
        || (s->map.entity[(int)def_pos.y][(int)def_pos.x].perso->team == BLUE
        && s->map.entity[(int)atk_pos.y][(int)atk_pos.x].perso->life <= 0)) {
        s->usexp.money += 200;
        s->usexp.experience += 50;
    }
    s->scene_number[0] = 5;
    s->scene_number[1] = -1;
    return (0);
}
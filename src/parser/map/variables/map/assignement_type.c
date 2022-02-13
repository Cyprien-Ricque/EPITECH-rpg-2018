/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

void class_assignement(char c, entity_t *obj, int pos, tmp_pt *tmp)
{
    if (c == tmp->basic)
        obj[pos].perso->type = SOLDIER;
    if (c == tmp->fast)
        (*obj[pos].perso).type = TANK;
    if (c == tmp->strong)
        obj[pos].perso->type = HELICOPTER;
    if (c == tmp->shop)
        obj[pos].perso->type = SHOP;
}

char team_assignement(char *c, entity_t *obj, int pos, tmp_pt *tmp)
{
    if (*c == ' ' || !*c)
        return (error("An unit need a team"));
    if (*c == tmp->red)
        obj[pos].perso->team = RED;
    else if (*c == tmp->blue)
        obj[pos].perso->team = BLUE;
    else
        return (error("Invalid team"));
    return (SUCCESS);
}

char rotation_assignement(char *c, entity_t *obj, int pos, tmp_pt *tmp)
{
    if (*c == ' ' || !*c)
        return (error("An entity need a rotation"));
    if (*c == tmp->front_left)
        obj[pos].perso->rotation = FRONT_LEFT;
    if (*c == tmp->front_right)
        obj[pos].perso->rotation = FRONT_RIGHT;
    if (*c == tmp->back_right)
        obj[pos].perso->rotation = BACK_RIGHT;
    if (*c == tmp->back_left)
        obj[pos].perso->rotation = BACK_LEFT;
    if (*c != tmp->front_left && *c != tmp->front_right &&
        *c != tmp->back_right && *c != tmp->back_left)
        return (error("Invalid team"));
    obj[pos].perso->percent = 0;
    return (SUCCESS);
}

/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Created by charles,
*/

#include "my_rpg.h"
#include "my.h"

char init_tank_stat(tanks_sb *tank_dt)
{
    sfVector2f size = {.x = 80, .y = 75};

    tank_dt->stats = sfRectangleShape_create();
    if (!tank_dt->stats)
        return (FAILURE);
    sfRectangleShape_setFillColor(tank_dt->stats, sfWhite);
    sfRectangleShape_setOutlineColor(tank_dt->stats, sfGreen);
    sfRectangleShape_setOutlineThickness(tank_dt->stats, 1);
    sfRectangleShape_setSize(tank_dt->stats, size);
    return (SUCCESS);
}

char init_tank_text(tanks_sb *tank_dt)
{
    sfFont *font = sfFont_createFromFile("assets/font_menu.ttf");

    tank_dt->text = sfText_create();
    if (!tank_dt->text)
        return (FAILURE);
    sfText_setFont(tank_dt->text, font);
    sfText_setColor(tank_dt->text, sfBlack);
    sfText_setCharacterSize(tank_dt->text, 15);
    return (SUCCESS);
}

char init_tank_life(tanks_sb *tank_dt)
{
    tank_dt->life = sfRectangleShape_create();

    if (!tank_dt->life)
        return (FAILURE);
    sfRectangleShape_setFillColor(tank_dt->life, sfRed);
    return (SUCCESS);
}

char init_tanks_stat(summary_t *summary)
{
    if (init_tank_stat(&summary->tank_dt) == FAILURE ||
        init_tank_text(&summary->tank_dt) == FAILURE ||
        init_tank_life(&summary->tank_dt) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Created by charles,
*/

#include "my_rpg.h"
#include "my.h"

char init_circle(user_sprites_t *usp)
{
    sfVector2f pos = {.x = 5, .y = 5};

    usp->lvl = sfCircleShape_create();
    if (!usp->lvl)
        return (FAILURE);
    sfCircleShape_setFillColor(usp->lvl, light_grey_b());
    sfCircleShape_setOutlineColor(usp->lvl, dark(light_grey_b()));
    sfCircleShape_setOutlineThickness(usp->lvl, 1);
    sfCircleShape_setRadius(usp->lvl, 30);
    sfCircleShape_setPosition(usp->lvl, pos);
    return (SUCCESS);
}

char init_text(user_sprites_t *usp)
{
    sfFont *font = sfFont_createFromFile("assets/font_menu.ttf");
    sfVector2f pos = {.x = 75, .y = 33};

    usp->statst = sfText_create();
    if (!usp->statst)
        return (FAILURE);
    sfText_setFont(usp->statst, font);
    sfText_setColor(usp->statst, sfBlack);
    sfText_setCharacterSize(usp->statst, 15);
    sfText_setPosition(usp->statst, pos);
    return (SUCCESS);
}

char init_exp(user_sprites_t *usp)
{
    sfVector2f pos = {.x = 98, .y = 57};

    usp->experience = sfRectangleShape_create();
    if (!usp->experience)
        return (FAILURE);
    sfRectangleShape_setPosition(usp->experience, pos);
    return (SUCCESS);
}

char init_user_exp(summary_t *summary)
{
    if (init_circle(&summary->usexp.usp) == FAILURE)
        return (FAILURE);
    if (init_pp(&summary->usexp.usp) == FAILURE)
        return (FAILURE);
    if (init_stats(&summary->usexp.usp) == FAILURE ||
        init_exp(&summary->usexp.usp) == FAILURE)
        return (FAILURE);
    summary->usexp.level = 1;
    summary->usexp.money = 500;
    summary->usexp.experience = 0;
    if (init_text(&summary->usexp.usp) == FAILURE)
        return (FAILURE);
    summary->usexp.open = FALSE;
    return (init_inventory(summary));
}
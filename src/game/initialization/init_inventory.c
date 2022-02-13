/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Created by charles,
*/

#include "my_rpg.h"
#include "my.h"

char init_inv_win(inv_t *inv)
{
    sfVector2f size = {.x = 400, .y = 150};
    sfVector2f pos = {.x = 1920 / 2 - size.x / 2, .y = 1080 / 2 -
        (size.y + 150) / 2};

    inv->inv = sfRectangleShape_create();
    if (!inv->inv)
        return (FAILURE);
    sfRectangleShape_setFillColor(inv->inv, sfWhite);
    sfRectangleShape_setOutlineColor(inv->inv, sfGreen);
    sfRectangleShape_setOutlineThickness(inv->inv, 1);
    sfRectangleShape_setSize(inv->inv, size);
    sfRectangleShape_setPosition(inv->inv, pos);
    return (SUCCESS);
}

char init_inv_basic(inv_t *inv)
{
    inv->text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font_menu.ttf");

    if (!inv->text)
        return (FAILURE);
    sfText_setFont(inv->text, font);
    sfText_setColor(inv->text, sfBlack);
    sfText_setCharacterSize(inv->text, 30);
    return (SUCCESS);
}

char init_inv_tanks(inv_t *inv)
{
    sfTexture *tmp[3];
    sfVector2f pos[3] = {
        {.x = 1920 / 2 - 498 / 2 + 30, .y = 1080 / 2 - 250 / 2},
        {.x = 1920 / 2 - 498 / 2 + 180, .y = 1080 / 2 - 250 / 2},
        {.x = 1920 / 2 - 498 / 2 + 320, .y = 1080 / 2 - 250 / 2}};
    sfVector2f scale = {0.4, 0.5};

    tmp[0] = sfTexture_createFromFile(TANK_INV_P, NULL);
    tmp[1] = sfTexture_createFromFile(TANK_INV_G, NULL);
    tmp[2] = sfTexture_createFromFile(TANK_INV_Y, NULL);
    for (int i = 0; i < 3; ++i) {
        inv->tanks[i] = sfSprite_create();
        if (!inv->tanks[i] || !tmp[i])
            return (FAILURE);
        sfSprite_setTexture(inv->tanks[i], tmp[i], sfTrue);
        sfSprite_setScale(inv->tanks[i], scale);
        sfSprite_setPosition(inv->tanks[i], pos[i]);
    }
    return (SUCCESS);
}

char init_back_inventory(summary_t *summary)
{
    sfVector2f pos = {0, 480};

    summary->inv.tt_inv = TextureFromFile(PATH_INV, NULL);
    summary->inv.spr_inv = sfSprite_create();
    if (!summary->inv.tt_inv || !summary->inv.spr_inv)
        return (FAILURE);
    sfSprite_setPosition(summary->inv.spr_inv, pos);
    sfSprite_setTexture(summary->inv.spr_inv, summary->inv.tt_inv, sfTrue);
    return (SUCCESS);
}

char init_inventory(summary_t *summary)
{
    summary->turn.f_call = false;
    if (init_inv_win(&summary->inv) == FAILURE ||
        init_inv_basic(&summary->inv) == FAILURE ||
        init_inv_tanks(&summary->inv) == FAILURE ||
        init_back_inventory(summary) == FAILURE)
        return (FAILURE);
    summary->inv.tanks_nb[0] = 0;
    summary->inv.tanks_nb[1] = 0;
    summary->inv.tanks_nb[2] = 0;
    return (init_shop(summary));
}
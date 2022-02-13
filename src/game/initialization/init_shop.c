/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Created by charles,
*/

#include "my_rpg.h"
#include "my.h"

const char *tanks_shop[] = TANK_SHOP

char init_shop_win(shop_t *shop)
{
    sfVector2f size = {.x = 400, .y = 150};
    sfVector2f pos = {.x = 1920 / 2 - size.x / 2, .y = 1080 / 2 -
        (size.y + 150) / 2};

    shop->shop = sfRectangleShape_create();
    if (!shop->shop)
        return (FAILURE);
    sfRectangleShape_setFillColor(shop->shop, sfWhite);
    sfRectangleShape_setOutlineColor(shop->shop, sfGreen);
    sfRectangleShape_setOutlineThickness(shop->shop, 1);
    sfRectangleShape_setSize(shop->shop, size);
    sfRectangleShape_setPosition(shop->shop, pos);
    return (SUCCESS);
}

char init_shop_basic(shop_t *shop)
{
    sfFont *font = sfFont_createFromFile("assets/font_menu.ttf");

    shop->text = sfText_create();
    if (!shop->text)
        return (FAILURE);
    sfText_setFont(shop->text, font);
    sfText_setColor(shop->text, sfBlack);
    sfText_setCharacterSize(shop->text, 30);
    return (SUCCESS);
}

char init_shop_tanks(shop_t *shop)
{
    sfTexture *tmp;
    sfVector2f pos[3] = {
        {.x = 1920 / 2 - 490 / 2 + 35, .y = 1080 / 2 - 250 / 2},
        {.x = 1920 / 2 - 498 / 2 + 175, .y = 1080 / 2 - 250 / 2},
        {.x = 1920 / 2 - 498 / 2 + 310, .y = 1080 / 2 - 250 / 2}};
    sfVector2f size = {150, 120};

    for (int i = 0; i < 9; ++i) {
        shop->tanks[i] = sfRectangleShape_create();
        tmp = sfTexture_createFromFile(tanks_shop[i], NULL);
        if (!shop->tanks[i] || !tmp)
            return (FAILURE);
        sfRectangleShape_setTexture(shop->tanks[i], tmp, sfTrue);
        sfRectangleShape_setSize(shop->tanks[i], size);
        sfRectangleShape_setPosition(shop->tanks[i], pos[(int)(i / 3)]);
    }
    return (SUCCESS);
}

char init_back_shop(summary_t *summary)
{
    sfVector2f pos = {.x = 0, .y = 480};

    summary->shop.tt_shop = TextureFromFile(PATH_SHOP, NULL);
    summary->shop.spr_shop = sfSprite_create();
    if (!summary->shop.tt_shop || !summary->shop.spr_shop)
        return (FAILURE);
    sfSprite_setTexture(summary->shop.spr_shop, summary->shop.tt_shop, sfTrue);
    sfSprite_setPosition(summary->shop.spr_shop, pos);
    return (SUCCESS);
}

char init_shop(summary_t *summary)
{
    if (init_shop_win(&summary->shop) == FAILURE ||
        init_shop_basic(&summary->shop) == FAILURE ||
        init_shop_tanks(&summary->shop) == FAILURE ||
        init_back_shop(summary) == FAILURE)
        return (FAILURE);
    summary->shop.tanks_price[0] = 100;
    summary->shop.tanks_price[1] = 150;
    summary->shop.tanks_price[2] = 300;
    return (init_stars(summary));
}
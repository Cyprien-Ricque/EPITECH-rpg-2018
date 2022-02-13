/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Created by charles,
*/

#include "my_rpg.h"
#include "my.h"

char *stars_sprites[] = STARS;

char init_back(summary_t *s)
{
    sfTexture *back =
    sfTexture_createFromFile("assets/back_new_tank.png", NULL);
    s->shop.back = sfSprite_create();

    if (!s->shop.back || !back)
        return (FAILURE);
    sfSprite_setTexture(s->shop.back, back, sfFalse);
    return (SUCCESS);
}

char init_stars(summary_t *s)
{
    sfTexture *tmp[2] = {sfTexture_createFromFile(stars_sprites[0], NULL),
        sfTexture_createFromFile(stars_sprites[1], NULL)};
    sfVector2f size = {200, 200};
    sfVector2f pos = {1920 / 2 - size.x / 2, 1080 / 2 - size.y};

    for (int i = 0; i < 2; ++i) {
        s->shop.stars[i] = sfRectangleShape_create();
        if (!s->shop.stars[i] || !tmp[i])
            return (FAILURE);
        sfRectangleShape_setTexture(s->shop.stars[i], tmp[i], sfTrue);
        sfRectangleShape_setSize(s->shop.stars[i], size);
        sfRectangleShape_setPosition(s->shop.stars[i], pos);
    }
    s->shop.new_time = -1;
    return (init_back(s));
}
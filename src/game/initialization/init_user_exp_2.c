/*
** EPITECH PROJECT, 2019
** init_user_exp_2
** File description:
** init_user_exp_2
*/

#include "my_rpg.h"
#include "my.h"

char init_pp(user_sprites_t *usp)
{
    sfTexture *tmp = sfTexture_createFromFile(PP, NULL);
    sfVector2f pos = {.x = 10, .y = 10};
    sfVector2f size = {.x = 50, .y = 50};

    usp->pp = sfRectangleShape_create();
    if (!usp->pp || !tmp)
        return (FAILURE);
    sfRectangleShape_setTexture(usp->pp, tmp, sfTrue);
    sfRectangleShape_setPosition(usp->pp, pos);
    sfRectangleShape_setSize(usp->pp, size);
    return (SUCCESS);
}

char init_stats(user_sprites_t *usp)
{
    sfVector2f pos = {.x = 30, .y = 30};
    sfVector2f size = {.x = 140, .y = 60};

    usp->stats = sfRectangleShape_create();
    if (!usp->stats)
        return (FAILURE);
    sfRectangleShape_setFillColor(usp->stats, dark(light_grey_b()));
    sfRectangleShape_setOutlineColor(usp->stats, sfBlue);
    sfRectangleShape_setOutlineThickness(usp->stats, 1);
    sfRectangleShape_setPosition(usp->stats, pos);
    sfRectangleShape_setSize(usp->stats, size);
    return (SUCCESS);
}
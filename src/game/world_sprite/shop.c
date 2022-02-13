/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** world sprite
*/

#include "my_rpg.h"
#include "world.h"
#include "my.h"

char create_shape_shop(cube_t *cube)
{
    sfTexture *texture;

    for (int i = 0; i < TANK_NB; ++i) {
        cube->shapes.shop[i] = sfConvexShape_create();
        texture = sfTexture_createFromFile("assets/tank_shop.png", NULL);
        if (!texture || !cube->shapes.shop[i])
            return (FAILURE);
        sfConvexShape_setTexture(cube->shapes.shop[i], texture, sfTrue);
    }
    return (SUCCESS);
}

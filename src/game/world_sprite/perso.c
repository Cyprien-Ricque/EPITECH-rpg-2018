/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** world sprite
*/

#include "my_rpg.h"
#include "world.h"
#include "my.h"

const char *shape_tank_blue[ENTITY_NB][TANK_NB] = {TANK_BLUE_Y, TANK_BLUE_G,
    TANK_BLUE_P};

const char *shape_tank_red[ENTITY_NB][TANK_NB] = {TANK_RED_Y, TANK_RED_G,
    TANK_RED_P};

char create_shape_tank_blue(cube_t *cube)
{
    sfTexture *texture;

    for (int e = 0; e < ENTITY_NB; ++e)
        for (int i = 0; i < TANK_NB; ++i) {
            cube->shapes.tank_blue[e][i] = sfConvexShape_create();
            texture = sfTexture_createFromFile(shape_tank_blue[e][i], NULL);
            if (!texture || !cube->shapes.tank_blue[i])
                return (FAILURE);
            sfConvexShape_setTexture(cube->shapes.tank_blue[e][i], texture,
                sfFalse);
        }
    return (SUCCESS);
}

char create_shape_tank_red(cube_t *cube)
{
    sfTexture *texture;

    for (int e = 0; e < ENTITY_NB; ++e)
        for (int i = 0; i < TANK_NB; ++i) {
            cube->shapes.tank_red[e][i] = sfConvexShape_create();
            texture = sfTexture_createFromFile(shape_tank_red[e][i], NULL);
            if (!texture || !cube->shapes.tank_red[i])
                return (FAILURE);
            sfConvexShape_setTexture(cube->shapes.tank_red[e][i], texture,
                sfFalse);
        }
    return (SUCCESS);
}

char create_shape_tank(cube_t *cube)
{
    if (create_shape_tank_blue(cube) == FAILURE)
        return (FAILURE);
    if (create_shape_tank_red(cube) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
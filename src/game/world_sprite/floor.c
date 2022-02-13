/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** world sprite
*/

#include "my_rpg.h"
#include "world.h"
#include "my.h"

const char *sprites_grass[GRASS_NB] = S_GRASS;

char create_sprite_grass(cube_t *cube)
{
    sfTexture *text;

    for (int i = 0; i < GRASS_NB; ++i) {
        cube->shapes.shape_grass[i] = sfConvexShape_create();
        text = sfTexture_createFromFile(sprites_grass[i], NULL);
        if (!text || !cube->shapes.shape_grass[i])
            return (FAILURE);
        sfConvexShape_setTexture(cube->shapes.shape_grass[i], text, sfTrue);
    }
    return (SUCCESS);
}

char create_sprite_water(cube_t *cube)
{
    sfTexture *text;

    cube->shapes.shape_water = sfConvexShape_create();
    text = sfTexture_createFromFile(S_WATER, NULL);
    if (!text || !cube->shapes.shape_water)
        return (FAILURE);
    sfConvexShape_setTexture(cube->shapes.shape_water, text, sfTrue);
    return (SUCCESS);
}

char create_sprite_floor(cube_t *cube)
{
    if (create_sprite_grass(cube) == FAILURE)
        return (FAILURE);
    if (create_sprite_sand(cube) == FAILURE ||
        create_sprite_bush(cube) == FAILURE ||
        create_sprite_dirt(cube) == FAILURE ||
        create_sprite_snow(cube) == FAILURE ||
        create_sprite_water(cube) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** world sprite
*/

#include "my_rpg.h"
#include "world.h"
#include "my.h"

char create_sprite_sand(cube_t *cube)
{
    sfTexture *text;

    cube->shapes.shape_sand = sfConvexShape_create();
    text = sfTexture_createFromFile(S_SAND, NULL);
    if (!text || !cube->shapes.shape_sand)
        return (FAILURE);
    sfConvexShape_setTexture(cube->shapes.shape_sand, text, sfTrue);
    return (SUCCESS);
}

char create_sprite_snow(cube_t *cube)
{
    sfTexture *text;

    cube->shapes.shape_snow = sfConvexShape_create();
    text = sfTexture_createFromFile(S_SNOW, NULL);
    if (!text || !cube->shapes.shape_snow)
        return (FAILURE);
    sfConvexShape_setTexture(cube->shapes.shape_snow, text, sfTrue);
    return (SUCCESS);
}

char create_sprite_bush(cube_t *cube)
{
    sfTexture *text;

    cube->shapes.shape_bush = sfConvexShape_create();
    text = sfTexture_createFromFile(S_BUSH, NULL);
    if (!text || !cube->shapes.shape_bush)
        return (FAILURE);
    sfConvexShape_setTexture(cube->shapes.shape_bush, text, sfTrue);
    return (SUCCESS);
}

char create_sprite_dirt(cube_t *cube)
{
    sfTexture *text;

    cube->shapes.shape_dirt = sfConvexShape_create();
    text = sfTexture_createFromFile(S_DIRT, NULL);
    if (!text || !cube->shapes.shape_dirt)
        return (FAILURE);
    sfConvexShape_setTexture(cube->shapes.shape_dirt, text, sfTrue);
    return (SUCCESS);
}
/*
** EPITECH PROJECT, 2018
** window
** File description:
** display a window and keep it open
*/

#include "my_rpg.h"
#include "world.h"

sfColor light_grey_b(void)
{
    sfColor light_grey = sfWhite;

    light_grey.b -= 40;
    light_grey.r -= 40;
    light_grey.g -= 40;
    return (light_grey);
}

sfColor dark_green(void)
{
    sfColor d_green;

    d_green.r = 0;
    d_green.g = 150;
    d_green.b = 0;
    d_green.a = 255;
    return (d_green);
}

sfColor light(sfColor color)
{
    if (color.b > 100)
        color.b -= 100;
    else
        color.b = 0;
    if (color.r > 100)
        color.r -= 100;
    else
        color.r = 0;
    if (color.g > 100)
        color.g -= 100;
    else
        color.g = 0;
    return (color);
}

sfColor sand_color(void)
{
    sfColor sand;

    sand.r = 192 - 20;
    sand.g = 180 - 20;
    sand.b = 0;
    sand.a = 255;
    return (sand);
}

sfColor dark(sfColor color)
{
    if (color.b > 27)
        color.b -= 27;
    else
        color.b = 0;
    if (color.r > 27)
        color.r -= 27;
    else
        color.r = 0;
    if (color.g > 27)
        color.g -= 27;
    else
        color.g = 0;
    return (color);
}
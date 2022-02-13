/*
** EPITECH PROJECT, 2018
** window
** File description:
** display a window and keep it open
*/

#include "my_rpg.h"
#include "world.h"
#include "my.h"

sfColor no_color(void)
{
    sfColor no_color;

    no_color.r = 0;
    no_color.g = 0;
    no_color.b = 0;
    no_color.a = 0;
    return (no_color);
}

sfColor blue_rd(int rd)
{
    sfColor blue = sfBlue;

    blue.a = 160 + rd;
    blue.b -= rd % 10;
    return (blue);
}

sfColor water_c(void)
{
    sfColor blue = sfBlue;

    blue.a = 180;
    return (blue);
}

sfColor grey(void)
{
    sfColor grey = sfWhite;

    grey.b -= 100;
    grey.r -= 100;
    grey.g -= 100;
    return (grey);
}

sfColor light_grey(void)
{
    sfColor light_grey = sfWhite;

    light_grey.b -= 60;
    light_grey.r -= 60;
    light_grey.g -= 60;
    return (light_grey);
}

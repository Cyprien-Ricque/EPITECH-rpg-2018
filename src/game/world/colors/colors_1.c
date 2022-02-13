/*
** EPITECH PROJECT, 2018
** window
** File description:
** display a window and keep it open
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/System.h>
#include <stdio.h>
#include "time.h"
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Event.h>
#include <math.h>

sfColor brown(void)
{
    sfColor brown;

    brown.r = 150 - 20;
    brown.g = 84 - 20;
    brown.b = 55 - 20;
    brown.a = 255;
    return (brown);
}

sfColor brown_2(void)
{
    sfColor brown;

    brown.r = 150 - 55;
    brown.g = 84 - 55;
    brown.b = 55 - 55;
    brown.a = 255;
    return (brown);
}

sfColor green(void)
{
    sfColor green;

    green.r = 26 - 20;
    green.g = 198 - 20;
    green.b = 56 - 20;
    green.a = 255;
    return (green);
}
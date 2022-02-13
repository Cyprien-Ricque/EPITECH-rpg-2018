/*
** EPITECH PROJECT, 2019
** offset.c
** File description:
** offset for framerate indépendance of tank animation
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>
#include <unistd.h>

int dif_offset_tank(float t_fire)
{
    int r_t_fire = (int)(t_fire / 0.15);

    return (r_t_fire % 2);
}

int dif_offset_exp(float t_fire)
{
    int r_t_fire = (int)((t_fire - 5.0) / 0.15);

    if (r_t_fire >= 7)
        return (7);
    return (r_t_fire % 7);
}
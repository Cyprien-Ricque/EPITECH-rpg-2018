/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Created by charles,
*/

#include "movement.h"

int get_gap(int num1, int num2)
{
    int result = 0;

    result = num1 - num2;
    if (result <= 0)
        return result * -1;
    return result;
}

int get_next_direction(sfVector3f mouse, sfVector3f movement)
{
    int x_gap = get_gap((int)movement.x, (int)mouse.x);
    int y_gap = get_gap((int)movement.y, (int)mouse.y);

    if (mouse.x < movement.x && x_gap >= y_gap)
        return (BACK_LEFT);
    if (mouse.y < movement.y && y_gap > x_gap)
        return (BACK_RIGHT);
    if (mouse.x > movement.x && x_gap >= y_gap)
        return (FRONT_RIGHT);
    return (FRONT_LEFT);
}
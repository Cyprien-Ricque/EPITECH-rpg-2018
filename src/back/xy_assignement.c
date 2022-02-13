/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** MUL_my_rpg_2018,
*/

#include "movement.h"

sfVector2f xy_assignement(sfVector2f *pos, int y, int x)
{
    if ((*pos).y < y || (*pos).y > y) {
        if ((*pos).y < y)
            ++(*pos).y;
        else
            --(*pos).y;
    } else {
        if ((*pos).x < x)
            ++(*pos).x;
        else
            --(*pos).x;
    }
    return (*pos);
}

sfVector2f xy_assignement2(sfVector2f *pos, int y, int x)
{
    if ((*pos).x < x || (*pos).x > x) {
        if ((*pos).x < x)
            ++(*pos).x;
        else
            --(*pos).x;
    } else {
        if ((*pos).y < y)
            ++(*pos).y;
        else
            --(*pos).y;
    }
    return (*pos);
}
/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

int co(sfVector2f top, sfVector2f right, int x, int y)
{
    if (x > top.x && y < right.y) {
        if ((y - top.y) * (right.x - top.x) < (right.y - top.y) * (x - top.x))
            return (FALSE);
    }
    return (TRUE);
}

int ct(sfVector2f bottom, sfVector2f right, int x, int y)
{
    if (x > bottom.x && y > right.y) {
        if ((bottom.y - y) * (right.x - bottom.x) <
            (bottom.y - right.y) * (x - bottom.x))
            return (FALSE);
    }
    return (TRUE);
}

int cth(sfVector2f bottom, sfVector2f left, int x, int y)
{
    if (x < bottom.x && y > left.y) {
        if ((bottom.y - y) * (bottom.x - left.x) <
            (bottom.y - left.y) * (bottom.x - x))
            return (FALSE);
    }
    return (TRUE);
}

int check_point(sfVector2f *point, int x, int y)
{
    sfVector2f left = find_left(point[0], point[1], point[2], point[3]);
    sfVector2f right = find_right(point[0], point[1], point[2], point[3]);
    sfVector2f bottom = find_bottom(point[0], point[1], point[2], point[3]);
    sfVector2f top = find_top(point[0], point[1], point[2], point[3]);

    if (x < left.x || x > right.x || y > bottom.y || y < top.y)
        return (FALSE);
    if (x < top.x && y < left.y) {
        if ((y - top.y) * (top.x - left.x) < (left.y - top.y) * (top.x - x))
            return (FALSE);
    }
    if (x < bottom.x && y > left.y) {
        if ((bottom.y - y) * (bottom.x - left.x) <
            (bottom.y - left.y) * (bottom.x - x))
            return (FALSE);
    }
    if (co(top, right, x, y) == FALSE || ct(bottom, right, x, y) == FALSE ||
        cth(bottom, left, x, y) == FALSE)
        return (FALSE);
    return (TRUE);
}
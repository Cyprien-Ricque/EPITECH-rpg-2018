/*
** EPITECH PROJECT, 2018
** calcule
** File description:
** calcule
*/

#include "my_rpg.h"
#include "world.h"

sfVector2f find_left(sfVector2f a, sfVector2f b, sfVector2f c, sfVector2f d)
{
    sfVector2f left = a;

    if (left.x > b.x || (left.x == b.x && b.y > left.y))
        left = b;
    if (left.x > c.x || (left.x == c.x && c.y > left.y))
        left = c;
    if (left.x > d.x || (left.x == d.x && d.y > left.y))
        left = d;
    left.x -= 1;
    return (left);
}

sfVector2f find_right(sfVector2f a, sfVector2f b, sfVector2f c, sfVector2f d)
{
    sfVector2f right = a;

    if (right.x < b.x || (right.x == b.x && b.y < right.y))
        right = b;
    if (right.x < c.x || (right.x == c.x && c.y < right.y))
        right = c;
    if (right.x < d.x || (right.x == d.x && d.y < right.y))
        right = d;
    right.x += 0.5;
    return (right);

}

sfVector2f find_top(sfVector2f a, sfVector2f b, sfVector2f c, sfVector2f d)
{
    sfVector2f top = a;

    if (top.y > b.y || (top.y == b.y && b.x > top.x))
        top = b;
    if (top.y > c.y || (top.y == c.y && c.x > top.x))
        top = c;
    if (top.y > d.y || (top.y == d.y && d.x > top.x))
        top = d;
    top.y -= 0.5;
    return (top);
}

sfVector2f find_bottom(sfVector2f a, sfVector2f b, sfVector2f c, sfVector2f d)
{
    sfVector2f bottom = a;

    if (bottom.y < b.y || (bottom.y == b.y && b.x < bottom.x))
        bottom = b;
    if (bottom.y < c.y || (bottom.y == c.y && c.x < bottom.x))
        bottom = c;
    if (bottom.y < d.y || (bottom.y == d.y && d.x < bottom.x))
        bottom = d;
    bottom.y += 0.5;
    return (bottom);
}
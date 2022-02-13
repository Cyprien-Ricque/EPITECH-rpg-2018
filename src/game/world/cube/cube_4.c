/*
** EPITECH PROJECT, 2019
** cube_4
** File description:
** cube_4
*/

#include "my_rpg.h"
#include "world.h"

sfVector2f find_origin(points_t *points)
{
    sfVector2f origin;

    origin.x =
        (points->back_2d[2].x + points->back_2d[3].x + points->front_2d[3].x) /
        3;
    origin.y =
        (points->back_2d[2].y + points->back_2d[3].y + points->front_2d[3].y) /
        3;
    return (origin);
}

void top_1(summary_t *s, int k, int j, int i)
{
    sfConvexShape *tmp = top_color1(s, k, j, i);

    sfConvexShape_setPointCount(tmp, 3);
    sfConvexShape_setPoint(tmp, 0, s->map.cube.points.back_2d[2]);
    sfConvexShape_setPoint(tmp, 1, s->map.cube.points.back_2d[3]);
    sfConvexShape_setPoint(tmp, 2, s->map.cube.points.front_2d[3]);
    sfRenderWindow_drawConvexShape(s->win.window, tmp, NULL);
}
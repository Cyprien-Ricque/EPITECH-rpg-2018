/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

void right(summary_t *s, UNUSED int k, UNUSED int j, UNUSED int i)
{
    sfVector2f point_2d;
    sfConvexShape *tmp = s->map.cube.shapes.shape_dirt;

    point_2d.x = s->map.cube.position.x;
    point_2d.y = s->map.cube.position.y;
    sfConvexShape_setPointCount(tmp, 4);
    sfConvexShape_setPosition(tmp, point_2d);
    sfConvexShape_setPoint(tmp, 0, s->map.cube.points.front_2d[1]);
    sfConvexShape_setPoint(tmp, 1, s->map.cube.points.back_2d[1]);
    sfConvexShape_setPoint(tmp, 2, s->map.cube.points.back_2d[2]);
    sfConvexShape_setPoint(tmp, 3, s->map.cube.points.front_2d[2]);
    sfRenderWindow_drawConvexShape(s->win.window, tmp, NULL);
}

void back(summary_t *s, UNUSED int k, UNUSED int j, UNUSED int i)
{
    sfVector2f point_2d;
    sfConvexShape *tmp = s->map.cube.shapes.shape_dirt;

    point_2d.x = s->map.cube.position.x;
    point_2d.y = s->map.cube.position.y;
    sfConvexShape_setPointCount(tmp, 4);
    sfConvexShape_setPosition(tmp, point_2d);
    for (int e = 0; e < 4; ++e)
        sfConvexShape_setPoint(tmp, e, s->map.cube.points.back_2d[e]);
    sfRenderWindow_drawConvexShape(s->win.window, tmp, NULL);
}

void left(summary_t *s, UNUSED int k, UNUSED int j, UNUSED int i)
{
    sfVector2f point_2d;
    sfConvexShape *tmp = s->map.cube.shapes.shape_dirt;

    point_2d.x = s->map.cube.position.x;
    point_2d.y = s->map.cube.position.y;
    sfConvexShape_setPointCount(tmp, 4);
    sfConvexShape_setPosition(tmp, point_2d);
    sfConvexShape_setPoint(tmp, 0, s->map.cube.points.front_2d[0]);
    sfConvexShape_setPoint(tmp, 1, s->map.cube.points.back_2d[0]);
    sfConvexShape_setPoint(tmp, 2, s->map.cube.points.back_2d[3]);
    sfConvexShape_setPoint(tmp, 3, s->map.cube.points.front_2d[3]);
    sfRenderWindow_drawConvexShape(s->win.window, tmp, NULL);
}

void top(summary_t *s, UNUSED int k, UNUSED int j, UNUSED int i)
{
    draw_line(s->win.window, s->map.cube.points.front_2d[2],
        s->map.cube.points.back_2d[2], s->map.cube.array);
    draw_line(s->win.window, s->map.cube.points.back_2d[2],
        s->map.cube.points.back_2d[3], s->map.cube.array);
    draw_line(s->win.window, s->map.cube.points.back_2d[3],
        s->map.cube.points.front_2d[3], s->map.cube.array);
    draw_line(s->win.window, s->map.cube.points.front_2d[3],
        s->map.cube.points.front_2d[2], s->map.cube.array);
}
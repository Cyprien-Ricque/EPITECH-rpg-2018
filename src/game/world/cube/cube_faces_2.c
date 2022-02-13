/*
** EPITECH PROJECT, 2019
** cube_faces_2
** File description:
** cube_faces_2
*/

#include "my_rpg.h"
#include "world.h"

void front(summary_t *s, UNUSED int k, UNUSED int j, UNUSED int i)
{
    sfVector2f point_2d;
    sfConvexShape *tmp = s->map.cube.shapes.shape_dirt;

    point_2d.x = s->map.cube.position.x;
    point_2d.y = s->map.cube.position.y;
    sfConvexShape_setPointCount(tmp, 4);
    sfConvexShape_setPosition(tmp, point_2d);
    for (int e = 0; e < 4; ++e) {
        sfConvexShape_setPoint(tmp, e, s->map.cube.points.front_2d[e]);
    }
    sfRenderWindow_drawConvexShape(s->win.window, tmp, NULL);
}

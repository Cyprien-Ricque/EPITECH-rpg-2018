/*
** EPITECH PROJECT, 2019
** displaying_2
** File description:
** displaying_2
*/

#include "my_rpg.h"
#include "world.h"

char three_check(summary_t *s, int j, int i)
{
    int cpt = 0;

    if (i >= s->map.st.size.x - 1 || j >= s->map.st.size.y - 1)
        return (FALSE);
    if (s->map.map[j][i] < 1 || (s->map.map[j][i + 1] < 1) ||
        (s->map.map[j + 1][i] < 1) || (s->map.map[j + 1][i + 1] < 1))
        return (1);
    if (s->map.map[j][i] < s->map.dt.water_mov[j][i])
        ++cpt;
    if (s->map.map[j][i + 1] < s->map.dt.water_mov[j][i + 1])
        ++cpt;
    if (s->map.map[j + 1][i] < s->map.dt.water_mov[j + 1][i])
        ++cpt;
    if (s->map.map[j + 1][i + 1] < s->map.dt.water_mov[j + 1][i + 1])
        ++cpt;
    if (cpt <= 1)
        return (0);
    return (1);
}

void draw_shape_entity_base(summary_t *s, sfVector2f *point_2d,
    sfConvexShape *tmp)
{
    sfConvexShape_setPointCount(tmp, 6);
    sfConvexShape_setPosition(tmp, (*point_2d));
    sfConvexShape_setPoint(tmp, 0, s->map.cube.points.front_2d[1]);
    sfConvexShape_setPoint(tmp, 1, s->map.cube.points.front_2d[2]);
    sfConvexShape_setPoint(tmp, 2, s->map.cube.points.back_2d[2]);
    sfConvexShape_setPoint(tmp, 3, s->map.cube.points.back_2d[3]);
    sfConvexShape_setPoint(tmp, 4, s->map.cube.points.back_2d[0]);
    sfConvexShape_setPoint(tmp, 5, s->map.cube.points.front_2d[0]);
    sfRenderWindow_drawConvexShape(s->win.window, tmp, NULL);
}

void draw_shape_entity_right(summary_t *s, sfVector2f *point_2d,
    sfConvexShape *tmp)
{
    sfConvexShape_setPointCount(tmp, 6);
    sfConvexShape_setPosition(tmp, (*point_2d));
    sfConvexShape_setPoint(tmp, 0, s->map.cube.points.front_2d[0]);
    sfConvexShape_setPoint(tmp, 1, s->map.cube.points.front_2d[3]);
    sfConvexShape_setPoint(tmp, 2, s->map.cube.points.front_2d[2]);
    sfConvexShape_setPoint(tmp, 3, s->map.cube.points.back_2d[2]);
    sfConvexShape_setPoint(tmp, 4, s->map.cube.points.back_2d[1]);
    sfConvexShape_setPoint(tmp, 5, s->map.cube.points.back_2d[0]);
    sfRenderWindow_drawConvexShape(s->win.window, tmp, NULL);
}

void draw_shape_entity_left(summary_t *s, sfVector2f *point_2d,
    sfConvexShape *tmp)
{
    sfConvexShape_setPointCount(tmp, 6);
    sfConvexShape_setPosition(tmp, (*point_2d));
    sfConvexShape_setPoint(tmp, 0, s->map.cube.points.back_2d[1]);
    sfConvexShape_setPoint(tmp, 1, s->map.cube.points.back_2d[2]);
    sfConvexShape_setPoint(tmp, 2, s->map.cube.points.back_2d[3]);
    sfConvexShape_setPoint(tmp, 3, s->map.cube.points.front_2d[3]);
    sfConvexShape_setPoint(tmp, 4, s->map.cube.points.front_2d[0]);
    sfConvexShape_setPoint(tmp, 5, s->map.cube.points.front_2d[1]);
    sfRenderWindow_drawConvexShape(s->win.window, tmp, NULL);
}

void draw_shape_entity_back(summary_t *s, sfVector2f *point_2d,
    sfConvexShape *tmp)
{
    sfConvexShape_setPointCount(tmp, 6);
    sfConvexShape_setPosition(tmp, (*point_2d));
    sfConvexShape_setPoint(tmp, 0, s->map.cube.points.back_2d[0]);
    sfConvexShape_setPoint(tmp, 1, s->map.cube.points.back_2d[3]);
    sfConvexShape_setPoint(tmp, 2, s->map.cube.points.front_2d[3]);
    sfConvexShape_setPoint(tmp, 3, s->map.cube.points.front_2d[2]);
    sfConvexShape_setPoint(tmp, 4, s->map.cube.points.front_2d[1]);
    sfConvexShape_setPoint(tmp, 5, s->map.cube.points.back_2d[1]);
    sfRenderWindow_drawConvexShape(s->win.window, tmp, NULL);
}
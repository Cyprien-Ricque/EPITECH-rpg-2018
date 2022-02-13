/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"
#include <math.h>

void draw_water(summary_t *s, int j, int i, sfVector2i *tmp)
{
    if (((*tmp).x == 1 && (*tmp).y == 1) ||
        ((*tmp).y == 1 && (*tmp).x == -1 && s->map.map[j - 1][i] >= 3) ||
        ((*tmp).y == -1 && (*tmp).x == -1 && s->map.map[j - 1][i - 1] >= 3 &&
            s->map.map[j - 1][i] >= 3 && s->map.map[j][i - 1] >= 3) ||
        ((*tmp).y == -1 && (*tmp).x == 1 && s->map.map[j][i - 1] >= 3)) {
        sfRenderWindow_drawConvexShape(s->win.window,
            s->map.cube.shapes.shape_water, NULL);
    }
}

void water(summary_t *s, int j, int i)
{
    sfVector2i tmp;

    sfConvexShape_setPointCount(s->map.cube.shapes.shape_water, 4);
    for (int a = 1; a <= 1; a += 2) {
        for (int b = 1; b <= 1; b += 2) {
            tmp.x = a;
            tmp.y = b;
            create_water_points(s, j, i, tmp);
            draw_water(s, j, i, &tmp);
        }
    }
}

void set_water(summary_t *s)
{
    float value = 0;

    for (int j = 0; j < s->map.st.size.y; ++j) {
        for (int i = 0; i < s->map.st.size.x; ++i) {
            value = (float)(cos((double)(s->mtime->seconds +
            s->map.dt.water_fix[j][i])));
            s->map.dt.water_mov[j][i] = (float)(value / 5 + 0.80);
        }
    }
}
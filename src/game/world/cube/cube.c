/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

void (*function_cube[8])(summary_t *s, int k, int j, int i) =
{
    front, right, back, left, top_1, top_2, bottom, top
};

void top_2(summary_t *s, int k, int j, int i)
{
    sfVector2f point_2d;
    sfConvexShape *tmp = top_color2(s, k, j, i);

    point_2d.x = s->map.cube.position.x;
    point_2d.y = s->map.cube.position.y;
    sfConvexShape_setPointCount(tmp, 3);
    sfConvexShape_setPosition(tmp, point_2d);
    sfConvexShape_setPoint(tmp, 0, s->map.cube.points.front_2d[2]);
    sfConvexShape_setPoint(tmp, 1, s->map.cube.points.back_2d[2]);
    sfConvexShape_setPoint(tmp, 2, s->map.cube.points.front_2d[3]);
    sfRenderWindow_drawConvexShape(s->win.window, tmp, NULL);
}

void bottom(summary_t *s, UNUSED int k, UNUSED int j, UNUSED int i)
{
    sfVector2f point_2d;
    sfConvexShape *tmp = s->map.cube.shapes.shape_dirt;

    point_2d.x = s->map.cube.position.x;
    point_2d.y = s->map.cube.position.y;
    sfConvexShape_setPointCount(tmp, 4);
    sfConvexShape_setPosition(tmp, point_2d);
    sfConvexShape_setPoint(tmp, 0, s->map.cube.points.front_2d[0]);
    sfConvexShape_setPoint(tmp, 1, s->map.cube.points.back_2d[0]);
    sfConvexShape_setPoint(tmp, 2, s->map.cube.points.back_2d[1]);
    sfConvexShape_setPoint(tmp, 3, s->map.cube.points.front_2d[1]);
    sfRenderWindow_drawConvexShape(s->win.window, tmp, NULL);
}

void cpy(char *dest, char *src)
{
    int i = 0;

    for (i = 0; src[i]; ++i)
        dest[i] = src[i];
    dest[i] = 0;
}

void draw_cube(summary_t *s, int k, int j, int i)
{
    char *str = malloc(sizeof(char) * 9);

    if (s->map.st.angle.x > -45 && s->map.st.angle.x <= 45)
        cpy(str, "54703");
    if (s->map.st.angle.x > 45 && s->map.st.angle.x <= 135)
        cpy(str, "54723");
    if (s->map.st.angle.x > 135 && s->map.st.angle.x <= 225)
        cpy(str, "54712");
    if (s->map.st.angle.x > 225 && s->map.st.angle.x <= 315)
        cpy(str, "54710");
    for (int e = 0; str[e]; ++e)
        function_cube[str[e] - 48](s, k, j, i);
}

void water_display_left(summary_t *s, int k, int j, int i)
{
    if (s->map.st.angle.x > 225 && s->map.st.angle.x <= 315) {
        if (j > 0 && i < s->map.st.size.x && k == 0 &&
            three_check(s, j - 1, i + 1))
            water(s, j - 1, i + 1);
        if (i == -1 && j > 0 && k == 0) {
            cube_assignation(s, k, j - 1, i + 1);
            function_cube[1](s, k, j, i + 1);
        }
        if (j == s->map.st.size.y - 1 && i < s->map.st.size.x - 2 && k == 0) {
            cube_assignation(s, k, j - 1, i + 1);
            function_cube[0](s, k, j, i + 1);
        }
    }
}
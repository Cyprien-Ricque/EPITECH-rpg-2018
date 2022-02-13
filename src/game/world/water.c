/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

sfVector2f point_4(summary_t *s, int j, int i, sfVector2i ab)
{
    sfVector3f tmp;

    tmp.x = (i + ab.y) * s->map.st.zoom;
    tmp.y = j * s->map.st.zoom;
    tmp.z = s->map.dt.water_mov[j][i + ab.y] * s->map.st.zoom;
    return (project_iso_point(tmp, s->map.st.angle.x, s->map.st.angle.y,
        &s->map));
}

sfVector2f point_3(summary_t *s, int j, int i, sfVector2i ab)
{
    sfVector3f tmp;

    tmp.x = (i + ab.y) * s->map.st.zoom;
    tmp.y = (j + ab.x) * s->map.st.zoom;
    tmp.z = s->map.dt.water_mov[j + ab.x][i + ab.y] * s->map.st.zoom;
    return (project_iso_point(tmp, s->map.st.angle.x, s->map.st.angle.y,
        &s->map));
}

sfVector2f point_2(summary_t *s, int j, int i, sfVector2i ab)
{
    sfVector3f tmp;

    tmp.x = i * s->map.st.zoom;
    tmp.y = (j + ab.x) * s->map.st.zoom;
    tmp.z = s->map.dt.water_mov[j + ab.x][i] * s->map.st.zoom;
    return (project_iso_point(tmp, s->map.st.angle.x, s->map.st.angle.y,
        &s->map));
}

sfVector2f point_1(summary_t *s, int j, int i)
{
    sfVector3f tmp;

    tmp.x = i * s->map.st.zoom;
    tmp.y = j * s->map.st.zoom;
    tmp.z = s->map.dt.water_mov[j][i] * s->map.st.zoom;
    return (project_iso_point(tmp, s->map.st.angle.x, s->map.st.angle.y,
        &s->map));
}

void create_water_points(summary_t *s, int j, int i, sfVector2i ab)
{
    sfVector2f point_2d;

    for (int e = 0; e < 4; ++e) {
        if (e == 0)
            point_2d = point_1(s, j, i);
        if (e == 1)
            point_2d = point_2(s, j, i, ab);
        if (e == 2)
            point_2d = point_3(s, j, i, ab);
        if (e == 3)
            point_2d = point_4(s, j, i, ab);
        sfConvexShape_setPoint(s->map.cube.shapes.shape_water, e, point_2d);
    }
}

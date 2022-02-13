/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

sfVector2f project_iso_point(sfVector3f point_3d, float angle_x, float angle_y,
    map_t *map)
{
    sfVector2f point_2d;
    sfVector3f tmp;

    point_3d.x -= (map->st.size.x - 1) * map->st.zoom / 2;
    point_3d.y -= (map->st.size.y - 1) * map->st.zoom / 2;
    point_3d.z -= 1.5 * map->st.zoom / 2;
    tmp = point_3d;
    tmp.x = (float)(cos(angle_x * (M_PI / 180)) * point_3d.x -
        sin(angle_x * (M_PI / 180)) * point_3d.y);
    tmp.y = (float)(sin(angle_x * (M_PI / 180)) * point_3d.x +
        cos(angle_x * (M_PI / 180)) * point_3d.y);
    point_2d.x = (float)(cos(0 * (M_PI / 180)) * tmp.x -
        cos(0 * (M_PI / 180)) * tmp.y);
    point_2d.y = (float)(sin(angle_y * (M_PI / 180)) * tmp.y +
        sin(angle_y * (M_PI / 180)) * tmp.x - tmp.z);
    point_2d.x += map->st.pos.x;
    point_2d.y += map->st.pos.y;
    return (point_2d);
}

void create_2d_map_x(map_t *map, int k, int j)
{
    sfVector3f tmp;

    for (int i = 0; i < map->st.size.x; ++i) {
        if (map->dt.pntr_map[k][j][i]) {
            tmp.x = map->dt.map_3d[k][j][i].x * map->st.zoom;
            tmp.y = map->dt.map_3d[k][j][i].y * map->st.zoom;
            tmp.z = map->dt.map_3d[k][j][i].z * map->st.zoom;
            map->dt.map_2d[k][j][i] = project_iso_point(tmp, map->st.angle.x,
                (map->st.angle.y), map);
        }
    }
}

void create_2d_map(map_t *map)
{
    for (int k = 0; k < map->st.size.z; ++k) {
        for (int j = 0; j < map->st.size.y; ++j)
            create_2d_map_x(map, k, j);
    }
}
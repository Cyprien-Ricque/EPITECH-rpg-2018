/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** world sprite
*/

#include "my_rpg.h"
#include "world.h"
#include "my.h"

void points_2d(map_t *map)
{
    for (int e = 0; e < 4; ++e) {
        map->cube.points.back_2d[e] = project_iso_point(
            map->cube.points.back_3d[e], map->st.angle.x, map->st.angle.y,
            map);
        map->cube.points.front_2d[e] = project_iso_point(
            map->cube.points.front_3d[e], map->st.angle.x, map->st.angle.y,
            map);
    }
}
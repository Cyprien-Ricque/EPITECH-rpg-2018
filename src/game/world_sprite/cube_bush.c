/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** world sprite
*/

#include "my_rpg.h"
#include "world.h"
#include "my.h"

void points_bush_3d_1(map_t *map, int k, int j, int i)
{
    map->cube.points.front_3d[0].z = (float)((k + 0) * map->st.zoom);
    map->cube.points.front_3d[0].y = (float)((j + 1) * map->st.zoom);
    map->cube.points.front_3d[0].x = (float)((i + 1) * map->st.zoom);
    map->cube.points.front_3d[1].z = (float)((k + 0) * map->st.zoom);
    map->cube.points.front_3d[1].y = (float)((j + 1) * map->st.zoom);
    map->cube.points.front_3d[1].x = (float)((i + 0) * map->st.zoom);
    map->cube.points.front_3d[2].z = (float)((k + 0.40) * map->st.zoom);
    map->cube.points.front_3d[2].y = (float)((j + 1) * map->st.zoom);
    map->cube.points.front_3d[2].x = (float)((i + 0) * map->st.zoom);
    map->cube.points.front_3d[3].z = (float)((k + 0.40) * map->st.zoom);
    map->cube.points.front_3d[3].y = (float)((j + 1) * map->st.zoom);
    map->cube.points.front_3d[3].x = (float)((i + 1) * map->st.zoom);
}

void points_cube_bush_3d_2(map_t *map, int k, int j, int i)
{
    map->cube.points.back_3d[2].z = (float)((k + 0.40) * map->st.zoom);
    map->cube.points.back_3d[2].y = (float)((j + 0) * map->st.zoom);
    map->cube.points.back_3d[2].x = (float)((i + 0) * map->st.zoom);
    map->cube.points.back_3d[3].z = (float)((k + 0.40) * map->st.zoom);
    map->cube.points.back_3d[3].y = (float)((j + 0) * map->st.zoom);
    map->cube.points.back_3d[3].x = (float)((i + 1) * map->st.zoom);
    map->cube.points.back_3d[0].z = (float)((k + 0) * map->st.zoom);
    map->cube.points.back_3d[0].y = (float)((j + 0) * map->st.zoom);
    map->cube.points.back_3d[0].x = (float)((i + 1) * map->st.zoom);
    map->cube.points.back_3d[1].z = (float)((k + 0) * map->st.zoom);
    map->cube.points.back_3d[1].y = (float)((j + 0) * map->st.zoom);
    map->cube.points.back_3d[1].x = (float)((i + 0) * map->st.zoom);
}

void points_bush_3d(map_t *map, int k, int j, int i)
{
    points_bush_3d_1(map, k, j, i);
    points_cube_bush_3d_2(map, k, j, i);
}

void cube_points_bush(summary_t *s, int k, int j, int i)
{
    points_bush_3d(&s->map, k, j, i);
    points_2d(&s->map);
}
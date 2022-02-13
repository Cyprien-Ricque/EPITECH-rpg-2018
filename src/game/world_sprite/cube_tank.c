/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** world sprite
*/

#include "my_rpg.h"
#include "world.h"
#include "my.h"

void rotation_assignement_c(float rotation, float *value_j, float *value_i)
{
    if (rotation == FRONT_RIGHT)
        (*value_j) = 0;
    if (rotation == FRONT_LEFT)
        (*value_i) = 0;
    if (rotation == BACK_RIGHT) {
        (*value_i) = 0;
        (*value_j) *= -1;
    }
    if (rotation == BACK_LEFT) {
        (*value_j) = 0;
        (*value_i) *= -1;
    }
}

void points_tank_3d_1(map_t *map, int k, int j, int i)
{
    float value_j = map->entity[j][i].perso->percent;
    float value_i = map->entity[j][i].perso->percent;
    float rotation = map->entity[j][i].perso->rotation;

    rotation_assignement_c(rotation, &value_j, &value_i);
    map->cube.points.front_3d[0].z = (float)((k + 0) * map->st.zoom);
    map->cube.points.front_3d[0].y = (float)((j + 1 + value_j) * map->st.zoom);
    map->cube.points.front_3d[0].x = (float)((i + 1 + value_i) * map->st.zoom);
    map->cube.points.front_3d[1].z = (float)((k + 0) * map->st.zoom);
    map->cube.points.front_3d[1].y = (float)((j + 1 + value_j) * map->st.zoom);
    map->cube.points.front_3d[1].x = (float)((i + 0 + value_i) * map->st.zoom);
    map->cube.points.front_3d[2].z = (float)((k + 0.40) * map->st.zoom);
    map->cube.points.front_3d[2].y = (float)((j + 1 + value_j) * map->st.zoom);
    map->cube.points.front_3d[2].x = (float)((i + 0 + value_i) * map->st.zoom);
    map->cube.points.front_3d[3].z = (float)((k + 0.40) * map->st.zoom);
    map->cube.points.front_3d[3].y = (float)((j + 1 + value_j) * map->st.zoom);
    map->cube.points.front_3d[3].x = (float)((i + 1 + value_i) * map->st.zoom);
}

void points_tank_3d_2(map_t *map, int k, int j, int i)
{
    float value_j = map->entity[j][i].perso->percent;
    float value_i = map->entity[j][i].perso->percent;
    float rotation = map->entity[j][i].perso->rotation;

    rotation_assignement_c(rotation, &value_j, &value_i);
    map->cube.points.back_3d[2].z = (float)((k + 0.40) * map->st.zoom);
    map->cube.points.back_3d[2].y = (float)((j + 0 + value_j) * map->st.zoom);
    map->cube.points.back_3d[2].x = (float)((i + 0 + value_i) * map->st.zoom);
    map->cube.points.back_3d[3].z = (float)((k + 0.40) * map->st.zoom);
    map->cube.points.back_3d[3].y = (float)((j + 0 + value_j) * map->st.zoom);
    map->cube.points.back_3d[3].x = (float)((i + 1 + value_i) * map->st.zoom);
    map->cube.points.back_3d[0].z = (float)((k + 0) * map->st.zoom);
    map->cube.points.back_3d[0].y = (float)((j + 0 + value_j) * map->st.zoom);
    map->cube.points.back_3d[0].x = (float)((i + 1 + value_i) * map->st.zoom);
    map->cube.points.back_3d[1].z = (float)((k + 0) * map->st.zoom);
    map->cube.points.back_3d[1].y = (float)((j + 0 + value_j) * map->st.zoom);
    map->cube.points.back_3d[1].x = (float)((i + 0 + value_i) * map->st.zoom);
}

void points_tank_3d(map_t *map, int k, int j, int i)
{
    points_tank_3d_1(map, k, j, i);
    points_tank_3d_2(map, k, j, i);
}

void cube_points_tank(summary_t *s, int k, int j, int i)
{
    points_tank_3d(&s->map, k, j, i);
    points_2d(&s->map);
}
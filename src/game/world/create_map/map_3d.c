/*
** EPITECH PROJECT, 2018
** map_3d
** File description:
** map_3d
*/

#include "my_rpg.h"
#include "world.h"

void exist_cube(map_t *map, int k, int j, int i)
{
    map->dt.pntr_map[k][j][i] = 1;
    if (map->map[j][i] < k)
        map->dt.map_3d[k][j][i].z = map->map[j][i];
    else
        map->dt.map_3d[k][j][i].z = k;
    map->dt.map_3d[k][j][i].y = j;
    map->dt.map_3d[k][j][i].x = i;
}

void create_3d_map_x(map_t *map, int k, int j)
{
    for (int i = 0; i < map->st.size.x; ++i) {
        if (k - 1 > map->map[j][i])
            map->dt.pntr_map[k][j][i] = 0;
        else
            exist_cube(map, k, j, i);
    }
}

void create_3d_map(map_t *map)
{
    for (int k = 0; k < map->st.size.z; ++k) {
        for (int j = 0; j < map->st.size.y; ++j)
            create_3d_map_x(map, k, j);
    }
}
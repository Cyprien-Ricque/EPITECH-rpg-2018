/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

void random_map(map_t *map)
{
    for (int i = 0; i < map->st.size.y; ++i) {
        for (int x = 0; x < map->st.size.x; ++x)
            map->map[i][x] = rand() % 3;
    }
}

void new_map(map_t *map)
{
    map->dt.init = false;
    map->cube.init = false;
}

void default_values(map_t *map)
{
    map->st.pos.x = (float)(1920 * 0.5);
    map->st.pos.y = (float)(1080 * 0.5);
    map->st.zoom = 60;
    map->st.angle.x = 0;
    map->st.angle.y = 45;
    new_map(map);
}

void set_map_default(map_t *map)
{
    default_values(map);
    map->st.size.x = 30;
    map->st.size.y = 30;
    map->st.size.z = 3;
}
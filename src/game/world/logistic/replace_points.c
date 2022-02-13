/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

void place_points(map_t *map, int j)
{
    for (int i = 0; i < map->st.size.x; ++i) {
        if (map->map[j][i] > find_k(map, j, i) + 1)
            map->map[j][i] = find_k(map, j, i) + 1;
    }
}

void replace_points(map_t *map)
{
    for (int j = 0; j < map->st.size.y; ++j)
        place_points(map, j);
}
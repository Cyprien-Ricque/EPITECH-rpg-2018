/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

char create_map(map_t *map)
{
    map->map = malloc(sizeof(float *) * (map->st.size.y + 1));
    if (!map->map)
        return (FAILURE);
    for (int i = 0; i < map->st.size.y; ++i) {
        map->map[i] = malloc(sizeof(float) * (map->st.size.x + 1));
        if (!map->map[i])
            return (FAILURE);
    }
    map->map[map->st.size.y] = NULL;
    return (SUCCESS);
}
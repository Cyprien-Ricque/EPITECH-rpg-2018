/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

float getpoint_1(map_t *map, int i, float smaller, int e)
{
    for (int p = i; p < i + 1; ++p) {
        if (e >= 0 && p >= 0 && e < map->st.size.y && p < map->st.size.x &&
            map->map[e][p] < smaller)
            smaller = map->map[e][p];
        else if (!(e >= 0 && p >= 0 && e < map->st.size.y &&
            p < map->st.size.x))
            smaller = 0;
    }
    return smaller;
}

float getpoint_2(map_t *map, int i, float smaller, int e)
{
    for (int p = i; p <= i + 1; ++p) {
        if (e >= 0 && p >= 0 && e < map->st.size.y && p < map->st.size.x &&
            map->map[e][p] < smaller)
            smaller = map->map[e][p];
        else if (!(e >= 0 && p >= 0 && e < map->st.size.y &&
            p < map->st.size.x))
            smaller = 0;
    }
    return smaller;
}

float getpoint_3(map_t *map, int i, float smaller, int e)
{
    for (int p = i - 1; p <= i; ++p) {
        if (e >= 0 && p >= 0 && e < map->st.size.y && p < map->st.size.x &&
            map->map[e][p] < smaller)
            smaller = map->map[e][p];
        else if (!(e >= 0 && p >= 0 && e < map->st.size.y &&
            p < map->st.size.x))
            smaller = 0;
    }
    return smaller;
}

float getpoint_4(map_t *map, int i, float smaller, int e)
{
    for (int p = i - 1; p <= i; ++p) {
        if (e >= 0 && p >= 0 && e < map->st.size.y && p < map->st.size.x &&
            map->map[e][p] < smaller)
            smaller = map->map[e][p];
        else if (!(e >= 0 && p >= 0 && e < map->st.size.y &&
            p < map->st.size.x))
            smaller = 0;
    }
    return smaller;
}

int find_k(map_t *map, int j, int i)
{
    float smaller;
    float higher = 0;

    for (int r = 0; r < 4; ++r) {
        smaller = 100;
        for (int e = j; r == 0 && e <= j + 1; ++e)
            smaller = getpoint_1(map, i, smaller, e);
        for (int e = j - 1; r == 1 && e <= j; ++e)
            smaller = getpoint_2(map, i, smaller, e);
        for (int e = j; r == 2 && e <= j + 1; ++e)
            smaller = getpoint_3(map, i, smaller, e);
        for (int e = j - 1; r == 3 && e <= j; ++e)
            smaller = getpoint_4(map, i, smaller, e);
        if (higher < smaller)
            higher = smaller;
    }
    return ((int)higher);
}

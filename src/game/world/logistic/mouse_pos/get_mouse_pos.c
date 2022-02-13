/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

sfVector3f pos_tiles(map_t *map, window_t *win, int j)
{
    sfVector3f pos = {.x = -1, .y = -1, .z = -1};
    sfVector2f point[4];

    for (int i = 0; i < map->st.size.x - 1; ++i) {
        point[0] = map->dt.map_2d[find_k(map, j, i)][j][i];
        point[1] = map->dt.map_2d[find_k(map, j, i + 1)][j][i + 1];
        point[2] = map->dt.map_2d[find_k(map, j + 1, i + 1)][j + 1][i + 1];
        point[3] = map->dt.map_2d[find_k(map, j + 1, i)][j + 1][i];
        if (check_point(point, (int)win->mouse.x, (int)win->mouse.y) == TRUE) {
            pos.x = i;
            pos.y = j;
            pos.z = find_k(map, j, i);
        }
    }
    return (pos);
}

sfVector3f get_pos_tiles(map_t *map, window_t *win)
{
    sfVector3f pos = {.x = -1, .y = -1, .z = -1};
    sfVector3f tmp;

    for (int j = 0; j < map->st.size.y - 1; ++j) {
        tmp = pos_tiles(map, win, j);
        if (tmp.x != -1)
            pos = tmp;
    }
    return (pos);
}

sfVector3f pos_corner(map_t *map, window_t *win, int j, float *smaller)
{
    sfVector3f pos = {.x = -1, .y = -1, .z = -1};
    double dist = 0;

    for (int i = 0; i < map->st.size.x - 1; ++i) {
        dist = sqrt((double)square(
            map->dt.map_2d[find_k(map, j, i)][j][i].x - win->mouse.x) +
            square(map->dt.map_2d[find_k(map, j, i)][j][i].y - win->mouse.y)) -
            (find_k(map, j, i) * 1.8);
        if (dist <= *smaller) {
            pos.x = i;
            pos.y = j;
            pos.z = find_k(map, j, i);
            *smaller = (float)dist;
        }
    }
    return (pos);
}

sfVector3f get_pos_corner(map_t *map, window_t *win)
{
    float smaller = 1000;
    sfVector3f tmp;
    sfVector3f pos = {.x = -1, .y = -1, .z = -1};

    for (int j = 0; j < map->st.size.y - 1; ++j) {
        tmp = pos_corner(map, win, j, &smaller);
        if (tmp.x != -1)
            pos = tmp;
    }
    return (pos);
}
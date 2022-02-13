/*
** EPITECH PROJECT, 2019
** menu_main
** File description:
** menu_main
*/

#include "my_rpg.h"
#include "world.h"

char init_water(map_t *map)
{
    map->dt.water_mov = malloc(sizeof(float *) * (map->st.size.y + 1));
    map->dt.water_fix = malloc(sizeof(float *) * (map->st.size.y + 1));
    if (!map->dt.water_fix || !map->dt.water_mov)
        return (FAILURE);
    for (int j = 0; j <= map->st.size.y; ++j) {
        map->dt.water_mov[j] = malloc(sizeof(float) * (map->st.size.x + 1));
        map->dt.water_fix[j] = malloc(sizeof(float) * (map->st.size.x + 1));
        if (!map->dt.water_fix[j] || !map->dt.water_mov[j])
            return (FAILURE);
        for (int i = 0; i <= map->st.size.x; ++i) {
            map->dt.water_mov[j][i] = 1 - rand() % 100 / 50;
            map->dt.water_fix[j][i] = rand() % 100 / 70;
        }
    }
    return (SUCCESS);
}

char init_map_xy(map_t *map, int k)
{
    map->dt.pntr_map[k] = malloc(sizeof(long *) * (map->st.size.y + 1));
    map->dt.map_2d[k] = malloc(sizeof(sfVector2f *) * (map->st.size.y + 1));
    map->dt.map_3d[k] = malloc(sizeof(sfVector3f *) * (map->st.size.y + 1));
    if (!map->dt.pntr_map[k] || !map->dt.map_3d[k] || !map->dt.map_2d[k])
        return (FAILURE);
    for (int j = 0; j < map->st.size.y; ++j) {
        map->dt.pntr_map[k][j] = malloc(sizeof(char *) * (map->st.size.x + 1));
        map->dt.map_2d[k][j] = malloc(
            sizeof(sfVector2f) * (map->st.size.x + 1));
        map->dt.map_3d[k][j] = malloc(
            sizeof(sfVector3f) * (map->st.size.x + 1));
        if (!map->dt.pntr_map[k][j] || !map->dt.map_3d[k][j] ||
            !map->dt.map_2d[k][j])
            return (FAILURE);
    }
    map->dt.pntr_map[k][map->st.size.y] = NULL;
    map->dt.map_2d[k][map->st.size.y] = NULL;
    map->dt.map_3d[k][map->st.size.y] = NULL;
    return (SUCCESS);
}

char init_map(map_t *map)
{
    if (map->dt.init)
        return (SUCCESS);
    map->dt.pntr_map = malloc(sizeof(char **) * (map->st.size.z + 1));
    map->dt.map_3d = malloc(sizeof(sfVector3f **) * (map->st.size.z + 1));
    map->dt.map_2d = malloc(sizeof(sfVector2f **) * (map->st.size.z + 1));
    if (!map->dt.pntr_map || !map->dt.map_3d || !map->dt.map_2d ||
        init_water(map) == FAILURE)
        return (FAILURE);
    for (int k = 0; k < map->st.size.z; ++k) {
        if (init_map_xy(map, k) == FAILURE)
            return (FAILURE);
    }
    map->dt.pntr_map[map->st.size.z] = NULL;
    map->dt.map_2d[map->st.size.z] = NULL;
    map->dt.map_3d[map->st.size.z] = NULL;
    map->dt.init = true;
    map->entity_mvt.movement = NULL;
    return (SUCCESS);
}
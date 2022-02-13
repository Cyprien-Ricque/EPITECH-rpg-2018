/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char set_all_maps_null(map_t **maps, int size)
{
    for (int i = 0; i <= size; ++i)
        maps[i] = NULL;
    return (SUCCESS);
}

char init_map_p(summary_t *s, char *save)
{
    if (s->rpg_wd->maps)
        return (SUCCESS);
    if (!s->tmp_p.size) {
        return (error(save));
    } else {
        s->rpg_wd->maps = malloc(
            sizeof(s->rpg_wd->maps) * (s->tmp_p.size + 1));
        if (!s->rpg_wd->maps)
            return (FAILURE);
        set_all_maps_null(s->rpg_wd->maps, s->tmp_p.size);
    }
    return (SUCCESS);
}

char malloc_new_map(map_t **map, tmp_pt *tmp_p)
{
    *map = malloc(sizeof(map_t));
    if (!*map)
        return (FAILURE);
    (*map)->map = malloc(sizeof(float *) * (tmp_p->size_y + 1));
    (*map)->entity = malloc(sizeof(entity_t *) * (tmp_p->size_y + 1));
    if (!(*map)->map || !(*map)->entity)
        return (FAILURE);
    (*map)->map[0] = NULL;
    (*map)->entity[0] = NULL;
    return (SUCCESS);
}

char init_actual_map_p(summary_t *s, int map, char *statement)
{
    if (!s->rpg_wd->maps[map])
        if (malloc_new_map(&s->rpg_wd->maps[map], &s->tmp_p) == FAILURE)
            return (FAILURE);
    s->rpg_wd->maps[map]->name = statement[m_slen(statement) - 2];
    default_values(s->rpg_wd->maps[map]);
    s->rpg_wd->maps[map]->st.size.x = s->tmp_p.size_x;
    s->rpg_wd->maps[map]->st.size.y = s->tmp_p.size_y;
    s->rpg_wd->maps[map]->st.size.z = s->tmp_p.size_z;
    return (SUCCESS);
}
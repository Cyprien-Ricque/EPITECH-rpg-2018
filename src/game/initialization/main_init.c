/*
** EPITECH PROJECT, 2019
** menu_main
** File description:
** menu_main
*/

#include "my_rpg.h"

char (*disp_map_init[3])(map_t *map) =
{
    init_map, init_cubes, NULL
};

char init_map_s(map_t *map)
{
    for (int i = 0; disp_map_init[i]; ++i)
        if (disp_map_init[i](map) == FAILURE)
            return (FAILURE);
    return (SUCCESS);
}

char main_init(summary_t *s)
{
    if (init_map_s(&s->map) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
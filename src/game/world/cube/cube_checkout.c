/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

void cube_assignation(summary_t *s, int k, int j, int i)
{
    s->map.cube.points.back_2d[2] = s->map.dt.map_2d[k + 1][j][i];
    s->map.cube.points.back_2d[3] = s->map.dt.map_2d[k + 1][j][i + 1];
    s->map.cube.points.back_2d[0] = s->map.dt.map_2d[k][j][i + 1];
    s->map.cube.points.back_2d[1] = s->map.dt.map_2d[k][j][i];
    s->map.cube.points.front_2d[2] = s->map.dt.map_2d[k + 1][j + 1][i];
    s->map.cube.points.front_2d[3] = s->map.dt.map_2d[k + 1][j + 1][i + 1];
    s->map.cube.points.front_2d[0] = s->map.dt.map_2d[k][j + 1][i + 1];
    s->map.cube.points.front_2d[1] = s->map.dt.map_2d[k][j + 1][i];
}

char cube_exist(summary_t *s, int k, int j, int i)
{
    if (k < 0 || j < 0 || i < 0)
        return (FALSE);
    if (!(k < s->map.st.size.z - 1 && j < s->map.st.size.y - 1 &&
        i < s->map.st.size.x - 1 && s->map.dt.pntr_map[k] &&
        s->map.dt.pntr_map[k][j] && s->map.dt.pntr_map[k][j][i] &&
        s->map.dt.pntr_map[k + 1] && s->map.dt.pntr_map[k + 1][j] &&
        s->map.dt.pntr_map[k][j + 1] && s->map.dt.pntr_map[k + 1][j + 1]))
        return (FALSE);
    if (!(s->map.dt.pntr_map[k + 1][j][i] &&
        s->map.dt.pntr_map[k + 1][j][i + 1] &&
        s->map.dt.pntr_map[k][j][i + 1] &&
        s->map.dt.pntr_map[k + 1][j + 1][i] &&
        s->map.dt.pntr_map[k + 1][j + 1][i + 1] &&
        s->map.dt.pntr_map[k][j + 1][i + 1] &&
        s->map.dt.pntr_map[k][j + 1][i]))
        return (FALSE);
    return (TRUE);
}
/*
** EPITECH PROJECT, 2019
** cube_3
** File description:
** cube_3
*/

#include "my_rpg.h"
#include "world.h"

extern void (*function_cube[8])(summary_t *, int, int, int);

char is_moutain(entity_t **en, int j, int i, sfVector3i size)
{
    if (en[j][i].type == MOUNTAIN ||
        (j < size.y - 1 && en[j + 1][i].type == MOUNTAIN) ||
        (i < size.x - 1 && en[j][i + 1].type == MOUNTAIN) ||
        (j < size.y - 1 && i < size.x - 1 &&
        en[j + 1][i + 1].type == MOUNTAIN))
        return (TRUE);
    return (FALSE);
}

char is_water(entity_t **en, int j, int i, sfVector3i size)
{
    if (en[j][i].type == WATER ||
        (j < size.y - 1 && en[j + 1][i].type == WATER) ||
        (i < size.x - 1 && en[j][i + 1].type == WATER) ||
        (j < size.y - 1 && i < size.x - 1 &&
        en[j + 1][i + 1].type == WATER))
        return (TRUE);
    return (FALSE);
}

char is_in_path(sfVector3f *path, int j, int i)
{
    if (!path)
        return (FALSE);
    for (int e = 0; path[e].x != -1 && path[e].y != -1; ++e) {
        if (path[e].x == i && path[e].y == j)
            return (TRUE);
    }
    return (FALSE);
}

sfConvexShape *top_color1(summary_t *s, UNUSED int k, int j, int i)
{
    if (is_water(s->map.entity, j, i, s->map.st.size) == TRUE)
        return (s->map.cube.shapes.shape_sand);
    if (is_moutain(s->map.entity, j, i, s->map.st.size) == TRUE) {
        if (DOMINIQUE)
            return (s->map.cube.shapes.shape_grass[5]);
        return (s->map.cube.shapes.shape_grass[1]);
    }
    if (is_in_path(s->map.entity_mvt.movement, j, i) == TRUE)
        return (s->map.cube.shapes.shape_grass[4]);
    if (!s->map.entity[j][i].perso)
        return (s->map.cube.shapes.shape_grass[2]);
    if (s->map.entity[j][i].perso->type == SHOP)
        return (s->map.cube.shapes.shape_grass[3]);
    return (s->map.cube.shapes.shape_grass[0]);
}

sfConvexShape *top_color2(summary_t *s, int k, int j, int i)
{
    if (k < 1)
        return (s->map.cube.shapes.shape_sand);
    if (is_moutain(s->map.entity, j, i, s->map.st.size) == TRUE) {
        if ((s->map.entity[j][i].type == MOUNTAIN &&
            !(j < s->map.st.size.y - 1 &&
            s->map.entity[j + 1][i].type == MOUNTAIN)) ||
            ((i < s->map.st.size.x - 1 &&
            s->map.entity[j][i + 1].type == MOUNTAIN) &&
            (j < s->map.st.size.y - 1 &&
            s->map.entity[j + 1][i + 1].type != MOUNTAIN)))
            return (s->map.cube.shapes.shape_grass[5]);
        return (s->map.cube.shapes.shape_grass[1]);
    }
    if (is_in_path(s->map.entity_mvt.movement, j, i) == TRUE)
        return (s->map.cube.shapes.shape_grass[4]);
    if (!s->map.entity[j][i].perso)
        return (s->map.cube.shapes.shape_grass[2]);
    if (s->map.entity[j][i].perso->type == SHOP)
        return (s->map.cube.shapes.shape_grass[3]);
    return (s->map.cube.shapes.shape_grass[0]);
}
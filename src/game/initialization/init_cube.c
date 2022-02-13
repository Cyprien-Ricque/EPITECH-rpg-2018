/*
** EPITECH PROJECT, 2019
** menu_main
** File description:
** menu_main
*/

#include "my_rpg.h"
#include "world.h"

char faces_design(cube_t *cube)
{
    for (int i = 0; i < 8; ++i) {
        cube->c_des.thickness[i] = 1;
        if (i == 4 || i == 5)
            cube->c_des.thickness[i] = 0;
        cube->c_des.texture[i] = NULL;
        cube->c_des.color_out[i] = sfBlack;
        cube->c_des.color[i] = sfWhite;
    }
    return (SUCCESS);
}

char init_c_design(cube_t *cube)
{
    cube->c_des.color = malloc(sizeof(sfColor) * 8);
    cube->c_des.color_out = malloc(sizeof(sfColor) * 8);
    cube->c_des.thickness = malloc(sizeof(int) * 8);
    cube->c_des.texture = malloc(sizeof(sfTexture *) * 8);
    if (create_shape_tank(cube) == FAILURE ||
        create_sprite_floor(cube) == FAILURE ||
        create_shape_shop(cube) == FAILURE)
        return (FAILURE);
    if (!cube->c_des.color || !cube->c_des.color_out ||
        !cube->c_des.thickness || !cube->c_des.texture)
        return (FAILURE);
    return (SUCCESS);
}

char malloc_points(map_t *m)
{
    m->cube.points.front_2d = malloc(sizeof(sfVector2f) * 4);
    m->cube.points.back_2d = malloc(sizeof(sfVector2f) * 4);
    m->cube.points.back_3d = malloc(sizeof(sfVector3f) * 4);
    m->cube.points.front_3d = malloc(sizeof(sfVector3f) * 4);
    if (!m->cube.points.front_2d || !m->cube.points.back_2d ||
        !m->cube.points.back_3d || !m->cube.points.front_3d)
        return (FAILURE);
    return (SUCCESS);
}

char init_cubes(map_t *m)
{
    if (m->cube.init)
        return (SUCCESS);
    if (malloc_points(m) == FAILURE)
        return (FAILURE);
    if (init_c_design(&m->cube) == FAILURE)
        return (FAILURE);
    if (faces_design(&m->cube) == FAILURE)
        return (FAILURE);
    m->cube.position.x = 0;
    m->cube.position.y = 0;
    m->cube.position.z = 0;
    m->cube.array = sfVertexArray_create();
    if (!m->cube.array)
        return (FAILURE);
    m->cube.init = true;
    return (SUCCESS);
}

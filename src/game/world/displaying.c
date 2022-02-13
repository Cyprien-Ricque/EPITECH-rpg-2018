/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

void draw_perso(summary_t *s, int k, int j, int i)
{
    sfVector2f point_2d = {.x = s->map.cube.position.x,
        .y = s->map.cube.position.y};
    sfConvexShape *tmp;

    cube_points_tank(s, k, j, i);
    if (s->map.mouse.x == i && s->map.mouse.y == j && s->map.mouse.z == k &&
        s->win.mouse.z == N_CLICK && scene(s, 4) == FALSE &&
        scene(s, 7) == FALSE && scene(s, 8) == FALSE && scene(s, 9) == FALSE &&
        scene(s, 10) == FALSE)
        display_tank_stats(s, j, i);
    if (s->map.entity[j][i].perso->team == RED)
        tmp = s->map.cube.shapes.tank_red
            [(int)s->map.entity[j][i].perso->type + 12][rotation(
            (int)s->map.entity[j][i].perso->rotation, s->map.st.angle.x)];
    else
        tmp = s->map.cube.shapes.tank_blue
            [(int)s->map.entity[j][i].perso->type + 12][rotation(
            (int)s->map.entity[j][i].perso->rotation, s->map.st.angle.x)];
    draw_shape_entity(s, &point_2d, tmp);
}

void draw_building(summary_t *s, int k, int j, int i)
{
    sfVector2f point_2d = {.x = s->map.cube.position.x,
        .y = s->map.cube.position.y};
    sfConvexShape *tmp;

    cube_points_shop(s, k, j, i);
    tmp = s->map.cube.shapes.shop[(int)s->map.entity[j][i].perso->rotation];
    draw_shape_entity(s, &point_2d, tmp);
}

void draw_bush(summary_t *s, int k, int j, int i)
{
    sfVector2f point_2d = {.x = s->map.cube.position.x,
        .y = s->map.cube.position.y};
    sfConvexShape *tmp;

    cube_points_bush(s, k, j, i);
    tmp = s->map.cube.shapes.shape_bush;
    draw_shape_entity(s, &point_2d, tmp);
}

void draw_tank_right(summary_t *s, int k, int j, int i)
{
    if (k == 1 && s->map.entity[j][i].perso &&
        s->map.entity[j][i].perso->type != SHOP)
        draw_perso(s, k, j, i);
    if (k == 1 && j + 1 < s->map.st.size.y - 1 &&
        s->map.entity[j + 1][i].perso &&
        s->map.entity[j + 1][i].perso->type != SHOP)
        draw_perso(s, k, j + 1, i);
    if (k == 1 && i + 1 < s->map.st.size.x - 1 &&
        s->map.entity[j][i + 1].perso &&
        s->map.entity[j][i + 1].perso->type != SHOP)
        draw_perso(s, k, j, i + 1);
    if (k == 1 && j - 1 > 0 &&
        s->map.entity[j - 1][i].perso &&
        s->map.entity[j - 1][i].perso->type != SHOP)
        draw_perso(s, k, j - 1, i);
    if (k == 1 && i - 1 >= 0 &&
        s->map.entity[j][i - 1].perso &&
        s->map.entity[j][i - 1].perso->type != SHOP)
        draw_perso(s, k, j, i - 1);
}

void draw_entity(summary_t *s, int k, int j, int i)
{
    draw_tank_right(s, k, j, i);
    if (k == 1 && s->map.entity[j][i].perso &&
        s->map.entity[j][i].perso->type == SHOP)
        draw_building(s, k, j, i);
    if (k == 1 && s->map.entity[j][i].type == LINK)
        draw_bush(s, k, j, i);
}
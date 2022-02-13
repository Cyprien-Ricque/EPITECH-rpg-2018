/*
** EPITECH PROJECT, 2019
** cube_2
** File description:
** cube_2
*/

#include "my_rpg.h"
#include "world.h"

extern void (*function_cube[8])(summary_t *, int, int, int);

void water_display_right(summary_t *s, int k, int j, int i)
{
    if (s->map.st.angle.x > 45 && s->map.st.angle.x <= 135) {
        if (i > 0 && j < s->map.st.size.y && k == 0 &&
            three_check(s, j + 1, i - 1))
            water(s, j + 1, i - 1);
        if (i == s->map.st.size.x - 1 && j < s->map.st.size.y - 2 && k == 0) {
            cube_assignation(s, k, j + 1, i - 1);
            function_cube[3](s, k, j + 1, i);
        }
        if (i > 0 && j == -1 && k == 0) {
            cube_assignation(s, k, j + 1, i - 1);
            function_cube[2](s, k, j + 1, i);
        }
    }
}

void water_display_back(summary_t *s, int k, int j, int i)
{
    if (s->map.st.angle.x > 135 && s->map.st.angle.x <= 225) {
        if (i < s->map.st.size.x && j < s->map.st.size.y && k == 0 &&
            three_check(s, j + 1, i + 1))
            water(s, j + 1, i + 1);
        if (i == -1 && j < s->map.st.size.y - 2 && k == 0) {
            cube_assignation(s, k, j + 1, i + 1);
            function_cube[1](s, k, j, i);
        }
        if (i < s->map.st.size.x - 2 && j == -1 && k == 0) {
            cube_assignation(s, k, j + 1, i + 1);
            function_cube[2](s, k, j, i);
        }
    }
}

void water_display_front(summary_t *s, int k, int j, int i)
{
    if (s->map.st.angle.x > -45 && s->map.st.angle.x <= 45) {
        if (j > 0 && i > 0 && k == 0 && three_check(s, j - 1, i - 1))
            water(s, j - 1, i - 1);
        if (i == s->map.st.size.x - 1 && j > 0 && k == 0) {
            cube_assignation(s, k, j - 1, i - 1);
            function_cube[3](s, k, j, i);
        }
        if (j == s->map.st.size.y - 1 && i > 0 && k == 0) {
            cube_assignation(s, k, j - 1, i - 1);
            function_cube[0](s, k, j, i);
        }
    }
}

void water_display(summary_t *s, int k, int j, int i)
{
    water_display_front(s, k, j, i);
    water_display_left(s, k, j, i);
    water_display_right(s, k, j, i);
    water_display_back(s, k, j, i);
}

void edit_cube(summary_t *s, int k, int j, int i)
{
    water_display(s, k, j, i);
    if (cube_exist(s, k, j, i) == TRUE) {
        cube_assignation(s, k, j, i);
        draw_cube(s, k, j, i);
    }
    if (k >= 0 && j >= 0 && i >= 0)
        draw_entity(s, k, j, i);
}
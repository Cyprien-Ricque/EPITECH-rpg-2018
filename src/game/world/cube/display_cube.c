/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

void create_cube_base(summary_t *s, int k)
{
    for (int j = 0; j < s->map.st.size.y; ++j) {
        for (int i = 0; i < s->map.st.size.x; ++i)
            edit_cube(s, k, j, i);
    }
}

void create_cube_right(summary_t *s, int k)
{
    for (int j = s->map.st.size.y - 1; j >= -1; --j) {
        for (int i = 0; i < s->map.st.size.x; ++i)
            edit_cube(s, k, j, i);
    }
}

void create_cube_back(summary_t *s, int k)
{
    for (int j = s->map.st.size.y - 1; j >= -1; --j) {
        for (int i = s->map.st.size.x - 1; i >= -1; --i)
            edit_cube(s, k, j, i);
    }
}

void create_cube_left(summary_t *s, int k)
{
    for (int j = 0; j < s->map.st.size.y; ++j) {
        for (int i = s->map.st.size.x - 1; i >= -1; --i)
            edit_cube(s, k, j, i);
    }
}

void display_cube(summary_t *s)
{
    if (s->map.st.angle.x > 315)
        s->map.st.angle.x = -45 + s->map.st.angle.x - 315;
    if (s->map.st.angle.x < -45)
        s->map.st.angle.x = 315 + s->map.st.angle.x + 45;
    for (int k = 0; k < s->map.st.size.z; ++k) {
        if (s->map.st.angle.x > -45 && s->map.st.angle.x <= 45)
            create_cube_base(s, k);
        if (s->map.st.angle.x > 45 && s->map.st.angle.x <= 135)
            create_cube_right(s, k);
        if (s->map.st.angle.x > 135 && s->map.st.angle.x <= 225)
            create_cube_back(s, k);
        if (s->map.st.angle.x > 225 && s->map.st.angle.x <= 315)
            create_cube_left(s, k);
    }
}

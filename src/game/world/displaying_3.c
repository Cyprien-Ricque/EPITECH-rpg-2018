/*
** EPITECH PROJECT, 2019
** displaying_3
** File description:
** displaying_3
*/

#include "my_rpg.h"
#include "world.h"

void draw_shape_entity(summary_t *s, sfVector2f *point_2d, sfConvexShape *tmp)
{
    for (int k = 0; k < s->map.st.size.z; ++k) {
        if (s->map.st.angle.x > -45 && s->map.st.angle.x <= 45)
            draw_shape_entity_base(s, point_2d, tmp);
        if (s->map.st.angle.x > 45 && s->map.st.angle.x <= 135)
            draw_shape_entity_right(s, point_2d, tmp);
        if (s->map.st.angle.x > 135 && s->map.st.angle.x <= 225)
            draw_shape_entity_back(s, point_2d, tmp);
        if (s->map.st.angle.x > 225 && s->map.st.angle.x <= 315)
            draw_shape_entity_left(s, point_2d, tmp);
    }
}

int rotation(int rotation, float angle)
{
    if (angle > 45 && angle <= 135)
        rotation -= 1;
    if (angle > 135 && angle <= 225)
        rotation -= 2;
    if (angle > 225 && angle <= 315)
        rotation -= 3;
    if (rotation < 0)
        rotation += 4;
    return (rotation);
}

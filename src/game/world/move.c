/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

void move_map(summary_t *s)
{
    if ((sfKeyboard_isKeyPressed(sfKeyLControl) ||
        sfKeyboard_isKeyPressed(sfKeyRControl)) &&
        (s->win.mouse.z == CLICK)) {
        s->map.st.pos.x -= (s->win.prev_mouse.x - s->win.mouse.x) / 18;
        s->map.st.pos.y -= (s->win.prev_mouse.y - s->win.mouse.y) / 18;
    }
}
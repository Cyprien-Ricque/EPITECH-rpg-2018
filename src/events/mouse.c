/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"
#include "menu_rpg.h"

void mouse(window_t *win)
{
    sfVector2i pos;

    win->prev_mouse = win->mouse;
    pos = sfMouse_getPositionRenderWindow(win->window);
    win->mouse.x = calc_x_position(*win, pos.x);
    win->mouse.y = calc_y_position(*win, pos.y);
    if (win->mouse.x < 0)
        win->mouse.x = 0;
    if (win->mouse.y < 0)
        win->mouse.y = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        win->mouse.z = CLICK;
    else
        win->mouse.z = N_CLICK;
}
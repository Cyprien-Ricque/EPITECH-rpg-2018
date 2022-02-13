/*
** EPITECH PROJECT, 2019
** menu_main
** File description:
** menu_main
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"
#include "menu_rpg.h"

int calc_x_position(window_t win, int value)
{
    int output = 0;

    output = (int)((1920.0 * value) / win.size.x);
    return (output);
}

int calc_y_position(window_t win, int value)
{
    int output = 0;

    output = (int)((1080.0 * value) / win.size.y);
    return (output);
}

char menu_main(summary_t *sum)
{
    int pos[2];

    DrawSprite(sum->win.window, sum->menu.main.back_spr, NULL);
    pos[0] = calc_x_position(sum->win, MouseGetPos(sum->win.window).x);
    pos[1] = calc_y_position(sum->win, MouseGetPos(sum->win.window).y);
    play_button(pos, sum);
    settings_button(pos, sum);
    quit_button(pos, sum);
    return (SUCCESS);
}
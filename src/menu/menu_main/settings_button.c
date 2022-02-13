/*
** EPITECH PROJECT, 2019
** settings_button
** File description:
** settings_button
*/

#include "my_rpg.h"
#include "menu_rpg.h"

static void first_state(summary_t *s)
{
    SpriteSetPosition(s->menu.main.set[MOUS], C_SET_BUT);
    DrawSprite(s->win.window, s->menu.main.set[MOUS], NULL);
    if (s->menu.main.previous_settings == sfTrue) {
        for (int a = 0; s->scene_number[a] != -1; ++a) {
            s->old_scene_nb[a] = s->scene_number[a];
            s->old_scene_nb[a + 1] = -1;
        }
        s->scene_number[0] = 1;
    }
    disp_line(s, 1, &s->menu.main.lines[SETTINGS]);
    s->menu.main.previous_settings = sfFalse;
}

static void second_state(summary_t *s)
{
    SpriteSetPosition(s->menu.main.set[CLIC], C_SET_BUT);
    DrawSprite(s->win.window, s->menu.main.set[CLIC], NULL);
    disp_line(s, 2, &s->menu.main.lines[SETTINGS]);
    s->menu.main.previous_settings = sfTrue;
}

void third_state(summary_t *s)
{
    SpriteSetPosition(s->menu.main.set[BASE], C_SET_BUT);
    DrawSprite(s->win.window, s->menu.main.set[BASE], NULL);
    disp_line(s, 0, &s->menu.main.lines[SETTINGS]);
    s->menu.main.previous_settings = sfFalse;
}

void settings_button(int const *pos, summary_t *s)
{
    if (SET_X_EQU > SET_X_MIN && SET_X_EQU < SET_X_MAX &&
        SET_Y_EQU > SET_Y_MIN && SET_Y_EQU < SET_Y_MAX &&
        ButtonLPressed == sfFalse) {
        first_state(s);
    } else if (SET_X_EQU > SET_X_MIN && SET_X_EQU < SET_X_MAX &&
        SET_Y_EQU > SET_Y_MIN && SET_Y_EQU < SET_Y_MAX &&
        ButtonLPressed == sfTrue) {
        second_state(s);
    } else {
        third_state(s);
    }
}
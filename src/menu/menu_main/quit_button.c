/*
** EPITECH PROJECT, 2019
** quit_button
** File description:
** quit_button
*/

#include "my_rpg.h"
#include "menu_rpg.h"

static void first_state(summary_t *s)
{
    SpriteSetPosition(s->menu.main.quit[MOUS], C_QIT_BUT);
    DrawSprite(s->win.window, s->menu.main.quit[MOUS], NULL);
    if (s->menu.main.previous_quit == sfTrue)
        s->scene_number[0] = 2;
    disp_line(s, 1, &s->menu.main.lines[QUIT]);
    s->menu.main.previous_settings = sfFalse;
}

static void second_state(summary_t *s)
{
    SpriteSetPosition(s->menu.main.quit[CLIC], C_QIT_BUT);
    DrawSprite(s->win.window, s->menu.main.quit[CLIC], NULL);
    s->menu.main.previous_quit = sfTrue;
    disp_line(s, 2, &s->menu.main.lines[QUIT]);
}

static void third_state(summary_t *s)
{
    SpriteSetPosition(s->menu.main.quit[BASE], C_QIT_BUT);
    DrawSprite(s->win.window, s->menu.main.quit[BASE], NULL);
    s->menu.main.previous_quit = sfFalse;
    disp_line(s, 0, &s->menu.main.lines[QUIT]);
}

void quit_button(int const *pos, summary_t *s)
{
    if (QIT_X_EQU > QIT_X_MIN && QIT_X_EQU < QIT_X_MAX &&
        QIT_Y_EQU > QIT_Y_MIN && QIT_Y_EQU < QIT_Y_MAX &&
        ButtonLPressed == sfFalse) {
        first_state(s);
    } else if (QIT_X_EQU > QIT_X_MIN && QIT_X_EQU < QIT_X_MAX &&
        QIT_Y_EQU > QIT_Y_MIN && QIT_Y_EQU < QIT_Y_MAX &&
        ButtonLPressed == sfTrue) {
        second_state(s);
    } else {
        third_state(s);
    }
}
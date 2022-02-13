/*
** EPITECH PROJECT, 2019
** back_main_menu_but
** File description:
** back_main_menu_but
*/

#include "my_rpg.h"
#include "menu_rpg.h"

static void first_state(summary_t *s)
{
    SpriteSetPosition(s->menu.m_pause.spr_main[MOUS], C_BCK_BUT);
    DrawSprite(s->win.window, s->menu.m_pause.spr_main[MOUS], NULL);
    if (s->menu.m_pause.previous_back == sfTrue) {
        s->scene_number[0] = 0;
        s->scene_number[1] = -1;
    }
    disp_line(s, 1, &s->menu.main.lines[3]);
    s->menu.main.previous_settings = sfFalse;
}

static void second_state(summary_t *s)
{
    SpriteSetPosition(s->menu.m_pause.spr_main[CLIC], C_BCK_BUT);
    DrawSprite(s->win.window, s->menu.m_pause.spr_main[CLIC], NULL);
    s->menu.m_pause.previous_back = sfTrue;
    disp_line(s, 2, &s->menu.main.lines[3]);
}

static void third_state(summary_t *s)
{
    SpriteSetPosition(s->menu.m_pause.spr_main[BASE], C_BCK_BUT);
    DrawSprite(s->win.window, s->menu.m_pause.spr_main[BASE], NULL);
    s->menu.m_pause.previous_back = sfFalse;
    disp_line(s, 0, &s->menu.main.lines[3]);
}

void back_main_button(int const *pos, summary_t *s)
{
    if (BCK_X_EQU > BCK_X_MIN && BCK_X_EQU < BCK_X_MAX &&
        BCK_Y_EQU > BCK_Y_MIN && BCK_Y_EQU < BCK_Y_MAX &&
        ButtonLPressed == sfFalse) {
        first_state(s);
    } else if (BCK_X_EQU > BCK_X_MIN && BCK_X_EQU < BCK_X_MAX &&
        BCK_Y_EQU > BCK_Y_MIN && BCK_Y_EQU < BCK_Y_MAX &&
        ButtonLPressed == sfTrue) {
        second_state(s);
    } else {
        third_state(s);
    }
}
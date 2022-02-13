/*
** EPITECH PROJECT, 2019
** play_button
** File description:
** play_button
*/

#include "my_rpg.h"
#include "menu_rpg.h"
#include <math.h>

void game_scenes(summary_t *s)
{
    s->scene_number[0] = 10;
    s->scene_number[1] = -1;
    s->history.step = 0;
    s->history.i = 0;
    sfMusic_pause(s->music[M_MENU]);
    sfMusic_play(s->music[M_IN_GAME]);
}

void button_play_pressed(summary_t *s)
{
    SpriteSetPosition(s->menu.main.play[MOUS], C_PLAY_BUT);
    DrawSprite(s->win.window, s->menu.main.play[MOUS], NULL);
    if (s->menu.main.previous_play == sfTrue)
        game_scenes(s);
    s->menu.main.previous_play = sfFalse;
    s->menu.m_pause.active = sfFalse;
    disp_line(s, 1, &s->menu.main.lines[PLAY]);
}

void play_button(int const *pos, summary_t *s)
{
    if (PLAY_X_EQU > PLAY_X_MIN && PLAY_X_EQU < PLAY_X_MAX &&
        PLAY_Y_EQU > PLAY_Y_MIN && PLAY_Y_EQU < PLAY_Y_MAX &&
        ButtonLPressed == sfFalse) {
        button_play_pressed(s);
    } else if (PLAY_X_EQU > PLAY_X_MIN && PLAY_X_EQU < PLAY_X_MAX &&
        PLAY_Y_EQU > PLAY_Y_MIN && PLAY_Y_EQU < PLAY_Y_MAX &&
        ButtonLPressed == sfTrue) {
        SpriteSetPosition(s->menu.main.play[CLIC], C_PLAY_BUT);
        DrawSprite(s->win.window, s->menu.main.play[CLIC], NULL);
        s->menu.main.previous_play = sfTrue;
        disp_line(s, 2, &s->menu.main.lines[PLAY]);
    } else {
        SpriteSetPosition(s->menu.main.play[BASE], C_PLAY_BUT);
        DrawSprite(s->win.window, s->menu.main.play[BASE], NULL);
        s->menu.main.previous_play = sfFalse;
        disp_line(s, 0, &s->menu.main.lines[PLAY]);
    }
}

void button_pause_pressed(summary_t *s)
{
    SpriteSetPosition(s->menu.main.play[CLIC], C_PLAY_BUT);
    DrawSprite(s->win.window, s->menu.main.play[CLIC], NULL);
    setup_scene_pause(s);
    disp_line(s, 2, &s->menu.main.lines[PLAY]);
    s->menu.main.previous_play = sfTrue;
}

void play_button_pause(int const *pos, summary_t *s)
{
    if (PLAY_X_EQU > PLAY_X_MIN && PLAY_X_EQU < PLAY_X_MAX &&
        PLAY_Y_EQU > PLAY_Y_MIN && PLAY_Y_EQU < PLAY_Y_MAX &&
        ButtonLPressed == sfFalse) {
        SpriteSetPosition(s->menu.main.play[MOUS], C_PLAY_BUT);
        DrawSprite(s->win.window, s->menu.main.play[MOUS], NULL);
        s->menu.main.previous_play = sfFalse;
        disp_line(s, 1, &s->menu.main.lines[PLAY]);
    } else if (PLAY_X_EQU > PLAY_X_MIN && PLAY_X_EQU < PLAY_X_MAX &&
        PLAY_Y_EQU > PLAY_Y_MIN && PLAY_Y_EQU < PLAY_Y_MAX &&
        ButtonLPressed == sfTrue) {
        button_pause_pressed(s);
    } else {
        SpriteSetPosition(s->menu.main.play[BASE], C_PLAY_BUT);
        DrawSprite(s->win.window, s->menu.main.play[BASE], NULL);
        s->menu.main.previous_play = sfFalse;
        disp_line(s, 0, &s->menu.main.lines[PLAY]);
    }
}
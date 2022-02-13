/*
** EPITECH PROJECT, 2019
** menu_pause
** File description:
** menu_pause
*/

#include "my_rpg.h"
#include "menu_rpg.h"

char menu_pause(summary_t *s)
{
    int pos[2];

    DrawSprite(s->win.window, s->menu.m_pause.spr_pause, NULL);
    pos[0] = calc_x_position(s->win, MouseGetPos(s->win.window).x);
    pos[1] = calc_y_position(s->win, MouseGetPos(s->win.window).y);
    play_button_pause(pos, s);
    settings_button(pos, s);
    quit_button(pos, s);
    back_main_button(pos, s);
    return (SUCCESS);
}

void lauch_pause(summary_t *s)
{
    for (int a = 0; s->scene_number[a] != -1; ++a) {
        s->old_scene_nb[a] = s->scene_number[a];
        s->old_scene_nb[a + 1] = -1;
        s->old_scene_settings[a] = s->scene_number[a];
        s->old_scene_settings[a + 1] = -1;
    }
    s->menu.m_pause.active = sfTrue;
    s->scene_number[0] = 4;
    s->scene_number[1] = -1;
    s->mtime->actual_pause = sfClock_getElapsedTime(s->mtime->clock);
}

void reset_game_af_pause(summary_t *s)
{
    for (int a = 0; s->old_scene_settings[a] != -1; ++a) {
        s->scene_number[a] = s->old_scene_settings[a];
        s->scene_number[a + 1] = -1;
    }
    s->mtime->timepause.microseconds = s->mtime->timepause.microseconds +
    (sfClock_getElapsedTime(s->mtime->clock).microseconds -
    s->mtime->actual_pause.microseconds);
    s->menu.m_pause.active = sfFalse;
}

void setup_scene_pause(summary_t *s)
{
    if (s->scene_number[0] != 0 && s->scene_number[0] != 1
        && s->menu.m_pause.active == sfFalse) {
        sfMusic_play(s->music[3]);
        lauch_pause(s);
        set_pause_music(s);
    } else if (s->scene_number[0] != 0 && s->scene_number[0] != 1 &&
        s->menu.m_pause.active == sfTrue) {
        restart_pause_music(s);
        reset_game_af_pause(s);
        sfMusic_pause(s->music[3]);
    }
}

void start_pause(summary_t *s)
{
    if (s->win.event.type == sfEvtKeyPressed &&
        s->win.event.key.code == sfKeyEscape) {
        setup_scene_pause(s);
    }
}

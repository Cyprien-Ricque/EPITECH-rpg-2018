/*
** EPITECH PROJECT, 2019
** init_menu
** File description:
** init_menu
*/

#include "my_rpg.h"

void set_pos_text_settings(settings_t *s)
{
    sfText_setCharacterSize(s->fps_text[2], 70);
    sfText_setPosition(s->music_text[0], (sfVector2f) {1240, 685});
    sfText_setPosition(s->music_text[1], (sfVector2f) {1248, 685});
    sfText_setPosition(s->v_sync_text[0], (sfVector2f) {1240, 420});
    sfText_setPosition(s->v_sync_text[1], (sfVector2f) {1248, 420});
    sfText_setPosition(s->fl_screen[0], (sfVector2f) {1240, 290});
    sfText_setPosition(s->fl_screen[1], (sfVector2f) {1248, 290});
    sfText_setPosition(s->fps_text[0], (sfVector2f) {1248, 555});
    sfText_setPosition(s->fps_text[1], (sfVector2f) {1248, 555});
    sfText_setPosition(s->fps_text[2], (sfVector2f) {1248, 555});
    sfText_setColor(s->music_text[0], sfBlack);
    sfText_setColor(s->music_text[1], sfBlack);
    sfText_setColor(s->v_sync_text[0], sfBlack);
    sfText_setColor(s->v_sync_text[1], sfBlack);
    sfText_setColor(s->fl_screen[0], sfBlack);
    sfText_setColor(s->fl_screen[1], sfBlack);
    sfText_setColor(s->fps_text[0], sfBlack);
    sfText_setColor(s->fps_text[1], sfBlack);
    sfText_setColor(s->fps_text[2], sfBlack);
}

void set_text_default(settings_t *s)
{
    sfText_setString(s->music_text[0], "Off");
    sfText_setString(s->music_text[1], "On");
    sfText_setString(s->v_sync_text[0], "Off");
    sfText_setString(s->v_sync_text[1], "On");
    sfText_setString(s->fl_screen[0], "On");
    sfText_setString(s->fl_screen[1], "Off");
    sfText_setString(s->fps_text[0], "30");
    sfText_setString(s->fps_text[1], "60");
    sfText_setString(s->fps_text[2], "120");
    for (int a = 0; a < 2; ++a) {
        sfText_setFont(s->music_text[a], s->font_settings);
        sfText_setFont(s->v_sync_text[a], s->font_settings);
        sfText_setFont(s->fl_screen[a], s->font_settings);
        sfText_setFont(s->fps_text[a], s->font_settings);
        sfText_setCharacterSize(s->music_text[a], 70);
        sfText_setCharacterSize(s->v_sync_text[a], 70);
        sfText_setCharacterSize(s->fl_screen[a], 70);
        sfText_setCharacterSize(s->fps_text[a], 70);
    }
    sfText_setFont(s->fps_text[2], s->font_settings);
}

char init_text_settings(settings_t *s)
{
    s->music_text[0] = sfText_create();
    s->music_text[1] = sfText_create();
    s->v_sync_text[0] = sfText_create();
    s->v_sync_text[1] = sfText_create();
    s->fl_screen[0] = sfText_create();
    s->fl_screen[1] = sfText_create();
    s->fps_text[0] = sfText_create();
    s->fps_text[1] = sfText_create();
    s->fps_text[2] = sfText_create();
    if (!s->music_text[0] || !s->music_text[1] || !s->v_sync_text[0] ||
        !s->v_sync_text[1] || !s->fl_screen[0] || !s->fl_screen[1] ||
        !s->fps_text[0] || !s->fps_text[1] || !s->fps_text[2])
        return (FAILURE);
    set_text_default(s);
    set_pos_text_settings(s);
    return (SUCCESS);
}

char init_menu(summary_t *s)
{
    s->win.size.x = 1920;
    s->win.size.y = 1080;
    s->menu.main.previous_play = sfFalse;
    s->menu.main.previous_settings = sfFalse;
    s->menu.main.previous_quit = sfFalse;
    s->menu.m_pause.previous_back = sfFalse;
    s->menu.settings.sound_active = sfTrue;
    s->menu.settings.vertical_sync = sfFalse;
    s->menu.settings.fullscreen = sfFalse;
    s->menu.settings.fps = 0;
    s->mtime->timepause.microseconds = 0;
    s->mtime->actual_pause.microseconds = 0;
    s->menu.settings.old_status = -1;
    s->old_scene_nb[0] = -1;
    sfRenderWindow_setFramerateLimit(s->win.window, 30);
    return (SUCCESS);
}
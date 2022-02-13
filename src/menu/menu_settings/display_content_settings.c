/*
** EPITECH PROJECT, 2019
** display_content_settings
** File description:
** display_content_settings
*/

#include "my_rpg.h"
#include "menu_rpg.h"

void display_fullscreen_set(summary_t *s)
{
    sfText_setColor(s->menu.settings.fl_screen[0], sfWhite);
    sfText_setColor(s->menu.settings.fl_screen[1], sfWhite);
    if (s->menu.settings.fullscreen == sfTrue)
        DrawText(s->win.window, s->menu.settings.fl_screen[0], NULL);
    else
        DrawText(s->win.window, s->menu.settings.fl_screen[1], NULL);
}

void display_vsync_set(summary_t *s)
{
    sfText_setColor(s->menu.settings.v_sync_text[0], sfWhite);
    sfText_setColor(s->menu.settings.v_sync_text[1], sfWhite);
    if (s->menu.settings.vertical_sync == sfFalse)
        DrawText(s->win.window, s->menu.settings.v_sync_text[0], NULL);
    else
        DrawText(s->win.window, s->menu.settings.v_sync_text[1], NULL);
}

void display_framerate_set(summary_t *s)
{
    sfText_setColor(s->menu.settings.fps_text[s->menu.settings.fps], sfWhite);
    DrawText(s->win.window, s->menu.settings.fps_text[s->menu.settings.fps],
        NULL);
}

void display_music_set(summary_t *s)
{
    sfText_setColor(s->menu.settings.music_text[0], sfWhite);
    sfText_setColor(s->menu.settings.music_text[1], sfWhite);
    if (s->menu.settings.sound_active == sfFalse)
        DrawText(s->win.window, s->menu.settings.music_text[0], NULL);
    else
        DrawText(s->win.window, s->menu.settings.music_text[1], NULL);
}

void display_content_settings(summary_t *s)
{
    display_fullscreen_set(s);
    display_vsync_set(s);
    display_framerate_set(s);
    display_music_set(s);
}
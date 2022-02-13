/*
** EPITECH PROJECT, 2019
** chg_settings
** File description:
** chg_settings
*/

#include "my_rpg.h"
#include "menu_rpg.h"

const char frames[3] = {30, 60, 120};

void chg_full_screen(summary_t *s, char status)
{
    if ((status == 10 && s->menu.settings.old_status == 1) ||
        (status == 50 && s->menu.settings.old_status == 5)) {
        if (s->menu.settings.fullscreen == sfTrue) {
            s->menu.settings.fullscreen = sfFalse;
            sfRenderWindow_close(s->win.window);
            sfRenderWindow_destroy(s->win.window);
            s->win.window =
                sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "my_RPG",
                sfClose | sfResize, NULL);
        } else {
            s->menu.settings.fullscreen = sfTrue;
            sfRenderWindow_close(s->win.window);
            sfRenderWindow_destroy(s->win.window);
            s->win.window =
                sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "my_RPG",
                sfClose | sfFullscreen, NULL);
        }
    }
}

void chg_v_sync(summary_t *s, char status)
{
    if ((status == 20 && s->menu.settings.old_status == 2) ||
        (status == 60 && s->menu.settings.old_status == 6)) {
        if (s->menu.settings.vertical_sync == sfTrue) {
            s->menu.settings.vertical_sync = sfFalse;
            sfRenderWindow_setVerticalSyncEnabled(s->win.window, sfFalse);
        } else {
            s->menu.settings.vertical_sync = sfTrue;
            sfRenderWindow_setVerticalSyncEnabled(s->win.window, sfTrue);
        }
    }
}

void chg_framerate(summary_t *s, char status)
{
    if (status == 30 && s->menu.settings.old_status == 3) {
        if (s->menu.settings.fps == 0)
            s->menu.settings.fps = 2;
        else
            --s->menu.settings.fps;
        sfRenderWindow_setFramerateLimit(s->win.window,
            frames[s->menu.settings.fps]);
    } else if (status == 70 && s->menu.settings.old_status == 7) {
        if (s->menu.settings.fps == 2)
            s->menu.settings.fps = 0;
        else
            ++s->menu.settings.fps;
        sfRenderWindow_setFramerateLimit(s->win.window,
            frames[s->menu.settings.fps]);
    }
}

void chg_sound(summary_t *s, char status)
{
    if ((status == 40 && s->menu.settings.old_status == 4) ||
        (status == 80 && s->menu.settings.old_status == 8)) {
        if (s->menu.settings.sound_active == sfTrue) {
            s->menu.settings.sound_active = sfFalse;
            for (int a = 0; a < NB_MUSIC; ++a)
                sfMusic_setVolume(s->music[a], 0.0);
        } else {
            s->menu.settings.sound_active = sfTrue;
            for (int a = 0; a < NB_MUSIC; ++a)
                sfMusic_setVolume(s->music[a], 100.0);
        }
    }
}
/*
** EPITECH PROJECT, 2019
** scenes
** File description:
** scenes_organization
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include "my_rpg.h"
#include "menu_rpg.h"

char (*scenes[])(summary_t *summary) =
{
    menu_main, menu_settings, menu_quit, main_game, menu_pause,
    fight_scenes, user_stat, inventory, disp_shop, new_tank,
    history_scene, game_over, victory, rain, NULL
};

void update_time(summary_t *s)
{
    s->rain.old_time = (s->mtime->time.microseconds / 500000.0) -
        (s->mtime->timepause.microseconds / 500000.0);
    s->mtime->time = sfClock_getElapsedTime(s->mtime->clock);
    s->mtime->seconds = (float)((s->mtime->time.microseconds / 500000.0) -
        s->mtime->timepause.microseconds / 500000.0);
}

char scenes_display(summary_t *summary)
{
    for (int i = 0; summary->scene_number[i] != -1 && i < MAX_SCENES; ++i) {
        if (scenes[summary->scene_number[i]](summary) == FAILURE)
            return (FAILURE);
    }
    return (SUCCESS);
}

char main_scenes(summary_t *summary)
{
    while (sfRenderWindow_isOpen(summary->win.window)) {
        update_time(summary);
        events(summary);
        scenes_display(summary);
        sfRenderWindow_display(summary->win.window);
        sfRenderWindow_clear(summary->win.window, sfBlack);
    }
    return (SUCCESS);
}
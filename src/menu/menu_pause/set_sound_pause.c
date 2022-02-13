/*
** EPITECH PROJECT, 2019
** set_sound_pause
** File description:
** set_sound_pause
*/

#include "my_rpg.h"
#include "menu_rpg.h"

void set_pause_music(summary_t *s)
{
    for (int a = 0; a < NB_MUSIC; ++a) {
        if (sfMusic_getStatus(s->music[a]) == sfPlaying && a != M_MENU) {
            sfMusic_pause(s->music[a]);
            s->music_status[a] = sfTrue;
        } else {
            s->music_status[a] = sfFalse;
        }
    }
}

void restart_pause_music(summary_t *s)
{
    for (int a = 0; a < NB_MUSIC; ++a) {
        if (s->music_status[a] == sfTrue && a != M_MENU)
            sfMusic_play(s->music[a]);
    }
}
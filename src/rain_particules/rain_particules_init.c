/*
** EPITECH PROJECT, 2019
** rain_particules_init
** File description:
** rain_particules_init
*/

#include "my_rpg.h"

char rain(summary_t *s)
{
    for (int a = 0; a < NB_RAIN; ++a) {
        if (s->rain.in_pos[a] == sfFalse && (rand() % 100) == 3) {
            s->rain.position[a].x = rand() % 1920;
            s->rain.position[a].y = 0.0;
            s->rain.in_pos[a] = sfTrue;
        } else if (s->rain.in_pos[a] == sfTrue &&
            (s->rain.position[a].x < 0 || s->rain.position[a].x > 1920.0
            || s->rain.position[a].y < 0 || s->rain.position[a].y > 1080.0)) {
            s->rain.in_pos[a] = sfFalse;
        }
        if (s->rain.in_pos[a] == sfTrue) {
            s->rain.position[a].y += (70.0 * VALUE);
            s->rain.position[a].x -= ((rand() % 7) * VALUE);
            sfSprite_setPosition(s->rain.spr, s->rain.position[a]);
            sfRenderWindow_drawSprite(s->win.window, s->rain.spr, NULL);
        }
    }
    return (SUCCESS);
}

char rain_init(summary_t *s)
{
    s->rain.tex = TextureFromFile(RAIN, NULL);
    s->rain.spr = sfSprite_create();
    s->mtime->previous_pause.microseconds = 0;
    if (!s->rain.tex || !s->rain.spr)
        return (FAILURE);
    SpriteSetTexture(s->rain.spr, s->rain.tex, sfTrue);
    if (!s->rain.spr)
        return (FAILURE);
    for (int a = 0; a < NB_RAIN; ++a) {
        s->rain.in_pos[a] = sfFalse;
    }
    s->rain.old_time = 0;
    return (SUCCESS);
}
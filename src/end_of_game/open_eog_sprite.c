/*
** EPITECH PROJECT, 2019
** open_eof_sprite.c_
** File description:
** open game_over and victory screen
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>
#include <unistd.h>

char open_eof_texture(summary_t *sum)
{
    sum->eog.game_over_tt = TextureFromFile(GAME_OVER, NULL);
    sum->eog.victory_tt = TextureFromFile(VICTORY, NULL);
    if (!sum->eog.game_over_tt || !sum->eog.victory_tt)
        return (FAILURE);
    return (SUCCESS);
}

char open_eof(summary_t *sum)
{
    if (open_eof_texture(sum) == FAILURE)
        return (FAILURE);
    sum->eog.game_over_spr = sfSprite_create();
    sum->eog.victory_spr = sfSprite_create();
    if (!sum->eog.game_over_spr || !sum->eog.victory_spr)
        return (FAILURE);
    sfSprite_setTexture(sum->eog.game_over_spr,
        sum->eog.game_over_tt, sfTrue);
    sfSprite_setTexture(sum->eog.victory_spr,
        sum->eog.victory_tt, sfTrue);
    if (!sum->eog.game_over_spr || !sum->eog.victory_spr)
        return (FAILURE);
    return (SUCCESS);
}

void game_over_or_victory_events(summary_t *sum)
{
    if (sum->win.event.type == sfEvtKeyPressed
        && sum->win.event.key.code == sfKeyB)
        sum->scene_number[0] = 0;
    if (sum->win.event.type == sfEvtKeyPressed
        && sum->win.event.key.code == sfKeyQ)
        sfRenderWindow_close(sum->win.window);
}

char victory(summary_t *sum)
{
    sfRenderWindow_drawSprite(sum->win.window,
        sum->eog.victory_spr, NULL);
    return (SUCCESS);
}

char game_over(summary_t *sum)
{
    sfRenderWindow_drawSprite(sum->win.window,
        sum->eog.game_over_spr, NULL);
    return (SUCCESS);
}

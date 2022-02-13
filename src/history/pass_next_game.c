/*
** EPITECH PROJECT, 2019
** pass_next_game
** File description:
** pass_next_game
*/

#include "my_rpg.h"

void pass_to_history(summary_t *s)
{
    if (s->history.step == 3 ||
        s->history_content.history[s->history.step] == NULL) {
        s->scene_number[0] = 12;
        s->scene_number[1] = -1;
    } else {
        s->scene_number[0] = 10;
        s->scene_number[1] = -1;
    }
}

void pass_to_next_map(summary_t *s)
{
    s->scene_number[0] = 3;
    s->scene_number[1] = 6;
    s->scene_number[2] = 13;
    s->scene_number[3] = -1;
    s->history.i = 0;
    s->history.step++;
}

void history_events(summary_t *sum)
{
    if (sum->win.event.type == sfEvtKeyPressed
        && sum->win.event.key.code == sfKeySpace) {
        if (sum->history_content.history[sum->history.step][sum->history.i + 1]
            == NULL)
            pass_to_next_map(sum);
        else
            sum->history.i++;
    }
    if (sum->win.event.type == sfEvtKeyPressed
        && sum->win.event.key.code == sfKeyS)
        pass_to_next_map(sum);
}

void display_bubble(const summary_t *sum, int number)
{
    if (number == USER) {
        sfRenderWindow_drawSprite(sum->win.window,
        sum->history.h_spr[SPR_L_BUBBLE], NULL);
    } else {
        sfRenderWindow_drawSprite(sum->win.window,
        sum->history.h_spr[SPR_R_BUBBLE], NULL);
    }
}

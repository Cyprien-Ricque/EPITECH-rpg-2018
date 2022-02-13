/*
** EPITECH PROJECT, 2019
** history_scene.c
** File description:
** history scene
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>
#include <unistd.h>

void display_characters(const summary_t *sum, int number)
{
    sfSprite_setTextureRect(sum->history.h_spr[SPR_CHARACTERS],
    (sfIntRect){0, 0, 129, 161});
    sfSprite_setPosition(sum->history.h_spr[SPR_CHARACTERS],
    (sfVector2f){100, 783});
    sfRenderWindow_drawSprite(sum->win.window,
    sum->history.h_spr[SPR_CHARACTERS], NULL);
    if (number != 0) {
        sfSprite_setTextureRect(sum->history.h_spr[SPR_CHARACTERS],
        (sfIntRect) {0, 161 * number, 129, 161});
        sfSprite_setPosition(sum->history.h_spr[SPR_CHARACTERS],
        (sfVector2f) {1691, 783});
        sfRenderWindow_drawSprite(sum->win.window,
        sum->history.h_spr[SPR_CHARACTERS], NULL);
    }
}

void display_history_background(summary_t *sum)
{
    if (sum->history.step == 0) {
        sfRenderWindow_drawSprite(sum->win.window,
        sum->history.h_spr[SPR_H_STREET], NULL);
    } else if (sum->history.step == 0) {
        sfRenderWindow_drawSprite(sum->win.window,
        sum->history.h_spr[SPR_H_PALACE], NULL);
    } else {
        sfRenderWindow_drawSprite(sum->win.window,
        sum->history.h_spr[SPR_H_DOCK], NULL);
    }
}

void offset_of_backslashn(const summary_t *sum, int p)
{
    int f;

    for (f = p + 1; sum->history_content.
        history[sum->history.step][sum->history.i][f] != '\0'; f++) {
        sum->history_content.
        history[sum->history.step][sum->history.i][f] =
        sum->history_content.
        history[sum->history.step][sum->history.i][f + 1];
    }
    sum->history_content.
    history[sum->history.step][sum->history.i][f + 1] = '\0';
}

void add_backslashn(summary_t *sum)
{
    int p;

    for (p = 0; sum->history_content.
        history[sum->history.step][sum->history.i][p] != '\0'; p++) {
        if (sum->history_content.
            history[sum->history.step][sum->history.i][p] == '\\' &&
            sum->history_content.
            history[sum->history.step][sum->history.i][p + 1] == 'n') {
            sum->history_content.
            history[sum->history.step][sum->history.i][p] = '\n';
            offset_of_backslashn(sum, p);
        }
    }
}

char history_scene(summary_t *sum)
{
    int number = m_getnb(sum->history_content.history[sum->history.step]
        [sum->history.i]);

    display_history_background(sum);
    display_bubble(sum, number);
    display_characters(sum, number);
    add_backslashn(sum);
    sfText_setString(sum->history.h_txt, &sum->history_content
    .history[sum->history.step][sum->history.i][1]);
    if (number == USER) {
        sfText_setPosition(sum->history.h_txt, (sfVector2f){150, 533});
    } else {
        sfText_setPosition(sum->history.h_txt, (sfVector2f){1261, 533});
    }
    sfRenderWindow_drawText(sum->win.window, sum->history.h_txt, NULL);
    return (SUCCESS);
}
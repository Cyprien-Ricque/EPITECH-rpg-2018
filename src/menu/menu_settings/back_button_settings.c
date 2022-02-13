/*
** EPITECH PROJECT, 2019
** back_button_settings
** File description:
** back_button_settings
*/

#include "my_rpg.h"
#include "menu_rpg.h"

static void first_state(summary_t *s)
{
    SpriteSetPosition(s->menu.settings.spr_back_but[MOUS], C_BACK_BUT);
    DrawSprite(s->win.window, s->menu.settings.spr_back_but[MOUS], NULL);
    s->menu.main.previous_play = sfFalse;
}

static void second_state(summary_t *s)
{
    SpriteSetPosition(s->menu.settings.spr_back_but[CLIC], C_BACK_BUT);
    DrawSprite(s->win.window, s->menu.settings.spr_back_but[CLIC], NULL);
    for (int a = 0; s->old_scene_nb[a] != -1; ++a) {
        s->scene_number[a] = s->old_scene_nb[a];
        s->scene_number[a + 1] = -1;
    }
    s->menu.main.previous_play = sfTrue;
}

static void third_state(summary_t *s)
{
    SpriteSetPosition(s->menu.settings.spr_back_but[BASE], C_BACK_BUT);
    DrawSprite(s->win.window, s->menu.settings.spr_back_but[BASE], NULL);
    s->menu.main.previous_play = sfFalse;
}

void setup_button_back(summary_t *s, int const pos[2])
{
    if (BACK_X_EQU > BACK_X_MIN && BACK_X_EQU < BACK_X_MAX &&
        BACK_Y_EQU > BACK_Y_MIN && BACK_Y_EQU < BACK_Y_MAX &&
        ButtonLPressed == sfFalse)
        first_state(s);
    else if (BACK_X_EQU > BACK_X_MIN && BACK_X_EQU < BACK_X_MAX && BACK_Y_EQU
        > BACK_Y_MIN && BACK_Y_EQU < BACK_Y_MAX && ButtonLPressed == sfTrue)
        second_state(s);
    else
        third_state(s);
}

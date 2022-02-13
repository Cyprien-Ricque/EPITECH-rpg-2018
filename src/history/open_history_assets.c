/*
** EPITECH PROJECT, 2019
** open_history_assets.c
** File description:
** open history assets
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>
#include <unistd.h>

char create_textures_history(history_t *history)
{
    history->h_tt[TT_CHARACTERS] = TextureFromFile(CHARACTERS, NULL);
    history->h_tt[TT_L_BUBBLE] = TextureFromFile(L_BUBBLE, NULL);
    history->h_tt[TT_R_BUBBLE] = TextureFromFile(R_BUBBLE, NULL);
    history->h_tt[TT_H_STREET] = TextureFromFile(H_STREET, NULL);
    history->h_tt[TT_H_PALACE] = TextureFromFile(H_PALACE, NULL);
    history->h_tt[TT_H_DOCK] = TextureFromFile(H_DOCK, NULL);
    if (!history->h_tt[TT_CHARACTERS] || !history->h_tt[TT_L_BUBBLE] ||
    !history->h_tt[TT_R_BUBBLE] || !history->h_tt[TT_H_STREET] ||
    !history->h_tt[TT_H_PALACE] || !history->h_tt[TT_H_DOCK])
        return (FAILURE);
    return (SUCCESS);
}

char create_sprites_history(history_t *history)
{
    history->h_spr[SPR_CHARACTERS] = sfSprite_create();
    history->h_spr[SPR_L_BUBBLE] = sfSprite_create();
    history->h_spr[SPR_R_BUBBLE] = sfSprite_create();
    history->h_spr[SPR_H_STREET] = sfSprite_create();
    history->h_spr[SPR_H_PALACE] = sfSprite_create();
    history->h_spr[SPR_H_DOCK] = sfSprite_create();
    if (!history->h_spr[SPR_CHARACTERS] || !history->h_spr[SPR_L_BUBBLE] ||
    !history->h_spr[SPR_R_BUBBLE] || !history->h_spr[SPR_H_STREET] ||
    !history->h_spr[SPR_H_PALACE] || !history->h_spr[SPR_H_DOCK])
        return (FAILURE);
    return (SUCCESS);
}

char set_texture_history(history_t *history)
{
    sfSprite_setTexture(history->h_spr[SPR_CHARACTERS],
        history->h_tt[TT_CHARACTERS], sfTrue);
    sfSprite_setTexture(history->h_spr[SPR_L_BUBBLE],
        history->h_tt[TT_L_BUBBLE], sfTrue);
    sfSprite_setTexture(history->h_spr[SPR_R_BUBBLE],
        history->h_tt[TT_R_BUBBLE], sfTrue);
    sfSprite_setTexture(history->h_spr[SPR_H_STREET],
        history->h_tt[TT_H_STREET], sfTrue);
    sfSprite_setTexture(history->h_spr[SPR_H_PALACE],
        history->h_tt[TT_H_PALACE], sfTrue);
    sfSprite_setTexture(history->h_spr[SPR_H_DOCK],
        history->h_tt[TT_H_DOCK], sfTrue);
    if (!history->h_spr[SPR_CHARACTERS] || !history->h_spr[SPR_L_BUBBLE] ||
        !history->h_spr[SPR_R_BUBBLE] || !history->h_spr[SPR_H_STREET] ||
        !history->h_spr[SPR_H_PALACE] || !history->h_spr[SPR_H_DOCK])
        return (FAILURE);
    return (SUCCESS);
}

void set_scale_and_pos(const summary_t *sum)
{
    sfSprite_setScale(sum->history.h_spr[SPR_CHARACTERS],
        (sfVector2f) {1.5, 1.5});
    sfSprite_setPosition(sum->history.h_spr[SPR_L_BUBBLE],
        (sfVector2f) {120, 533});
    sfSprite_setPosition(sum->history.h_spr[SPR_R_BUBBLE],
        (sfVector2f) {1231, 533});
    sfText_setFont(sum->history.h_txt, sum->menu.settings.font_settings);
    sfText_setFont(sum->turn.turn_text, sum->menu.settings.font_settings);
    sfText_setCharacterSize(sum->history.h_txt, 47);
    sfText_setCharacterSize(sum->turn.turn_text, 120);
    sfText_setOutlineColor(sum->turn.turn_text, sfBlack);
    sfText_setOutlineThickness(sum->turn.turn_text, 2.0);
    sfText_setPosition(sum->turn.turn_text, (sfVector2f) {840, 440});
    sfText_setFillColor(sum->history.h_txt, sfBlack);
}

char open_history_assets(summary_t *sum)
{
    if (create_textures_history(&sum->history) == FAILURE
    || create_sprites_history(&sum->history) == FAILURE
    || set_texture_history(&sum->history) == FAILURE)
        return (FAILURE);
    sum->history.step = 0;
    sum->history.i = 0;
    sum->history.h_txt = sfText_create();
    if (!sum->history.h_txt)
        return (FAILURE);
    sum->turn.turn_text = sfText_create();
    if (!sum->turn.turn_text)
        return (FAILURE);
    sum->turn.ia_turn = false;
    set_scale_and_pos(sum);
    return (SUCCESS);
}
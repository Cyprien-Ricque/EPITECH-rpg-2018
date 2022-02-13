/*
** EPITECH PROJECT, 2019
** open_sprites_fight
** File description:
** open_sprites_fight
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"

char create_textures_fight_opponents(fight_spr_t *fight_spr)
{
    fight_spr->texture.tt[TT_L_BLUE_TANK] = TextureFromFile(L_BLUE_TANK, NULL);
    fight_spr->texture.tt[TT_R_RED_TANK] = TextureFromFile(R_RED_TANK, NULL);
    if (ERROR_OPPONENT_TEXTURE)
        return (FAILURE);
    return (SUCCESS);
}

char create_sprites_fight_opponents(fight_spr_t *fight_spr)
{
    fight_spr->sprite.spr[SPR_L_BLUE_TANK] = sfSprite_create();
    fight_spr->sprite.spr[SPR_R_RED_TANK] = sfSprite_create();
    if (ERROR_OPPONENT_SPRITE)
        return (FAILURE);
    return (SUCCESS);
}

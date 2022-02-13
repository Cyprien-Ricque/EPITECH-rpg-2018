/*
** EPITECH PROJECT, 2019
** open_sprites_gith.c
** File description:
** open sprite for fight scene
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

char create_textures_fight_scenes(fight_spr_t *fight_spr)
{
    fight_spr->texture.tt[TT_L_FOREST] = TextureFromFile(L_FOREST, NULL);
    fight_spr->texture.tt[TT_R_FOREST] = TextureFromFile(R_FOREST, NULL);
    fight_spr->texture.tt[TT_L_BEACH] = TextureFromFile(L_BEACH, NULL);
    fight_spr->texture.tt[TT_R_BEACH] = TextureFromFile(R_BEACH, NULL);
    fight_spr->texture.tt[TT_L_STREET] = TextureFromFile(L_STREET, NULL);
    fight_spr->texture.tt[TT_R_STREET] = TextureFromFile(R_STREET, NULL);
    fight_spr->texture.tt[TT_DIVISION] = TextureFromFile(DIVISION, NULL);
    fight_spr->texture.tt[TT_EXPLOSION] = TextureFromFile(EXPLOSION, NULL);
    if (ERROR_FIGHT_SCENES_TEXTURE)
        return (FAILURE);
    return (SUCCESS);
}

char create_sprites_fight_scenes(fight_spr_t *fight_spr)
{
    fight_spr->sprite.spr[SPR_L_FOREST] = sfSprite_create();
    fight_spr->sprite.spr[SPR_R_FOREST] = sfSprite_create();
    fight_spr->sprite.spr[SPR_L_BEACH] = sfSprite_create();
    fight_spr->sprite.spr[SPR_R_BEACH] = sfSprite_create();
    fight_spr->sprite.spr[SPR_L_STREET] = sfSprite_create();
    fight_spr->sprite.spr[SPR_R_STREET] = sfSprite_create();
    fight_spr->sprite.spr[SPR_DIVISION] = sfSprite_create();
    fight_spr->sprite.spr[SPR_EXPLOSION] = sfSprite_create();
    if (ERROR_FIGHT_SCENES_SPRITE)
        return (FAILURE);
    return (SUCCESS);
}

char set_texture_fight_scenes_sprites(fight_spr_t *fight_spr)
{
    sfSprite_setTexture(fight_spr->sprite.spr[SPR_L_FOREST],
        fight_spr->texture.tt[TT_L_FOREST], sfTrue);
    sfSprite_setTexture(fight_spr->sprite.spr[SPR_R_FOREST],
        fight_spr->texture.tt[TT_R_FOREST], sfTrue);
    sfSprite_setTexture(fight_spr->sprite.spr[SPR_L_BEACH],
        fight_spr->texture.tt[TT_L_BEACH], sfTrue);
    sfSprite_setTexture(fight_spr->sprite.spr[SPR_R_BEACH],
        fight_spr->texture.tt[TT_R_BEACH], sfTrue);
    sfSprite_setTexture(fight_spr->sprite.spr[SPR_L_STREET],
        fight_spr->texture.tt[TT_L_STREET], sfTrue);
    sfSprite_setTexture(fight_spr->sprite.spr[SPR_R_STREET],
        fight_spr->texture.tt[TT_R_STREET], sfTrue);
    sfSprite_setTexture(fight_spr->sprite.spr[SPR_DIVISION],
        fight_spr->texture.tt[TT_DIVISION], sfTrue);
    sfSprite_setTexture(fight_spr->sprite.spr[SPR_EXPLOSION],
        fight_spr->texture.tt[TT_EXPLOSION], sfTrue);
    if (ERROR_FIGHT_SCENES_SPRITE)
        return (FAILURE);
    return (SUCCESS);
}

int set_position_of_left_element(fight_spr_t *fight_spr)
{
    sfSprite_setPosition(fight_spr->sprite.spr[SPR_R_BEACH],
        (sfVector2f){960, 0});
    sfSprite_setPosition(fight_spr->sprite.spr[SPR_R_FOREST],
        (sfVector2f){960, 0});
    sfSprite_setPosition(fight_spr->sprite.spr[SPR_R_STREET],
        (sfVector2f){960, 0});
    sfSprite_setPosition(fight_spr->sprite.spr[SPR_DIVISION],
        (sfVector2f){953, 0});
    sfSprite_setScale(fight_spr->sprite.spr[SPR_EXPLOSION],
        (sfVector2f){1.2, 1.2});
    return (SUCCESS);
}

char open_fight_scenes_sprites(summary_t *sum)
{
    if (create_textures_fight_scenes(&sum->fight_spr) == FAILURE)
        return (FAILURE);
    if (create_sprites_fight_scenes(&sum->fight_spr) == FAILURE)
        return (FAILURE);
    if (set_texture_fight_scenes_sprites(&sum->fight_spr) == FAILURE)
        return (FAILURE);
    if (set_position_of_left_element(&sum->fight_spr) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
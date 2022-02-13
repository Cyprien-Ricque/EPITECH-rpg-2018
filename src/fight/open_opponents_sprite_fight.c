/*
** EPITECH PROJECT, 2019
** open_sprites_gith.c
** File description:
** open sprite for fight scene
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"

char set_texture_fight_opponents_sprites(fight_spr_t *fight_spr)
{
    sfSprite_setTexture(fight_spr->sprite.spr[SPR_L_BLUE_TANK],
        fight_spr->texture.tt[TT_L_BLUE_TANK], sfTrue);
    sfSprite_setTexture(fight_spr->sprite.spr[SPR_R_RED_TANK],
        fight_spr->texture.tt[TT_R_RED_TANK], sfTrue);
    if (ERROR_OPPONENT_SPRITE)
        return (FAILURE);
    return (SUCCESS);
}

void set_tank_scale(fight_spr_t *fight_spr)
{
    sfSprite_setScale(fight_spr->sprite.spr[SPR_R_RED_TANK],
        (sfVector2f){0.5, 0.5});
    sfSprite_setScale(fight_spr->sprite.spr[SPR_L_BLUE_TANK],
        (sfVector2f){0.5, 0.5});
}

void init_info_fight_value(summary_t *sum)
{
    sum->i_fight.rect_offset_x[USER] = 0;
    sum->i_fight.rect_offset_x[ENNEMY] = 0;
    sum->i_fight.rect_offset_y[USER] = 0;
    sum->i_fight.rect_offset_y[ENNEMY] = 0;
    sum->i_fight.l_tank_fire = false;
    sum->i_fight.r_tank_fire = false;
    sum->i_fight.b_flash = true;
    sum->i_fight.get_time = true;
    sum->i_fight.exp_offset = -1;
    sum->i_fight.flash = 6.0;
}

char set_fight_sound_effects(summary_t *sum)
{
    sum->music[M_RADIO] = sfMusic_createFromFile(OGG_RADIO);
    sum->music[M_GUN_FIRE] = sfMusic_createFromFile(OGG_GUN_FIRE);
    sum->music[M_EXPLOSION] = sfMusic_createFromFile(OGG_EXPLOSION);
    if (!sum->music[M_RADIO] || !sum->music[M_GUN_FIRE] ||
    !sum->music[M_EXPLOSION])
        return (FAILURE);
    return (SUCCESS);
}

char open_fight_opponents_sprites(summary_t *sum)
{
    if (create_textures_fight_opponents(&sum->fight_spr) == FAILURE)
        return (FAILURE);
    if (create_sprites_fight_opponents(&sum->fight_spr) == FAILURE)
        return (FAILURE);
    if (set_texture_fight_opponents_sprites(&sum->fight_spr) == FAILURE)
        return (FAILURE);
    if (set_fight_sound_effects(sum) == FAILURE)
        return (FAILURE);
    init_info_fight_value(sum);
    set_tank_scale(&sum->fight_spr);
    return (SUCCESS);
}
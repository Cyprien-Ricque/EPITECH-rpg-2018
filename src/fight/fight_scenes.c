/*
** EPITECH PROJECT, 2019
** fight_scenes.c
** File description:
** fight scene
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>
#include <unistd.h>

void init_rect(summary_t *sum, int l_x, int r_x)
{
    sfSprite_setTextureRect(sum->fight_spr.sprite.spr[SPR_R_RED_TANK],
        (sfIntRect){r_x, sum->i_fight.rect_offset_y[ENNEMY], 600, 552});
    sfSprite_setTextureRect(sum->fight_spr.sprite.spr[SPR_L_BLUE_TANK],
        (sfIntRect){l_x, sum->i_fight.rect_offset_y[USER], 600, 552});
    sfSprite_setTextureRect(sum->fight_spr.sprite.spr[SPR_EXPLOSION],
        (sfIntRect){192 * sum->i_fight.exp_offset, 0, 192, 192});
}

void dif_var_modification(summary_t *sum, float t_fire)
{
    sum->i_fight.rect_offset_x[USER] = (sum->i_fight.rect_offset_x[USER] ==
        600) ? 0 : 600 * sum->i_fight.l_tank_fire * dif_offset_tank(t_fire);
    sum->i_fight.rect_offset_x[ENNEMY] = (sum->i_fight.rect_offset_x
        [ENNEMY] == 600) ? 0 : 600 * sum->i_fight.r_tank_fire *
        dif_offset_tank(t_fire);
    if (t_fire > 2.5)
        sum->i_fight.l_tank_fire = true;
    if (t_fire > 3.5)
        sum->i_fight.r_tank_fire = true;
    if (t_fire > 5.0) {
        sum->i_fight.exp_offset = (sum->i_fight.exp_offset >= 7) ? 7 :
        dif_offset_exp(t_fire);
    }
}

void init_position(summary_t *sum)
{
    if (sum->fight.background[USER] == STREET ||
        sum->fight.background[USER] == FOREST)
        set_tank_position_street(sum);
    else if (sum->fight.background[USER] == BEACH)
        set_tank_position_beach(sum);
}

void reset_settings(summary_t *sum)
{
    sum->i_fight.exp_offset = -1;
    sum->i_fight.rect_offset_y[USER] = 552 * sum->fight.type[USER];
    sum->i_fight.rect_offset_y[ENNEMY] = 552 * sum->fight.type[ENNEMY];
    sum->i_fight.o_time = sum->mtime->time.microseconds / 1000000.0;
    sum->i_fight.get_time = false;
    sum->i_fight.rect_offset_x[USER] = 0;
    sum->i_fight.rect_offset_x[ENNEMY] = 0;
    sum->i_fight.l_tank_fire = false;
    sum->i_fight.r_tank_fire = false;
    sum->i_fight.b_flash = true;
    sum->i_fight.exp_offset = -1;
    sum->i_fight.flash = 6.0;
}

char fight_scenes(summary_t *sum)
{
    if (sum->i_fight.get_time == true) {
        sfMusic_play(sum->music[M_GUN_FIRE]);
        sfMusic_play(sum->music[M_RADIO]);
        if ((sum->fight.life[0] != sum->fight.life_after_fight[0])
        || (sum->fight.life[1] != sum->fight.life_after_fight[1]))
            sfMusic_play(sum->music[M_EXPLOSION]);
        init_position(sum);
        reset_settings(sum);
    }
    else {
        tank_management(sum);
        display_background(sum);
        sfRenderWindow_drawSprite(sum->win.window, sum->fight_spr.sprite.spr
        [SPR_DIVISION], NULL);
        display_fight_sprite(sum);
    }
    return (SUCCESS);
}
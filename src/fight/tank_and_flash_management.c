/*
** EPITECH PROJECT, 2019
** tank_and_flash_management.c
** File description:
** tank and flash function managemennt
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>
#include <unistd.h>

void flash_management(summary_t *sum, float t_fire)
{
    if (t_fire > sum->i_fight.flash && sum->i_fight.flash < 7.5) {
        if (sum->i_fight.b_flash == true) {
            sum->i_fight.save_e_l = sum->fight.life[ENNEMY];
            sum->i_fight.save_u_l = sum->fight.life[USER];
            sum->fight.life[ENNEMY] = sum->fight.life_after_fight[ENNEMY];
            sum->fight.life[USER] = sum->fight.life_after_fight[USER];
            sum->i_fight.b_flash = false;
        } else {
            sum->fight.life[ENNEMY] = sum->i_fight.save_e_l;
            sum->fight.life[USER] = sum->i_fight.save_u_l;
            sum->i_fight.b_flash = true;
        }
        sum->i_fight.flash += 0.1;
    }
}

void end_of_flash_and_fight_scene(summary_t *sum, float t_fire)
{
    if (sum->i_fight.flash >= 7.5) {
        sum->fight.life[ENNEMY] = sum->fight.life_after_fight[ENNEMY];
        sum->fight.life[USER] = sum->fight.life_after_fight[USER];
        sum->i_fight.l_tank_fire = false;
        sum->i_fight.r_tank_fire = false;
    }
    if (t_fire > 10.0) {
        sum->scene_number[0] = 3;
        sum->scene_number[1] = -1;
        sum->i_fight.get_time = true;
        sfMusic_stop(sum->music[M_RADIO]);
        sfMusic_stop(sum->music[M_GUN_FIRE]);
        sfMusic_stop(sum->music[M_EXPLOSION]);
    }
}

void tank_management(summary_t *sum)
{
    sum->i_fight.a_time = sum->mtime->time.microseconds / 1000000.0;
    dif_var_modification(sum, sum->i_fight.a_time -
    sum->i_fight.o_time);
    flash_management(sum, sum->i_fight.a_time -
    sum->i_fight.o_time);
    end_of_flash_and_fight_scene(sum, sum->i_fight.a_time -
    sum->i_fight.o_time);
    init_rect(sum, sum->i_fight.rect_offset_x[USER],
    sum->i_fight.rect_offset_x[ENNEMY]);
}

void set_tank_position_beach(summary_t *sum)
{
    sum->i_fight.l_pos[0] = (sfVector2f) {450, 550};
    sum->i_fight.l_pos[1] = (sfVector2f) {600, 750};
    sum->i_fight.l_pos[2] = (sfVector2f) {600, 350};
    sum->i_fight.l_pos[3] = (sfVector2f) {200, 700};
    sum->i_fight.l_pos[4] = (sfVector2f) {250, 450};
    sum->i_fight.r_pos[0] = (sfVector2f) {960 + (960 - 400 - 300), 550};
    sum->i_fight.r_pos[1] = (sfVector2f) {960 + (960 - 600 - 300), 750};
    sum->i_fight.r_pos[2] = (sfVector2f) {960 + (960 - 600 - 300), 350};
    sum->i_fight.r_pos[3] = (sfVector2f) {960 + (960 - 150 - 300), 700};
    sum->i_fight.r_pos[4] = (sfVector2f) {960 + (960 - 200 - 300), 450};
}

void set_tank_position_street(summary_t *sum)
{
    sum->i_fight.l_pos[0] = (sfVector2f) {550, 500};
    sum->i_fight.l_pos[1] = (sfVector2f) {200, 400};
    sum->i_fight.l_pos[2] = (sfVector2f) {200, 650};
    sum->i_fight.l_pos[3] = (sfVector2f) {550, 250};
    sum->i_fight.l_pos[4] = (sfVector2f) {550, 750};
    sum->i_fight.r_pos[0] = (sfVector2f) {960 + (960 - 550 - 300), 500};
    sum->i_fight.r_pos[1] = (sfVector2f) {960 + (960 - 200 - 300), 400};
    sum->i_fight.r_pos[2] = (sfVector2f) {960 + (960 - 200 - 300), 650};
    sum->i_fight.r_pos[3] = (sfVector2f) {960 + (960 - 550 - 300), 250};
    sum->i_fight.r_pos[4] = (sfVector2f) {960 + (960 - 550 - 300), 750};
}
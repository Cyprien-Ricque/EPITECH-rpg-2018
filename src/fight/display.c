/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** display function for fight scenes
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>
#include <unistd.h>

void display_background(summary_t *sum)
{
    if (sum->fight.background[USER] == STREET) {
        sfRenderWindow_drawSprite(sum->win.window, sum->fight_spr.sprite.spr
        [SPR_L_STREET], NULL);
    } else if (sum->fight.background[USER] == BEACH) {
        sfRenderWindow_drawSprite(sum->win.window, sum->fight_spr.sprite.spr
        [SPR_L_BEACH], NULL);
    } else {
        sfRenderWindow_drawSprite(sum->win.window, sum->fight_spr.sprite.spr
        [SPR_L_FOREST], NULL);
    }
    if (sum->fight.background[ENNEMY] == STREET) {
        sfRenderWindow_drawSprite(sum->win.window, sum->fight_spr.sprite.spr
        [SPR_R_STREET], NULL);
    } else if (sum->fight.background[ENNEMY] == BEACH) {
        sfRenderWindow_drawSprite(sum->win.window, sum->fight_spr.sprite.spr
        [SPR_R_BEACH], NULL);
    } else {
        sfRenderWindow_drawSprite(sum->win.window, sum->fight_spr.sprite.spr
        [SPR_R_FOREST], NULL);
    }
}

void display_explosion(const summary_t *sum)
{
    int i = sum->fight.life[0];

    while (i > sum->fight.life_after_fight[USER]) {
        sfSprite_setPosition(sum->fight_spr.sprite.spr[SPR_EXPLOSION],
        sum->i_fight.l_pos[i - 1]);
        sfRenderWindow_drawSprite(sum->win.window, sum->fight_spr.sprite.spr
        [SPR_EXPLOSION], NULL);
        i--;
    }
    i = sum->fight.life[1];
    while (i > sum->fight.life_after_fight[ENNEMY]) {
        sfSprite_setPosition(sum->fight_spr.sprite.spr
        [SPR_EXPLOSION], sum->i_fight.r_pos[i - 1]);
        sfRenderWindow_drawSprite(sum->win.window, sum->fight_spr.sprite.spr
        [SPR_EXPLOSION], NULL);
        i--;
    }
}

void display_fight_sprite(summary_t *sum)
{
    int i = 0;

    while (i < sum->fight.life[USER]) {
        sfSprite_setPosition(sum->fight_spr.sprite.spr
        [SPR_L_BLUE_TANK], sum->i_fight.l_pos[i]);
        sfRenderWindow_drawSprite(sum->win.window, sum->fight_spr.sprite.spr
        [SPR_L_BLUE_TANK], NULL);
        i++;
    }
    i = 0;
    while (i < sum->fight.life[ENNEMY]) {
        sfSprite_setPosition(sum->fight_spr.sprite.spr
        [SPR_R_RED_TANK], sum->i_fight.r_pos[i]);
        sfRenderWindow_drawSprite(sum->win.window, sum->fight_spr.sprite.spr
        [SPR_R_RED_TANK], NULL);
        i++;
    }
    display_explosion(sum);
}
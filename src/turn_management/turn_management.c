/*
** EPITECH PROJECT, 2019
** turn_mangement.c
** File description:
** manage turn
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>
#include <unistd.h>

void turn_management(summary_t *sum)
{
    float a_time;

    if (sum->turn.f_call == true) {
        sum->turn.f_call = false;
        sum->turn.o_time = sum->mtime->time.microseconds / 1000000.0;
        if (sum->turn.ia_turn == false) {
            sfText_setFillColor(sum->turn.turn_text, sfWhite);
            sfText_setString(sum->turn.turn_text, "Your Turn");
        } else {
            sfText_setFillColor(sum->turn.turn_text, sfRed);
            sfText_setString(sum->turn.turn_text, "AI Turn");
        }
    }
    a_time = (sum->mtime->time.microseconds / 1000000.0) - sum->turn.o_time;
    if (a_time < 3.0) {
        sfRenderWindow_drawText(sum->win.window, sum->turn.turn_text, NULL);
        sum->turn.laucn_ia = false;
    } else
        sum->turn.laucn_ia = true;
}
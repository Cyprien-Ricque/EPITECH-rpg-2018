/*
** EPITECH PROJECT, 2019
** move_settings_menu
** File description:
** move_settings_menu
*/

#include "my_rpg.h"
#include "menu_rpg.h"
#include <SFML/Audio.h>

const sfVector2f place_arrows[9] = {
    L1_AR, L2_AR, L3_AR, L4_AR, R1_AR, R2_AR, R3_AR, R4_AR
};

void check_change_arrows(summary_t *sum, char status)
{
    chg_full_screen(sum, status);
    chg_v_sync(sum, status);
    chg_framerate(sum, status);
    chg_sound(sum, status);
}

void setup_the_arrows(summary_t *sum, char status)
{
    for (int a = 1; a < 5; ++a) {
        if (status == a)
            display_l_arrow(sum, 1, place_arrows[a - 1]);
        else if (status / 10 == a)
            display_l_arrow(sum, 2, place_arrows[a - 1]);
        else
            display_l_arrow(sum, 0, place_arrows[a - 1]);
    }
    for (int a = 5; a < 9; ++a) {
        if (status == a)
            display_r_arrow(sum, 1, place_arrows[a - 1]);
        else if (status / 10 == a)
            display_r_arrow(sum, 2, place_arrows[a - 1]);
        else
            display_r_arrow(sum, 0, place_arrows[a - 1]);
    }
    check_change_arrows(sum, status);
}
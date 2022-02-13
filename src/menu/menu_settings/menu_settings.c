/*
** EPITECH PROJECT, 2019
** menu_settings
** File description:
** menu_settings
*/

#include "my_rpg.h"
#include "menu_rpg.h"

extern sfVector2f place_arrows[9];

char arrow_is_press(int const pos[2])
{
    char value = 0;

    for (int a = 0; a < 8; ++a) {
        if (pos[0] > place_arrows[a].x && pos[0] < place_arrows[a].x + 43 &&
            pos[1] > place_arrows[a].y && pos[1] < place_arrows[a].y + 110 +
            value && ButtonLPressed == sfTrue)
            return (a + 1);
        else if (pos[0] > place_arrows[a].x && pos[0] < place_arrows[a].x + 43
            && pos[1] > place_arrows[a].y && pos[1] < place_arrows[a].y +
            110 + value)
            return ((a + 1) * 10);
        if (a % 2 != 0)
            value += 8;
    }
    return (-1);
}

void display_l_arrow(summary_t *sum, int arrow_nb, sfVector2f pos)
{
    SpriteSetPosition(sum->menu.settings.spr_l[arrow_nb], pos);
    DrawSprite(sum->win.window, sum->menu.settings.spr_l[arrow_nb], NULL);
}

void display_r_arrow(summary_t *sum, int arrow_nb, sfVector2f pos)
{
    SpriteSetPosition(sum->menu.settings.spr_r[arrow_nb], pos);
    DrawSprite(sum->win.window, sum->menu.settings.spr_r[arrow_nb], NULL);
}

char menu_settings(summary_t *sum)
{
    int pos[2];
    char status;

    pos[0] = calc_x_position(sum->win, MouseGetPos(sum->win.window).x);
    pos[1] = calc_y_position(sum->win, MouseGetPos(sum->win.window).y);
    DrawSprite(sum->win.window, sum->menu.settings.back, NULL);
    status = arrow_is_press(pos);
    setup_the_arrows(sum, status);
    display_content_settings(sum);
    setup_button_back(sum, pos);
    sum->menu.settings.old_status = status;
    return (SUCCESS);
}
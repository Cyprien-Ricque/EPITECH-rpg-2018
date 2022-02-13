/*
** EPITECH PROJECT, 2019
** destroy_useless_texture
** File description:
** destroy_useless_texture
*/

#include "my_rpg.h"

void destroy_menu_ressources(menu_t m)
{
    for (int a = 0; a < 3; ++a) {
        sfTexture_destroy(m.main.tex_quit[a]);
        sfTexture_destroy(m.main.tex_set[a]);
        sfTexture_destroy(m.main.tex_play[a]);
        sfSprite_destroy(m.main.quit[a]);
        sfSprite_destroy(m.main.set[a]);
        sfSprite_destroy(m.main.play[a]);
    }
    sfSprite_destroy(m.main.back_spr);
    sfTexture_destroy(m.main.background);
}

void destroy_ressources(summary_t *sum)
{
    destroy_menu_ressources(sum->menu);
    sfRenderWindow_destroy(sum->win.window);
    sfMusic_destroy(sum->music[M_RADIO]);
    sfMusic_destroy(sum->music[M_GUN_FIRE]);
    sfMusic_destroy(sum->music[M_EXPLOSION]);
    sfMusic_destroy(sum->music[M_MENU]);
    sfMusic_destroy(sum->music[M_IN_GAME]);
}
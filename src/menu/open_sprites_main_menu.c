/*
** EPITECH PROJECT, 2019
** open_sprites
** File description:
** open_sprites
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "menu_rpg.h"

char create_line_settings(menu_t *menu)
{
    sfVector2f pos = {.x = 1920 / 2 - 122, .y = 535};
    sfVector2f size = {.x = 0, .y = 8};

    menu->main.lines[SETTINGS].line = sfRectangleShape_create();
    if (!menu->main.lines[SETTINGS].line)
        return (FAILURE);
    sfRectangleShape_setFillColor(menu->main.lines[SETTINGS].line, sfRed);
    sfRectangleShape_setSize(menu->main.lines[SETTINGS].line, size);
    sfRectangleShape_setPosition(menu->main.lines[SETTINGS].line, pos);
    menu->main.lines[SETTINGS].time = -1;
    menu->main.lines[SETTINGS].time_back = -1;
    menu->main.lines[SETTINGS].max_line = 240;
    return (SUCCESS);
}

char create_sprites_menu(menu_t *menu)
{
    menu->main.back_spr = sfSprite_create();
    menu->main.play[BASE] = sfSprite_create();
    menu->main.play[MOUS] = sfSprite_create();
    menu->main.play[CLIC] = sfSprite_create();
    menu->m_pause.spr_pause = sfSprite_create();
    menu->main.set[BASE] = sfSprite_create();
    menu->main.set[MOUS] = sfSprite_create();
    menu->main.set[CLIC] = sfSprite_create();
    menu->main.quit[BASE] = sfSprite_create();
    menu->main.quit[CLIC] = sfSprite_create();
    menu->main.quit[MOUS] = sfSprite_create();
    menu->settings.back = sfSprite_create();
    if (!menu->main.back_spr || !menu->main.play[BASE] ||
        !menu->main.play[MOUS] || !menu->main.play[CLIC] ||
        !menu->m_pause.spr_pause || !menu->main.set[BASE] ||
        !menu->main.set[MOUS] || !menu->main.set[CLIC] ||
        !menu->main.quit[BASE] || !menu->main.quit[CLIC] ||
        !menu->main.quit[MOUS] || !menu->settings.back)
        return (FAILURE);
    return (SUCCESS);
}

char set_texture_t_sprites(menu_t *m)
{
    SpriteSetTexture(m->main.back_spr, m->main.background, sfTrue);
    SpriteSetTexture(m->main.play[BASE], m->main.tex_play[BASE], sfTrue);
    SpriteSetTexture(m->main.play[MOUS], m->main.tex_play[MOUS], sfTrue);
    SpriteSetTexture(m->main.play[CLIC], m->main.tex_play[CLIC], sfTrue);
    SpriteSetTexture(m->m_pause.spr_pause, m->m_pause.text_pause, sfTrue);
    SpriteSetTexture(m->main.set[BASE], m->main.tex_set[BASE], sfTrue);
    SpriteSetTexture(m->main.set[MOUS], m->main.tex_set[MOUS], sfTrue);
    SpriteSetTexture(m->main.set[CLIC], m->main.tex_set[CLIC], sfTrue);
    SpriteSetTexture(m->main.quit[BASE], m->main.tex_quit[BASE], sfTrue);
    SpriteSetTexture(m->main.quit[MOUS], m->main.tex_quit[MOUS], sfTrue);
    SpriteSetTexture(m->main.quit[CLIC], m->main.tex_quit[CLIC], sfTrue);
    SpriteSetTexture(m->settings.back, m->settings.tex_back, sfTrue);
    if (!m->main.back_spr || !m->main.play[BASE] || !m->main.play[MOUS] ||
        !m->main.play[CLIC] || !m->m_pause.spr_pause || !m->main.set[BASE] ||
        !m->main.set[MOUS] || !m->main.set[CLIC] || !m->main.quit[BASE] ||
        !m->main.quit[CLIC] || !m->main.quit[MOUS] || !m->settings.back)
        return (FAILURE);
    return (SUCCESS);
}

char open_sprites_menu(menu_t *menu)
{
    if (create_line_play(menu) == FAILURE ||
        create_line_quit(menu) == FAILURE ||
        create_line_settings(menu) == FAILURE ||
        create_line_back_menu(menu) == FAILURE)
        return (FAILURE);
    if (create_sprites_menu(menu) == FAILURE)
        return (FAILURE);
    if (set_texture_t_sprites(menu) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

char open_menu_sprites(summary_t *sum)
{
    sum->menu.settings.font_settings = sfFont_createFromFile(FONT_MENU);
    sum->music[M_MENU] = sfMusic_createFromFile(MENU_MUSIC);
    sum->music[M_IN_GAME] = sfMusic_createFromFile(OGG_IN_GAME);
    if (!sum->menu.settings.font_settings || !sum->music[M_MENU] ||
        !sum->music[M_IN_GAME])
        return (FAILURE);
    sfMusic_setLoop(sum->music[M_IN_GAME], sfTrue);
    sfMusic_setLoop(sum->music[M_MENU], sfTrue);
    sfMusic_play(sum->music[M_MENU]);
    if (open_textures_menu(&sum->menu) == FAILURE)
        return (FAILURE);
    if (open_sprites_menu(&sum->menu) == FAILURE)
        return (FAILURE);
    if (open_sprites_settings(&sum->menu) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
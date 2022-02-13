/*
** EPITECH PROJECT, 2019
** open_sprites_menu
** File description:
** open_sprites_menu
*/

#include "menu_rpg.h"

char open_textures_menu(menu_t *menu)
{
    menu->main.background = TextureFromFile(BACK_MAIN_MENU, NULL);
    menu->m_pause.text_pause = TextureFromFile(PAUSE_SCREEN, NULL);
    menu->main.tex_play[BASE] = TextureFromFile(PLAY_BASE, NULL);
    menu->main.tex_play[CLIC] = TextureFromFile(PLAY_CLICK, NULL);
    menu->main.tex_play[MOUS] = TextureFromFile(PLAY_MOUSE, NULL);
    menu->main.tex_set[BASE] = TextureFromFile(SET_BASE, NULL);
    menu->main.tex_set[CLIC] = TextureFromFile(SET_CLICK, NULL);
    menu->main.tex_set[MOUS] = TextureFromFile(SET_MOUSE, NULL);
    menu->main.tex_quit[BASE] = TextureFromFile(QIT_BASE, NULL);
    menu->main.tex_quit[CLIC] = TextureFromFile(QIT_CLICK, NULL);
    menu->main.tex_quit[MOUS] = TextureFromFile(QIT_MOUSE, NULL);
    menu->settings.tex_back = TextureFromFile(SETTINGS_SCREEN, NULL);
    if (!menu->main.background || !menu->main.tex_play[BASE] ||
        !menu->main.tex_play[MOUS] || !menu->main.tex_play[CLIC] ||
        !menu->m_pause.text_pause || !menu->main.tex_set[BASE] ||
        !menu->main.tex_set[CLIC] || !menu->main.tex_set[MOUS] ||
        !menu->main.tex_quit[BASE] || !menu->main.tex_quit[CLIC] ||
        !menu->main.tex_quit[MOUS] || !menu->settings.tex_back)
        return (FAILURE);
    return (SUCCESS);
}

char create_line_play(menu_t *menu)
{
    sfVector2f pos = {.x = 1920 / 2 - 110, .y = 400};
    sfVector2f size = {.x = 0, .y = 8};

    menu->main.lines[PLAY].line = sfRectangleShape_create();
    if (!menu->main.lines[PLAY].line)
        return (FAILURE);
    sfRectangleShape_setFillColor(menu->main.lines[PLAY].line, sfRed);
    sfRectangleShape_setSize(menu->main.lines[PLAY].line, size);
    sfRectangleShape_setPosition(menu->main.lines[PLAY].line, pos);
    menu->main.lines[PLAY].max_line = 220;
    menu->main.lines[PLAY].time = -1;
    menu->main.lines[PLAY].time_back = -1;
    return (SUCCESS);
}

char create_line_quit(menu_t *menu)
{
    sfVector2f pos = {.x = 1920 / 2 - 98, .y = 695};
    sfVector2f size = {.x = 0, .y = 8};

    menu->main.lines[QUIT].line = sfRectangleShape_create();
    if (!menu->main.lines[QUIT].line)
        return (FAILURE);
    sfRectangleShape_setFillColor(menu->main.lines[QUIT].line, sfRed);
    sfRectangleShape_setSize(menu->main.lines[QUIT].line, size);
    sfRectangleShape_setPosition(menu->main.lines[QUIT].line, pos);
    menu->main.lines[QUIT].max_line = 187;
    menu->main.lines[QUIT].time = -1;
    menu->main.lines[QUIT].time_back = -1;
    return (SUCCESS);
}

char create_line_back_menu(menu_t *menu)
{
    sfVector2f pos = {.x = 1920 / 2 - 98, .y = 943};
    sfVector2f size = {.x = 0, .y = 8};

    menu->main.lines[3].line = sfRectangleShape_create();
    if (!menu->main.lines[3].line)
        return (FAILURE);
    sfRectangleShape_setFillColor(menu->main.lines[3].line, sfRed);
    sfRectangleShape_setSize(menu->main.lines[3].line, size);
    sfRectangleShape_setPosition(menu->main.lines[3].line, pos);
    menu->main.lines[3].max_line = 187;
    menu->main.lines[3].time = -1;
    menu->main.lines[3].time_back = -1;
    return (SUCCESS);
}
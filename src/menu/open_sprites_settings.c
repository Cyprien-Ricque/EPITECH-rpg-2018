/*
** EPITECH PROJECT, 2019
** open_sprites_settings
** File description:
** open_sprites_settings
*/

#include "menu_rpg.h"

char open_textures_settings(menu_t *m)
{
    m->settings.tex_l[BLUE_AR] = TextureFromFile(BLUE_L_ARROW, NULL);
    m->settings.tex_l[GREEN_AR] = TextureFromFile(GREEN_L_ARROW, NULL);
    m->settings.tex_l[RED_AR] = TextureFromFile(RED_L_ARROW, NULL);
    m->settings.tex_r[BLUE_AR] = TextureFromFile(BLUE_R_ARROW, NULL);
    m->settings.tex_r[GREEN_AR] = TextureFromFile(GREEN_R_ARROW, NULL);
    m->settings.tex_r[RED_AR] = TextureFromFile(RED_R_ARROW, NULL);
    m->settings.tex_back_but[BASE] = TextureFromFile(BACK_BASE, NULL);
    m->settings.tex_back_but[MOUS] = TextureFromFile(BACK_MOUS, NULL);
    m->settings.tex_back_but[CLIC] = TextureFromFile(BACK_CLIC, NULL);
    m->m_pause.tex_main[BASE] = TextureFromFile(MAIN_BASE, NULL);
    m->m_pause.tex_main[MOUS] = TextureFromFile(MAIN_MOUS, NULL);
    m->m_pause.tex_main[CLIC] = TextureFromFile(MAIN_CLIC, NULL);
    for (int a = 0; a < 3; ++a) {
        if (!m->settings.tex_l[a] || !m->settings.tex_r[a] ||
            !m->settings.tex_back_but[a] || !m->m_pause.tex_main[a])
            return (FAILURE);
    }
    return (SUCCESS);
}

char set_texture_sprites_set(menu_t *m)
{
    for (int a = 0; a < 3; ++a) {
        m->settings.spr_l[a] = sfSprite_create();
        m->settings.spr_r[a] = sfSprite_create();
        m->settings.spr_back_but[a] = sfSprite_create();
        m->m_pause.spr_main[a] = sfSprite_create();
        if (!m->settings.spr_l[a] || !m->settings.spr_r[a] ||
            !m->settings.spr_back_but[a] || !m->m_pause.spr_main[a])
            return (FAILURE);
    }
    return (SUCCESS);
}

char open_sprites_set(menu_t *m)
{
    for (int a = 0; a < 3; ++a) {
        SpriteSetTexture(m->settings.spr_l[a], m->settings.tex_l[a], sfTrue);
        SpriteSetTexture(m->settings.spr_r[a], m->settings.tex_r[a], sfTrue);
        SpriteSetTexture(m->m_pause.spr_main[a], m->m_pause.tex_main[a],
            sfTrue);
        SpriteSetTexture(m->settings.spr_back_but[a],
            m->settings.tex_back_but[a], sfTrue);
        if (!m->settings.spr_l[a] || !m->settings.spr_r[a] ||
            !m->settings.spr_back_but[a] || !m->m_pause.spr_main[a])
            return (FAILURE);
    }
    return (SUCCESS);
}

char open_sprites_settings(menu_t *m)
{
    if (open_textures_settings(m) == FAILURE)
        return (FAILURE);
    if (set_texture_sprites_set(m) == FAILURE)
        return (FAILURE);
    if (open_sprites_set(m) == FAILURE)
        return (FAILURE);
    if (init_text_settings(&m->settings) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
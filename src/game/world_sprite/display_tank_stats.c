/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** world sprite
*/

#include "my_rpg.h"
#include "world.h"
#include "my.h"

sfVector2f higher(points_t *points)
{
    sfVector2f tmp = {0, 1080};

    for (int i = 0; i < 4; ++i) {
        if (points->front_2d[i].y < tmp.y)
            tmp = points->front_2d[i];
        if (points->back_2d[i].y < tmp.y)
            tmp = points->back_2d[i];
    }
    return (tmp);
}

void draw_text(summary_t *s, int j, int i)
{
    sfVector2f pos = {.x = higher(&s->map.cube.points).x - 25,
        .y = higher(&s->map.cube.points).y - 53};
    char *str = m_sdup("LIFE:\nATTACK: ", 0);

    str = m_scat(str, m_retbase(s->map.entity[j][i].perso->attack, 10),
        m_slen(str), 0);
    str = m_scat(str, "\nDEFENSE: ", m_slen(str), 0);
    str = m_scat(str, m_retbase(s->map.entity[j][i].perso->defense, 10),
        m_slen(str), 0);
    str = m_scat(str, "\nMOVES: ", m_slen(str), 0);
    str = m_scat(str, m_retbase(s->map.entity[j][i].perso->moves, 10),
        m_slen(str), 0);
    sfText_setPosition(s->tank_dt.text, pos);
    sfText_setString(s->tank_dt.text, str);
    sfRenderWindow_drawText(s->win.window, s->tank_dt.text, NULL);
}

void draw_stats(summary_t *s)
{
    sfVector2f pos = {.x = higher(&s->map.cube.points).x - 30,
        .y = higher(&s->map.cube.points).y - 55};

    sfRectangleShape_setPosition(s->tank_dt.stats, pos);
    sfRenderWindow_drawRectangleShape(s->win.window, s->tank_dt.stats, NULL);
}

void draw_life(summary_t *s, int j, int i)
{
    sfVector2f pos = {.x = higher(&s->map.cube.points).x,
        .y = higher(&s->map.cube.points).y - 47};
    sfVector2f size = {.x = s->map.entity[j][i].perso->life / 6.5, .y = 8};

    sfRectangleShape_setPosition(s->tank_dt.life, pos);
    sfRectangleShape_setSize(s->tank_dt.life, size);
    sfRenderWindow_drawRectangleShape(s->win.window, s->tank_dt.life, NULL);
}

void display_tank_stats(summary_t *s, int j, int i)
{
    draw_stats(s);
    draw_text(s, j, i);
    draw_life(s, j, i);
}
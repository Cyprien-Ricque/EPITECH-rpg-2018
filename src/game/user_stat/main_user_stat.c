/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** world sprite
*/

#include <my.h>
#include "my_rpg.h"
#include "world.h"

void print_exp(summary_t *s)
{
    sfVector2f size = {.x = 65, .y = 8};

    sfRectangleShape_setFillColor(s->usexp.usp.experience, sfBlack);
    sfRectangleShape_setOutlineThickness(s->usexp.usp.experience, 1);
    sfRectangleShape_setOutlineColor(s->usexp.usp.experience, sfBlack);
    sfRectangleShape_setSize(s->usexp.usp.experience, size);
    sfRenderWindow_drawRectangleShape(s->win.window, s->usexp.usp.experience,
        NULL);
    size.x = s->usexp.experience;
    sfRectangleShape_setFillColor(s->usexp.usp.experience, dark(sfBlue));
    sfRectangleShape_setOutlineThickness(s->usexp.usp.experience, 0);
    sfRectangleShape_setSize(s->usexp.usp.experience, size);
    sfRenderWindow_drawRectangleShape(s->win.window, s->usexp.usp.experience,
        NULL);
    s->usexp.open = TRUE;
}

void disp_user_exp(summary_t *s)
{
    char *str = m_sdup("Level: ", 0);

    str = m_scat(str, m_retbase(s->usexp.level, 10), m_slen(str), 0);
    str = m_scat(str, "\nExp: ", m_slen(str), 0);
    str = m_scat(str, "\nMoney: ", m_slen(str), 0);
    sfRenderWindow_drawRectangleShape(s->win.window, s->usexp.usp.stats, NULL);
    sfRenderWindow_drawCircleShape(s->win.window, s->usexp.usp.lvl, NULL);
    sfRenderWindow_drawRectangleShape(s->win.window, s->usexp.usp.pp, NULL);
    sfText_setString(s->usexp.usp.statst,
        m_scat(str, m_retbase(s->usexp.money, 10), m_slen(str), 0));
    sfRenderWindow_drawText(s->win.window, s->usexp.usp.statst, NULL);
    print_exp(s);
}

char user_stat(summary_t *s)
{
    if (s->usexp.experience >= 65) {
        ++s->usexp.level;
        s->usexp.experience = 0;
    }
    if (sqrt(square(s->win.mouse.x - 35) + square(s->win.mouse.y - 35)) < 30 ||
        (s->usexp.open == TRUE && s->win.mouse.x < 140 + 30 &&
            s->win.mouse.x > 30 && s->win.mouse.y < 60 + 30 &&
            s->win.mouse.y > 30)) {
        disp_user_exp(s);
    } else {
        s->usexp.open = FALSE;
        sfRenderWindow_drawCircleShape(s->win.window, s->usexp.usp.lvl, NULL);
        sfRenderWindow_drawRectangleShape(s->win.window, s->usexp.usp.pp,
            NULL);
    }
    return (SUCCESS);
}
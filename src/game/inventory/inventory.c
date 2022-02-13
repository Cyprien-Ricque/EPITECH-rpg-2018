/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

#include "my_rpg.h"
#include "my.h"

char disp_inv_win(inv_t *inv, summary_t *s)
{
    sfRenderWindow_drawRectangleShape(s->win.window, inv->inv, NULL);
    return (SUCCESS);
}

char disp_inv_text(inv_t *inv, summary_t *s)
{
    char *str = m_sdup("BASIC: ", 0);
    sfVector2f pos = {.x = 1920 / 2 - 400 / 2 + 30, .y = 1080 / 2 - 300 / 2};

    sfText_setString(inv->text,
        m_scat(str, m_retbase(inv->tanks_nb[0], 10), m_slen(str), 0));
    sfText_setPosition(inv->text, pos);
    sfRenderWindow_drawText(s->win.window, inv->text, NULL);
    str = m_sdup("FAST: ", 0);
    sfText_setString(inv->text,
        m_scat(str, m_retbase(inv->tanks_nb[1], 10), m_slen(str), 0));
    pos.x += 145;
    sfText_setPosition(inv->text, pos);
    sfRenderWindow_drawText(s->win.window, inv->text, NULL);
    str = m_sdup("STRONG: ", 0);
    sfText_setString(inv->text,
        m_scat(str, m_retbase(inv->tanks_nb[2], 10), m_slen(str), 0));
    pos.x += 135;
    sfText_setPosition(inv->text, pos);
    sfRenderWindow_drawText(s->win.window, inv->text, NULL);
    return (SUCCESS);
}

char disp_inventory_tanks(summary_t *summary)
{
    for (int i = 0; i < 9; i += 3)
        sfRenderWindow_drawRectangleShape(summary->win.window,
            summary->shop.tanks[i], NULL);
    return (SUCCESS);
}

char disp_inventory_back(summary_t *s)
{
    sfRenderWindow_drawSprite(s->win.window, s->inv.spr_inv, NULL);
    return (SUCCESS);
}

char inventory(summary_t *summary)
{
    if (disp_inventory_back(summary) == FAILURE ||
        disp_inv_win(&summary->inv, summary) == FAILURE ||
        disp_inv_text(&summary->inv, summary) == FAILURE ||
        disp_inventory_tanks(summary))
        return (FAILURE);
    for (int i = 0; i < 9; i += 3)
        new_tank_from_inv(summary, i);
    return (SUCCESS);
}
/*
** EPITECH PROJECT, 2019
** shop_2
** File description:
** shop_2
*/

#include "my_rpg.h"
#include "my.h"

char disp_shop_win(shop_t *shop, summary_t *s)
{
    sfRenderWindow_drawRectangleShape(s->win.window, shop->shop, NULL);
    return (SUCCESS);
}

void disp_shop_text_2(shop_t *shop, summary_t *s, sfVector2f *pos, char *str)
{
    str = m_sdup("STRONG: ", 0);
    str = m_scat(str, m_retbase(shop->tanks_price[2], 10), m_slen(str), 0);
    sfText_setString(shop->text, m_scat(str, "e", m_slen(str), 0));
    (*pos).x += 125;
    sfText_setPosition(shop->text, (*pos));
    sfRenderWindow_drawText(s->win.window, shop->text, NULL);
}

char disp_shop_text(shop_t *shop, summary_t *s)
{
    sfVector2f pos = {.x = 1920 / 2 - 410 / 2 + 30, .y = 1080 / 2 - 300 / 2};
    char *str = m_sdup("BASIC: ", 0);

    str = m_scat(str, m_retbase(shop->tanks_price[0], 10), m_slen(str), 0);
    sfText_setString(shop->text, m_scat(str, "e", m_slen(str), 0));
    sfText_setPosition(shop->text, pos);
    sfRenderWindow_drawText(s->win.window, shop->text, NULL);
    str = m_sdup("FAST: ", 0);
    str = m_scat(str, m_retbase(shop->tanks_price[1], 10), m_slen(str), 0);
    sfText_setString(shop->text, m_scat(str, "e", m_slen(str), 0));
    pos.x += 145;
    sfText_setPosition(shop->text, pos);
    sfRenderWindow_drawText(s->win.window, shop->text, NULL);
    disp_shop_text_2(shop, s, &pos, str);
    return (SUCCESS);
}

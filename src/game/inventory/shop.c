/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Shop
*/

#include "my_rpg.h"
#include "my.h"

int mouse_in_rectangle(summary_t *s, sfRectangleShape *rs)
{
    if (s->win.mouse.x >= sfRectangleShape_getPosition(rs).x &&
        s->win.mouse.x <= sfRectangleShape_getPosition(rs).x +
            sfRectangleShape_getSize(rs).x &&
        s->win.mouse.y >= sfRectangleShape_getPosition(rs).y &&
        s->win.mouse.y <= sfRectangleShape_getPosition(rs).y +
            sfRectangleShape_getSize(rs).y)
        return (TRUE);
    return (FALSE);
}

int sprites_tank_shop(summary_t *s, int i)
{
    if ((s->usexp.level < 2 && i > 2) ||
        ((unsigned int)s->shop.tanks_price[i / 3] > s->usexp.money))
        return (i + 2);
    if ((s->usexp.level < 4 && i > 5))
        return (i + 2);
    if (mouse_in_rectangle(s, s->shop.tanks[i]) == TRUE &&
        s->win.mouse.z == FALSE && s->win.prev_mouse.z == TRUE) {
        ++s->inv.tanks_nb[i / 3];
        s->shop.new_tank = i / 3;
        s->usexp.money -= s->shop.tanks_price[i / 3];
        new_scene(s, 9);
    }
    if (mouse_in_rectangle(s, s->shop.tanks[i]) == TRUE &&
        s->win.mouse.z == TRUE)
        return (i + 1);
    return (i);
}

char disp_shape_tanks(summary_t *summary)
{
    for (int i = 0; i < 9; i += 3)
        sfRenderWindow_drawRectangleShape(summary->win.window,
            summary->shop.tanks[sprites_tank_shop(summary, i)], NULL);
    return (SUCCESS);
}

char disp_shop_back(shop_t *shop, summary_t *s)
{
    sfRenderWindow_drawSprite(s->win.window, shop->spr_shop, NULL);
    return (SUCCESS);
}

char disp_shop(summary_t *summary)
{
    summary->shop.new_time = -1;
    if (disp_shop_back(&summary->shop, summary) == FAILURE ||
        disp_shop_win(&summary->shop, summary) == FAILURE ||
        disp_shop_text(&summary->shop, summary) == FAILURE ||
        disp_shape_tanks(summary))
        return (FAILURE);
    return (SUCCESS);
}
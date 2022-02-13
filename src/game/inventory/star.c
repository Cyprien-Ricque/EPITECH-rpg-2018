/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** star
*/

#include "my_rpg.h"
#include "my.h"
#include "world.h"

void disp_stars(summary_t *s)
{
    sfVector2f tmp_size =
    sfRectangleShape_getSize(s->shop.tanks[s->shop.new_tank * 3]);
    sfVector2f tmp_pos =
    sfRectangleShape_getPosition(s->shop.tanks[s->shop.new_tank * 3]);
    sfVector2f size = {300, 240};
    sfVector2f pos = {1920 / 2 - size.x / 2, 1080 / 2 - size.y};

    sfRenderWindow_drawSprite(s->win.window, s->shop.back, NULL);
    sfRectangleShape_setPosition(s->shop.tanks[s->shop.new_tank * 3], pos);
    sfRectangleShape_setSize(s->shop.tanks[s->shop.new_tank * 3], size);
    sfRenderWindow_drawRectangleShape(s->win.window,
        s->shop.tanks[s->shop.new_tank * 3], NULL);
    sfRectangleShape_setPosition(s->shop.tanks[s->shop.new_tank * 3], tmp_pos);
    sfRectangleShape_setSize(s->shop.tanks[s->shop.new_tank * 3], tmp_size);
    sfRenderWindow_drawRectangleShape(s->win.window,
        s->shop.stars[(int)((s->mtime->seconds - s->shop.new_time) / 1.11) % 2],
        NULL);
}

char new_tank(summary_t *s)
{
    if (s->shop.new_time == -1) {
        remove_scene(s, 8);
        s->shop.new_time = s->mtime->seconds;
    }
    disp_stars(s);
    if (s->mtime->seconds - s->shop.new_time > 5) {
        remove_scene(s, 9);
        new_scene(s, 8);
    }
    return (SUCCESS);
}
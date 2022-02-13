/*
** EPITECH PROJECT, 2019
** loading_screen
** File description:
** loading_screen
*/

#include "my_rpg.h"
#include "menu_rpg.h"

char loading_screen(summary_t *sum)
{
    sum->loading.load = sfTexture_createFromFile(LOAD_SCREEN, NULL);
    sum->loading.sprite = sfSprite_create();
    sum->loading.shape = sfRectangleShape_create();
    sum->loading.position = 1;
    if (sum->loading.load == NULL || sum->loading.sprite == NULL ||
        sum->loading.shape == NULL)
        return (FAILURE);
    sfSprite_setTexture(sum->loading.sprite, sum->loading.load, sfTrue);
    sfRenderWindow_drawSprite(sum->win.window, sum->loading.sprite, NULL);
    sfRenderWindow_display(sum->win.window);
    sfRectangleShape_setSize(sum->loading.shape,
        (sfVector2f){(float)(1034.0 / (LEN_INIT - 1) - 4), 55});
    sfRectangleShape_setFillColor(sum->loading.shape, sfWhite);
    return (SUCCESS);
}
/*
** EPITECH PROJECT, 2019
** menu_quit
** File description:
** menu_quit
*/

#include "my_rpg.h"
#include "menu_rpg.h"

char menu_quit(summary_t *sum)
{
    sfRenderWindow_close(sum->win.window);
    return (SUCCESS);
}
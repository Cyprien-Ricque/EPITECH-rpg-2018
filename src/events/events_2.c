/*
** EPITECH PROJECT, 2019
** events_2
** File description:
** events_2
*/

#include "my_rpg.h"
#include "my.h"

void shop_events(summary_t *sum)
{
    if (sum->win.event.type == sfEvtKeyPressed &&
        sum->win.event.key.code == sfKeyS) {
        remove_scene(sum, 8);
        sum->win.event.key.code = sfKeyF1;
    }
}

void inv_events(UNUSED summary_t *sum)
{
    if (sum->win.event.type == sfEvtKeyPressed &&
        sum->win.event.key.code == sfKeyE) {
        remove_scene(sum, 7);
        sum->win.event.key.code = sfKeyF1;
    }
}

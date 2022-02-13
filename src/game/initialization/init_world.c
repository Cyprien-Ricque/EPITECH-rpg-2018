/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init world
*/

#include "my_rpg.h"

char init_world(summary_t *summary)
{
    if (parser(summary) == FAILURE)
        return (FAILURE);
    summary->map = *summary->rpg_wd->maps[0];
    if (main_init(summary) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
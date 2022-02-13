/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init time
*/

#include "my_rpg.h"

char init_time(summary_t *summary)
{
    srand(time(NULL));
    summary->mtime = malloc(sizeof(mtime_t));
    summary->mtime->clock = sfClock_create();
    if (!summary->mtime->clock)
        return (FAILURE);
    return (SUCCESS);
}
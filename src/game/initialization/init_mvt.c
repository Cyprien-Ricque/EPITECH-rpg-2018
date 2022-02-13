/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Created by charles,
*/

#include "my_rpg.h"

char init_mvt(summary_t *summary)
{
    summary->map.entity_mvt.movement = NULL;
    summary->map.entity_mvt.status = USER_TURN;
    return (SUCCESS);
}
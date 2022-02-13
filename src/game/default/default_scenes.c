/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

char default_scenes(summary_t *summary)
{
    summary->scene_number[0] = 0;
    summary->scene_number[1] = -1;
    summary->menu.m_pause.active = sfFalse;
    return (SUCCESS);
}
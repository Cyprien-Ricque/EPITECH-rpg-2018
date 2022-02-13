/*
** EPITECH PROJECT, 2019
** display
** File description:
** display_organization
*/

#include "my_rpg.h"

char main_game(summary_t *sum)
{
    if (main_init(sum) == FAILURE)
        return (FAILURE);
    display_world(sum);
    return (SUCCESS);
}
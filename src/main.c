/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main_file
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

int main(int ac, char **av UNUSED)
{
    if (ac != 1)
        return (FAILURE);
    if (rpg() == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include <my.h>
#include "my_rpg.h"

void default_parsing(summary_t *s)
{
    s->tmp_p.size = 0;
    s->tmp_p.size_x = 0;
    s->tmp_p.size_y = 0;
    s->tmp_p.size_z = 0;
    s->tmp_p.water = '0';
    s->tmp_p.flat = '1';
    s->tmp_p.mountain = '2';
    s->tmp_p.basic = '0';
    s->tmp_p.fast = '1';
    s->tmp_p.strong = '2';
    s->tmp_p.red = 'r';
    s->tmp_p.blue = 'b';
}

char init_parsing(summary_t *s)
{
    s->rpg_wd = malloc(sizeof(rpg_wd_t));
    if (!s->rpg_wd)
        return (FAILURE);
    s->rpg_wd->maps = NULL;
    s->rpg_wd->units = NULL;
    default_parsing(s);
    return (SUCCESS);
}
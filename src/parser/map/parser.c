/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char parser(summary_t *s)
{
    if (!s)
        return (FAILURE);
    init_parsing(s);
    if (parse_units(s) == FAILURE) {
        m_puts("error: Parsing error\n", 2);
        return (FAILURE);
    }
    default_parsing(s);
    if (parse_map(s) == FAILURE) {
        m_puts("error: Parsing error\n", 2);
        return (FAILURE);
    }
    if (complete_units_data(s->rpg_wd) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
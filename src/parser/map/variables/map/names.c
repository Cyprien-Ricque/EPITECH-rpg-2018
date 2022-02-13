/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

char names(summary_t *s, char *str, UNUSED char *statement, char *save)
{
    if (m_slen(str) < 7)
        return (error(save));
    s->tmp_p.names = m_sdup(&(str[6]), 0);
    return (SUCCESS);
}
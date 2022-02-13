/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "my_rpg.h"
#include "my.h"

const char *all_values[] =
{
    "size", "water", "flat", "mountain", "basic", "fast", "strong",
    "red", "blue", "size_x", "size_y", "size_z", "attack",
    "life", "moves", ":", "names", "front_left", "front_right", "back_right",
    "back_left", "shop", "defense", NULL
};

char (*value[])(summary_t *s, char *str, char *statement, char *save) =
{
    size, water_p, flat_p, mountain_p, basic_p, fast_p, strong_p,
    red_p, blue_p, size_x_p, size_y_p, size_z_p, attack_p,
    life_p, moves_p, map_p, names, front_left, front_right, back_right,
    back_left, shop, defense_p, NULL
};

char error(char *str)
{
    m_puts("Invalid line : ", 2);
    m_puts(str, 2);
    m_puts("\n", 2);
    return (FAILURE);
}

char new_class(UNUSED summary_t *s, char *str, char *statement, char *error)
{
    if (end(str, error, statement) == FAILURE)
        return (FAILURE);
    if (new_c(str, error, statement) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

char new_value(summary_t *s, char *str, char *statement, char *error)
{
    for (int i = 0; str[i]; ++i)
        if (str[i] == ':' && i > 0 && (str[i - 1] == ' '
        || str[i - 1] == '\t'))
            move(str, i);
    for (int i = 0; all_values[i]; ++i) {
        if (!m_scmp(all_values[i], str, ':'))
            return (value[i](s, str, statement, error));
    }
    return (SUCCESS);
}

char comment(UNUSED summary_t *s, UNUSED char *str, UNUSED char *statement,
    UNUSED char *error)
{
    return (SUCCESS);
}
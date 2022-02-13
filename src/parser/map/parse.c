/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include <fcntl.h>
#include "my_rpg.h"
#include "world.h"
#include "my.h"

char (*new_data[4])(summary_t *s, char *str, char *statement, char *error) =
{
    new_class, new_value, comment, NULL
};

char main_parse(summary_t *s, char *save, char *statement)
{
    char *str = m_cleans(save, false);
    char what_is_this_line = line(str, save);

    if (what_is_this_line == 84)
        return (FAILURE);
    return (new_data[(int)what_is_this_line](s, str, statement, save));
}

char parse_map(summary_t *s)
{
    int fd = open(MAP_FILE, O_RDONLY);
    char *str;
    char *statement = m_sdup("0123456789", 0);

    statement[0] = FILE_MAP;
    statement[1] = 0;
    if (fd == -1) {
        m_puts("error: Unable to open file\n\n", 2);
        return (FAILURE);
    }
    do {
        str = m_sdup(gnl(fd), '/');
        if (!str)
            return (SUCCESS);
    } while (main_parse(s, str, statement) != FAILURE);
    m_puts("error: Map parsing stopped\n", 2);
    return (FAILURE);
}

char parse_units(summary_t *s)
{
    int fd = open(UNITS_FILE, O_RDONLY);
    char *str;
    char *statement = m_sdup("0123456789", 0);

    statement[0] = FILE_UNITS;
    statement[1] = 0;
    if (fd == -1) {
        m_puts("error: Unable to open units file\n", 2);
        return (FAILURE);
    }
    do {
        str = m_sdup(gnl(fd), '/');
        if (!str)
            return (SUCCESS);
    } while (main_parse(s, str, statement) != FAILURE);
    m_puts("error: Units parsing stopped\n", 2);
    return (FAILURE);
}
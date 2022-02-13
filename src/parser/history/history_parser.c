/*
** EPITECH PROJECT, 2019
** history_parser
** File description:
** history_parser
*/

#include <fcntl.h>
#include "my.h"
#include "my_rpg.h"

char setup_array_history(summary_t *s, int position, int fd[3])
{
    short counter = 0;
    char *str;
    char **new;

    s->history_content.history[position] = malloc(sizeof(char *) * 2);
    s->history_content.history[position][0] = NULL;
    while ((str = gnl(fd[position]))) {
        s->history_content.history[position][counter] = str;
        s->history_content.history[position][++counter] = NULL;
        new = malloc(sizeof(char *) * (counter + 3));
        for (int a = 0; s->history_content.history[position][a] != NULL; ++a) {
            new[a] = s->history_content.history[position][a];
            new[a + 1] = NULL;
        }
        free(s->history_content.history[position]);
        s->history_content.history[position] = new;
    }
    if (counter == 0)
        return (FAILURE);
    return (SUCCESS);
}

char history_parser(summary_t *s)
{
    int fd[3];

    s->history_content.position = 0;
    fd[0] = open("history/history_1", O_RDONLY);
    fd[1] = open("history/history_2", O_RDONLY);
    fd[2] = open("history/history_3", O_RDONLY);
    if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0) {
        m_puts("Missing at least one history file\n", 2);
        return (FAILURE);
    }
    for (int a = 0; a < 3; ++a) {
        if (setup_array_history(s, a, fd) == FAILURE)
            return (FAILURE);
    }
    return (SUCCESS);
}

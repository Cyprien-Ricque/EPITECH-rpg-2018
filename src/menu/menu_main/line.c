/*
** EPITECH PROJECT, 2019
** play_button
** File description:
** play_button
*/

#include "my_rpg.h"
#include "menu_rpg.h"
#include <math.h>

sfVector2f back_line(summary_t *s, int status, line_t *line, sfVector2f size)
{
    float x;

    if (status == 0 && line->time_back == -1) {
        line->time = -1;
        line->time_back = s->mtime->seconds;
    }
    if (status == 0) {
        line->time = -1;
        x = s->mtime->seconds - line->time_back;
        (size).x -= x * 6;
    }
    if ((size).x < 0)
        (size).x = 0;
    return (size);
}

void disp_line(summary_t *s, int status, line_t *line)
{
    sfVector2f size = sfRectangleShape_getSize(line->line);
    float x;

    if ((status == 1 || status == 2) && line->time == -1) {
        line->time_back = -1;
        line->time = s->mtime->seconds;
    }
    if ((status == 1 || status == 2)) {
        line->time_back = -1;
        x = s->mtime->seconds - line->time;
        if (sin(x + 0.00001) >= sin(x))
            size.x = (float)(sin(x) * (line->max_line * 1.05));
    }
    size = back_line(s, status, line, size);
    if (size.x > line->max_line)
        size.x = line->max_line;
    sfRectangleShape_setSize(line->line, size);
    sfRenderWindow_drawRectangleShape(s->win.window, line->line, NULL);
}
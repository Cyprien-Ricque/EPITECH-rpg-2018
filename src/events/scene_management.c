/*
** EPITECH PROJECT, 2019
** events
** File description:
** events
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>
#include "my.h"

void move_scene(short *scenes, int pos)
{
    for (int i = pos; scenes[i] != -1; ++i)
        scenes[i] = scenes[i + 1];
}

void remove_scene(summary_t *s, short scene)
{
    for (int i = 0; s->scene_number[i] != -1; ++i) {
        if (s->scene_number[i] == scene)
            move_scene(s->scene_number, i);
    }
}

void new_scene(summary_t *s, short scene)
{
    int len;

    for (len = 0; s->scene_number[len] != -1; ++len);
    s->scene_number[len] = scene;
    s->scene_number[len + 1] = -1;
}

char scene(summary_t *s, int scene)
{
    for (int i = 0; s->scene_number[i] != -1; ++i) {
        if (s->scene_number[i] == scene)
            return (TRUE);
    }
    return (FALSE);
}
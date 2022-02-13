/*
** EPITECH PROJECT, 2019
** events
** File description:
** events
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"
#include "my.h"

void world_event_1(summary_t *sum)
{
    if ((sum->win.event.type == sfEvtKeyPressed &&
        sum->win.event.key.code == sfKeyP) ||
        (sum->win.event.mouseWheel.type == sfEvtMouseWheelScrolled &&
        sum->win.event.mouseWheel.x > 0))
        sum->map.st.zoom += 2;
    if (((sum->win.event.type == sfEvtKeyPressed &&
        sum->win.event.key.code == sfKeyM) ||
        (sum->win.event.mouseWheel.type == sfEvtMouseWheelScrolled &&
        sum->win.event.mouseWheel.x < 0)) && sum->map.st.zoom > 2)
        sum->map.st.zoom -= 2;
    if (sum->win.event.type == sfEvtKeyPressed &&
        sum->win.event.key.code == sfKeyRight)
        sum->map.st.angle.x -= 10;
}

void world_event_2(summary_t *sum)
{
    if (sum->win.event.type == sfEvtKeyPressed &&
        sum->win.event.key.code == sfKeyLeft) {
        sum->map.st.angle.x += 10;
    }
    if (sum->win.event.type == sfEvtKeyPressed &&
        sum->win.event.key.code == sfKeyE &&
        sum->map.entity_mvt.movement == NULL) {
        new_scene(sum, 7);
        sum->win.event.key.code = sfKeyF1;
    }
    if (sum->win.event.type == sfEvtKeyPressed &&
        sum->win.event.key.code == sfKeyS &&
        sum->map.entity_mvt.movement == NULL) {
        new_scene(sum, 8);
        sum->win.event.key.code = sfKeyF1;
    }
    move_map(sum);
}

void world_events(summary_t *sum)
{
    world_event_1(sum);
    world_event_2(sum);
}

void start_scene(summary_t *sum)
{
    if (scene(sum, 7) == FALSE && scene(sum, 8) == TRUE &&
        scene(sum, 4) == FALSE)
        shop_events(sum);
    if (scene(sum, 3) == TRUE && scene(sum, 7) == FALSE &&
        scene(sum, 4) == FALSE && scene(sum, 8) == FALSE &&
        scene(sum, 9) == FALSE)
        world_events(sum);
    if (scene(sum, 4) == FALSE && scene(sum, 7) == TRUE &&
        scene(sum, 8) == FALSE)
        inv_events(sum);
    if (scene(sum, 10) == TRUE && scene(sum, 4) == FALSE)
        history_events(sum);
    if ((scene(sum, 11) == TRUE || (scene(sum, 12) == TRUE))
        && scene(sum, 4) == FALSE)
        game_over_or_victory_events(sum);
}

void events(summary_t *sum)
{
    sum->win.size = sfRenderWindow_getSize(sum->win.window);
    mouse(&sum->win);
    while (sfRenderWindow_pollEvent(sum->win.window, &sum->win.event)) {
        if (sum->win.event.type == sfEvtClosed)
            sfRenderWindow_close(sum->win.window);
        start_pause(sum);
        start_scene(sum);
        if (sum->win.event.type == sfEvtKeyPressed &&
            sum->win.event.key.code == sfKeyC &&
            sum->map.entity_mvt.movement != NULL &&
            sum->map.entity_mvt.status != USER_MOVE &&
            sum->map.entity_mvt.status != AI_MOVE) {
            free(sum->map.entity_mvt.movement);
            sum->map.entity_mvt.movement = NULL;
        } else if (sum->win.event.type == sfEvtKeyPressed &&
            sum->win.event.key.code == sfKeyQ && sum->scene_number[0] == 12 &&
            sum->scene_number[1] == -1) {
            sfRenderWindow_close(sum->win.window);
        }
    }
}
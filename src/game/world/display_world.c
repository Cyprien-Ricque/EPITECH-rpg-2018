/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

void get_pos(summary_t *s)
{
    s->map.mouse = get_pos_tiles(&s->map, &s->win);
    if (s->map.mouse.x == -1 || s->map.mouse.z == -1 || s->map.mouse.y == -1)
        s->map.mouse = get_pos_corner(&s->map, &s->win);
}

char shop_disp(summary_t *s)
{
    if (s->map.mouse.x != -1 && s->map.mouse.y != -1 &&
        s->map.entity[(int)s->map.mouse.y][(int)s->map.mouse.x].perso &&
        s->map.entity[(int)s->map.mouse.y][(int)s->map.mouse.x].perso->type ==
            SHOP && s->win.mouse.z == TRUE &&
        s->map.entity_mvt.movement == NULL) {
        new_scene(s, 8);
    }
    return (SUCCESS);
}

void check_dead(summary_t *s)
{
    for (int i = 0; i < s->map.st.size.y; i++) {
        for (int y = 0; y < s->map.st.size.x; y++) {
            if (s->map.entity[i][y].perso
                && s->map.entity[i][y].perso->type != SHOP &&
                s->map.entity[i][y].perso->life <= 0) {
                free(s->map.entity[i][y].perso);
                s->map.entity[i][y].perso = NULL;
            }
        }
    }
}

void display_world(summary_t *s)
{
    double a_time;

    create_3d_map(&s->map);
    create_2d_map(&s->map);
    replace_points(&s->map);
    set_water(s);
    get_pos(s);
    display_cube(s);
    turn_management(s);
    a_time = s->mtime->time.microseconds / 1000000.0 - s->turn.o_time;
    if (scene(s, 4) == FALSE && scene(s, 7) == FALSE && scene(s, 8) == FALSE &&
        scene(s, 9) == FALSE && scene(s, 10) == FALSE && a_time > 3.0) {
        game_back(s, (int)s->win.mouse.z, s->mtime);
        check_dead(s);
        shop_disp(s);
        if (next_map(s) == SUCCESS) {
            s->scene_number[0] = 12;
            s->scene_number[1] = -1;
        }
    }
}
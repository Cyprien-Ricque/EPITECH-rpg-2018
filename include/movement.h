/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Created by charles,
*/
#ifndef MUL_MY_RPG_2018_MOVEMENT_H
#define MUL_MY_RPG_2018_MOVEMENT_H

#include "my_rpg.h"

#define TOP 3
#define RIGHT 2
#define BOT 1
#define LEFT 0


int  reduce_gap_x_direction(sfVector2f *gap, map_t *map, int *pos,
    int direction
);
void get_path(map_t *map, int nb_mvt);
int get_gap(int, int);
int entity_movement(map_t *);
int get_next_direction(sfVector3f mouse, sfVector3f movement);
int get_direction_incrementation(int direction);
int is_obstacle(map_t *map, sfVector3f mouse, sfVector3f entity, mvt_t mvt);
char go_to2(map_t *, sfVector2f, int, int);
int user_move(map_t *, int);
void move_tank(summary_t *, mtime_t *);
void assignement_ai(map_t *map, int, int, int);
char good_path(map_t *map);
int fight_calcul(summary_t *s);
void tank_assignement(summary_t *s, float actual_time);
void set_figth2(summary_t *s, float UNUSED actual_time);
void set_figth1(summary_t *s, float UNUSED actual_time);
sfVector2f xy_assignement(sfVector2f *pos, int y, int x);
void life_after_fitgh(summary_t *s, sfVector2f *atk_pos, sfVector2f *def_pos,
    perso_t *save);
sfVector2f xy_assignement2(sfVector2f *pos, int y, int x);

#endif //MUL_MY_RPG_2018_MOVEMENT_H

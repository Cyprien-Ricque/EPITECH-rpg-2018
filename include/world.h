/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** world
*/

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/System.h>
#include <stdio.h>
#include "time.h"
#include <math.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Event.h>
#include "lib.h"
#include "my_rpg.h"
#include <stdbool.h>

/** Define **/

#define CLICK 1
#define N_CLICK 0
/** entity **/
#define ENTITY_NB 3

//TANKS
#define TANK_NB 4

#define TANK_INV_G "assets/tanks/green/tank_front_right_blue_green.png"
#define TANK_INV_Y "assets/tanks/yellow/tank_front_right_blue_yellow.png"
#define TANK_INV_P "assets/tanks/pink/tank_front_right_blue_pink.png"

#define STARS {"assets/stars.png", "assets/stars2.png"}

#define TANK_SHOP {TANK_INV_P, "assets/tanks/pink/pink_out.png",  \
"assets/tanks/pink/pink_sepia.png", TANK_INV_G, \
"assets/tanks/green/green_out.png", \
"assets/tanks/green/green_sepia.png", TANK_INV_Y, \
"assets/tanks/yellow/yellow_out.png", \
"assets/tanks/yellow/yellow_sepia.png"};

#define TANK_BLUE_Y {"assets/tanks/yellow/tank_front_left_blue_yellow.png", \
                  TANK_INV_Y, \
                  "assets/tanks/yellow/tank_back_right_blue_yellow.png", \
                  "assets/tanks/yellow/tank_back_left_blue_yellow.png"}
#define TANK_RED_Y {"assets/tanks/yellow/tank_front_left_red_yellow.png", \
                   "assets/tanks/yellow/tank_front_right_red_yellow.png", \
                   "assets/tanks/yellow/tank_back_right_red_yellow.png", \
                   "assets/tanks/yellow/tank_back_left_red_yellow.png"}

#define TANK_BLUE_G {"assets/tanks/green/tank_front_left_blue_green.png", \
                  TANK_INV_G, \
                  "assets/tanks/green/tank_back_right_blue_green.png", \
                  "assets/tanks/green/tank_back_left_blue_green.png"}
#define TANK_RED_G {"assets/tanks/green/tank_front_left_red_green.png", \
                   "assets/tanks/green/tank_front_right_red_green.png", \
                   "assets/tanks/green/tank_back_right_red_green.png", \
                   "assets/tanks/green/tank_back_left_red_green.png"}

#define TANK_BLUE_P {"assets/tanks/pink/tank_front_left_blue_pink.png", \
                  TANK_INV_P, \
                  "assets/tanks/pink/tank_back_right_blue_pink.png", \
                  "assets/tanks/pink/tank_back_left_blue_pink.png"}
#define TANK_RED_P {"assets/tanks/pink/tank_front_left_red_pink.png", \
                   "assets/tanks/pink/tank_front_right_red_pink.png", \
                   "assets/tanks/pink/tank_back_right_red_pink.png", \
                   "assets/tanks/pink/tank_back_left_red_pink.png"}

/** floor **/

#define GRASS_NB 6
//FLOOR
#define S_GRASS {"assets/floor/grass/grass3.png", \
                 "assets/floor/grass/grass4.png", \
                 "assets/floor/grass/grass5.png", \
                 "assets/floor/grass/grass6.png", \
                 "assets/floor/grass/grass5_light.png", \
                 "assets/floor/grass/grass4_dark.png"};
#define S_SNOW "assets/floor/snow"
#define S_SAND "assets/floor/sand"
#define S_DIRT "assets/floor/dirt.png"
#define S_BUSH "assets/floor/bush.png"
#define S_WATER "assets/floor/water.png"

#define USER_TURN 0
#define USER_MOVE 1
#define AI_TURN 2
#define AI_MOVE 3

/** Structures declaration **/

typedef struct points {
    sfVector3f *front_3d;
    sfVector3f *back_3d;
    sfVector2f *front_2d;
    sfVector2f *back_2d;
} points_t;

typedef struct cube_design {
    sfTexture **texture;        // faces textures
    sfColor *color;             // faces color
    sfColor *color_out;         // faces outline color
    int *thickness;             // thickness outline
} c_design;

typedef struct shapes {
    sfConvexShape *tank_blue[3][TANK_NB];
    sfConvexShape *tank_red[3][TANK_NB];
    sfConvexShape *shape_grass[GRASS_NB];
    sfConvexShape *shape_snow;
    sfConvexShape *shape_sand;
    sfConvexShape *shape_dirt;
    sfConvexShape *shape_bush;
    sfConvexShape *shop[4];
    sfConvexShape *shape_water;
} shape_t;

typedef struct cube {
    bool init;
    c_design c_des;             //design
    shape_t shapes;
    sfVertexArray *array;       //??
    sfVector3f position;        //cube position
    points_t points;            //don't touch
} cube_t;

typedef struct sfVector3i_s {
    int x;
    int y;
    int z;
} sfVector3i;

typedef struct map_data {
    bool init;
    float **water_mov;
    float **water_fix;
    float **save_map;
    char ***pntr_map;
    sfVector2f ***map_2d;
    sfVector3f ***map_3d;
} map_dt;

typedef struct map_state {
    float zoom;
    sfVector2f pos;
    sfVector3i size;
    sfVector2f angle;
} m_state;

typedef struct entity_movement {
    sfVector3f mouse;
    sfVector3f entity;
    sfVector3f *movement;
    char status;
    float save_time;
} mvt_t;

typedef struct map {
    float **map;    //truc with z data for each point beetween 0 and size.z
    map_dt dt;
    m_state st;
    cube_t cube;
    struct entity_object **entity;
    sfVector3f mouse;
    mvt_t entity_mvt;
    char name;
    char next;
} map_t;

typedef struct mode {
    char edit_mode;
    sfVector2i size;
    char move_mode;
} m_mode_t;

/** Function declaration **/

//INIT
char init_map(map_t *);
char init_water(map_t *);
char init_cubes(map_t *);
char create_map(map_t *);
void set_map_default(map_t *);
void random_map(map_t *map);
//DISPLAY
void create_3d_map(map_t *map);
void create_2d_map(map_t *map);
//LOGISTIC
int find_k(map_t *map, int j, int i);
void replace_points(map_t *map);
void draw_line(sfRenderWindow *window, sfVector2f point1, sfVector2f point2,
    sfVertexArray *array);
void draw_line_b(sfRenderWindow *window, sfVector2f point1, sfVector2f point2,
    sfVertexArray *array);
float square(float nb);
int check_point(sfVector2f *point, int x, int y);
sfVector2f find_left(sfVector2f a, sfVector2f b, sfVector2f c, sfVector2f d);
sfVector2f find_right(sfVector2f a, sfVector2f b, sfVector2f c, sfVector2f d);
sfVector2f find_top(sfVector2f a, sfVector2f b, sfVector2f c, sfVector2f d);
sfVector2f find_bottom(sfVector2f a, sfVector2f b, sfVector2f c, sfVector2f d);
sfVector2f find_origin(points_t *);

#endif //WORLD_H

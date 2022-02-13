/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#ifndef MY_RPG_MY_RPG_H
#define MY_RPG_MY_RPG_H

#include <SFML/Window/Types.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/Export.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window/Event.h>
#include <stdbool.h>
#include "lib.h"
#include "world.h"

#define UNUSED __attribute__ ((unused))

//Nb init functions
#define LEN_INIT 15
//Nb max scenes
#define MAX_SCENES 10

/*
 *
 * scene_number in summary is the number of the scene :
 *
 * 0 : menu_main
 * 1 : main_settings
 * 2 : menu_quit
 * 3 : main_game (world)
 * 4 : menu_pause
 * 5 : fight_scenes
 * 6 : user_stat
 * 7 : inventory
 * 8 : disp_shop
 * 9 : new_tank
 * 10 : history_scene
 * 11 : game_over
 * 12 : victory
 * 13 : rain particules
 *
 */

//Nb RAIN
#define NB_RAIN 100

/* Macros definition for music */

#define NB_MUSIC 5
#define OGG_RADIO "music/radio.ogg"
#define M_RADIO 0
#define OGG_GUN_FIRE "music/gun_fire.ogg"
#define M_GUN_FIRE 1
#define OGG_EXPLOSION "music/explosion.ogg"
#define M_EXPLOSION 2
#define M_MENU 3
#define OGG_IN_GAME "assets/music_in_game.ogg"
#define M_IN_GAME 4

/* Macros definition assets location */

#define R_BUBBLE "assets/history/r_txt_box.png"
#define L_BUBBLE "assets/history/l_txt_box.png"
#define CHARACTERS "assets/history/characters.png"
#define H_STREET "assets/history/history_1.png"
#define H_PALACE "assets/history/history_2.png"
#define H_DOCK "assets/history/history_3.png"
#define L_BLUE_TANK "assets/l_blue_tank.png"
#define R_RED_TANK "assets/r_red_tank.png"
#define L_FOREST "assets/left_forest.png"
#define R_FOREST "assets/right_forest.png"
#define L_BEACH "assets/left_beach.png"
#define R_BEACH "assets/right_beach.png"
#define L_STREET "assets/left_street.png"
#define R_STREET "assets/right_street.png"
#define DIVISION "assets/division.png"
#define EXPLOSION "assets/explosion.png"
#define PP "assets/tanks/base/pp.png"
#define RAIN "assets/particule_water.png"

/* Macros definition assets fight texture */

#define TT_DIVISION 0
#define TT_R_FOREST 1
#define TT_L_FOREST 2
#define TT_R_BEACH 3
#define TT_L_BEACH 4
#define TT_R_STREET 5
#define TT_L_STREET 6
#define TT_R_RED_TANK 7
#define TT_L_BLUE_TANK 8
#define TT_EXPLOSION 9

/* Macros definition assets fight sprite */

#define SPR_DIVISION 0
#define SPR_R_FOREST 1
#define SPR_L_FOREST 2
#define SPR_R_BEACH 3
#define SPR_L_BEACH 4
#define SPR_R_STREET 5
#define SPR_L_STREET 6
#define SPR_R_RED_TANK 7
#define SPR_L_BLUE_TANK 8
#define SPR_EXPLOSION 9

/* line macros */

#define SETTINGS 1
#define PLAY 0
#define QUIT 2

/* Macros definition assets history sprite */

#define SPR_R_BUBBLE 0
#define SPR_L_BUBBLE 1
#define SPR_CHARACTERS 2
#define SPR_H_STREET 3
#define SPR_H_PALACE 4
#define SPR_H_DOCK 5

/* Macros definition assets history texture */

#define TT_R_BUBBLE 0
#define TT_L_BUBBLE 1
#define TT_CHARACTERS 2
#define TT_H_STREET 3
#define TT_H_PALACE 4
#define TT_H_DOCK 5

/* Macros definition for shop and inventory assets */

#define PATH_SHOP "assets/shop_spr.png"
#define PATH_INV "assets/inventory_spr.png"

/* Macros definition for shop and inventory assets */

#define GAME_OVER "assets/game_over.png"
#define VICTORY "assets/victory.png"

/* Macros definition opponents assets sprites verification */

#define ERROR_OPPONENT_SPRITE !fight_spr->sprite.spr[SPR_L_BLUE_TANK]\
|| !fight_spr->sprite.spr[SPR_R_RED_TANK]

#define ERROR_FIGHT_SCENES_SPRITE !fight_spr->sprite.spr[SPR_L_FOREST] ||\
!fight_spr->sprite.spr[SPR_R_FOREST] || !fight_spr->sprite.spr[SPR_L_BEACH]\
|| !fight_spr->sprite.spr[SPR_R_BEACH] ||\
!fight_spr->sprite.spr[SPR_L_STREET] || !fight_spr->sprite.spr[SPR_R_STREET]\
|| !fight_spr->sprite.spr[SPR_DIVISION] || !fight_spr->sprite.spr[SPR_EXPLOSION]

/* Macros definition opponnets assets textures verification */

#define ERROR_OPPONENT_TEXTURE !fight_spr->texture.tt[TT_L_BLUE_TANK]\
|| !fight_spr->texture.tt[TT_R_RED_TANK]

#define ERROR_FIGHT_SCENES_TEXTURE !fight_spr->texture.tt[TT_L_FOREST] ||\
!fight_spr->texture.tt[TT_R_FOREST] || !fight_spr->texture.tt[TT_L_BEACH]||\
!fight_spr->texture.tt[TT_R_BEACH] || !fight_spr->texture.tt[TT_L_STREET] ||\
!fight_spr->texture.tt[TT_R_STREET] || !fight_spr->texture.tt[TT_DIVISION] ||\
!fight_spr->texture.tt[TT_EXPLOSION]

/* Macros definition assets number for opponents and fight scenes */

#define NB_OPPONENTS_AND_FIGHT_SCENES 10
#define NB_HISTORY_ASSET 6

/* Macros definition for user, ennemy and place*/

#define USER 0
#define ENNEMY 1
#define FOREST 0
#define STREET 1
#define BEACH 2

//TANKS
#define TFRB "assets/tanks/tank_front_right_blue.png"
#define TFLB "assets/tanks/tank_front_left_blue.png"
#define TFLR "assets/tanks/tank_front_left_red.png"
#define TFRR "assets/tanks/tank_front_right_red.png"
#define TBRB "assets/tanks/tank_back_right_blue.png"
#define TBLB "assets/tanks/tank_back_left_blue.png"
#define TBLR "assets/tanks/tank_back_left_red.png"
#define TBRR "assets/tanks/tank_back_right_red.png"

/* Macros for shorter functions */

#define ButtonLPressed sfMouse_isButtonPressed(sfMouseLeft)
#define MouseGetPos sfMouse_getPositionRenderWindow
#define DrawSprite sfRenderWindow_drawSprite
#define TextureFromFile sfTexture_createFromFile
#define SpriteSetPosition sfSprite_setPosition
#define SpriteSetTexture sfSprite_setTexture
#define DrawText sfRenderWindow_drawText
#define DrawRectangleShape sfRenderWindow_drawRectangleShape
/* Macros parsing declaration */

#define VALUE (s->mtime->seconds - s->rain.old_time) * 10

#define MAP_FILE "maps/map1/map"
#define UNITS_FILE "maps/map1/units"

#define BLUE 0
#define RED 1
#define WATER 0
#define FLAT 1
#define MOUNTAIN 2
#define LINK 3

//CLASSES
/**Please don't define printable char as classes. it s reserved for map name
  Don't change these values !! (you'll break the parser)**/
#define FILE_MAP (-1)
#define FILE_UNITS (-2)
#define LEGEND (-3)
#define LANDSCAPE (-4)
#define UNITS (-5)
#define TEAM (-6)
#define MAPS (-7)
#define SIZE (-8)
#define DATA (-9)
#define SOLDIER (-10)
#define TANK (-11)
#define HELICOPTER (-12)
#define ROTATION (-13)

#define SHOP (-13)

#define FRONT_LEFT 0
#define FRONT_RIGHT 1
#define BACK_RIGHT 2
#define BACK_LEFT 3

/** Structures declaration **/

#define DOMINIQUE (s->map.entity[j][i].type == MOUNTAIN &&  \
    !(j < s->map.st.size.y - 1 &&   \
    s->map.entity[j + 1][i].type == MOUNTAIN) &&    \
    (i < s->map.st.size.x - 1 &&    \
    s->map.entity[j][i + 1].type == MOUNTAIN)) ||   \
    ((i < s->map.st.size.x - 1 &&   \
    s->map.entity[j][i + 1].type == MOUNTAIN) &&    \
    (j < s->map.st.size.y - 1 &&    \
    s->map.entity[j + 1][i + 1].type != MOUNTAIN))

typedef struct history_struct {
    char **history[3];
    char position;
} history_content_t;

typedef struct parse_tmp {
    int size;
    int size_x;
    int size_y;
    int size_z;
    char water;
    char flat;
    char mountain;
    char basic;
    char fast;
    char strong;
    char shop;
    char red;
    char blue;
    char *names;
    char front_left;
    char front_right;
    char back_left;
    char back_right;
} tmp_pt;

typedef struct mtime {
    sfClock *clock;
    sfTime time;
    sfTime timepause;
    sfTime previous_pause;
    sfTime actual_pause;
    float seconds;
} mtime_t;

typedef struct fight_texture {
    sfTexture *tt[NB_OPPONENTS_AND_FIGHT_SCENES];
} fight_tt_t;

typedef struct ita_sprite {
    sfSprite *spr[NB_OPPONENTS_AND_FIGHT_SCENES];
} ita_spr_t;

typedef struct sprites_fight {
    fight_tt_t texture;
    ita_spr_t sprite;
} fight_spr_t;

typedef struct pause_menu {
    sfTexture *text_pause;
    sfSprite *spr_pause;
    sfBool active;
    sfTexture *tex_main[3];
    sfSprite *spr_main[3];
    sfBool previous_back;
} pause_menu_t;

typedef struct line {
    sfRectangleShape *line;
    int max_line;
    float time;
    float time_back;
} line_t;

typedef struct main_menu {
    line_t lines[4];
    //Data button play
    sfTexture *tex_play[3];
    sfSprite *play[3];
    //Data button settings
    sfTexture *tex_set[3];
    sfSprite *set[3];
    //Data button quit
    sfTexture *tex_quit[3];
    sfSprite *quit[3];
    int time_quit;
    //Data background picture
    sfTexture *background;
    sfSprite *back_spr;
    sfBool previous_settings;
    sfBool previous_play;
    sfBool previous_quit;
} main_menu_t;

typedef struct settings {
    char old_status;
    //Current status settings
    sfBool vertical_sync;
    sfBool sound_active;
    sfBool fullscreen;
    unsigned char fps;

    //Sprites and textures
    sfTexture *tex_back;
    sfSprite *back;
    sfTexture *tex_l[3];
    sfSprite *spr_l[3];
    sfTexture *tex_r[3];
    sfSprite *spr_r[3];

    //Text settings
    sfText *music_text[2];
    sfText *v_sync_text[2];
    sfText *fl_screen[2];
    sfText *fps_text[3];
    sfFont *font_settings;

    //Sprites and textures for back button
    sfTexture *tex_back_but[3];
    sfSprite *spr_back_but[3];
} settings_t;

typedef struct menu_struct {
    main_menu_t main;
    pause_menu_t m_pause;
    settings_t settings;
} menu_t;

typedef struct perso {
    char type;
    int moves;
    int attack;
    int defense;
    int life;
    char team;
    char rotation;
    float percent;
} perso_t;

typedef struct entity_object {
    char type;
    perso_t *perso;
} entity_t;

typedef struct info_fight {
    char save_e_l;
    char save_u_l;
    float flash;
    bool b_flash;
    bool get_time;
    float o_time;
    bool l_tank_fire;
    bool r_tank_fire;
    float a_time;
    int rect_offset_x[2];
    int rect_offset_y[2];
    int exp_offset;
    sfVector2f l_pos[5];
    sfVector2f r_pos[5];
} i_fight_t;

typedef struct fight {
    bool turn;
    char type[2];
    char background[2];
    char life[2];
    char life_after_fight[2];
} fight_t;

typedef struct window {
    sfRenderWindow *window;
    sfVector3f mouse;
    sfVector3f prev_mouse;
    sfEvent event;
    sfVector2u size;
    sfVector2f ratio;
    sfMouseButton button;
} window_t;

typedef struct rpg_world_data {
    map_t **maps;
    perso_t **units;
} rpg_wd_t;

typedef struct user_sprites {
    sfRectangleShape *pp;
    sfCircleShape *lvl;
    sfText *statst;
    sfRectangleShape *stats;
    sfRectangleShape *experience;
    sfRectangleShape *money;
} user_sprites_t;

typedef struct user_exp {
    unsigned int money;
    unsigned int experience;
    unsigned int level;
    char *name;
    user_sprites_t usp;
    char open;
} user_exp_t;

typedef struct tanks_stat_disp {
    sfRectangleShape *stats;
    sfRectangleShape *life;
    sfText *text;
} tanks_sb;

typedef struct inventory {
    sfSprite *spr_inv;
    sfTexture *tt_inv;
    sfRectangleShape *inv;
    sfText *text;
    sfSprite *tanks[3];
    int tanks_nb[3];
} inv_t;

typedef struct shop {
    sfSprite *spr_shop;
    sfTexture *tt_shop;
    sfRectangleShape *shop;
    sfText *text;
    sfRectangleShape *tanks[9];
    int tanks_price[3];
    sfRectangleShape *stars[2];
    float new_time;
    int new_tank;
    sfSprite *back;
} shop_t;

typedef struct loading_screen {
    char position;
    sfTexture *load;
    sfSprite *sprite;
    sfRectangleShape *shape;
} loading_t;

typedef struct history_text {
    int step;
    int i;
    sfText *h_txt;
    sfSprite *h_spr[NB_HISTORY_ASSET];
    sfTexture *h_tt[NB_HISTORY_ASSET];
} history_t;

typedef struct enf_of_game_s {
    sfSprite *game_over_spr;
    sfTexture *game_over_tt;
    sfSprite *victory_spr;
    sfTexture *victory_tt;
} end_of_game_t;

typedef struct rain {
    sfTexture *tex;
    sfSprite *spr;
    sfVector2f position[NB_RAIN];
    sfBool in_pos[NB_RAIN];
    float old_time;
} rain_t;

typedef struct turn_s {
    sfText *turn_text;
    bool ia_turn;
    bool laucn_ia;
    bool f_call;
    float o_time;
} turn_t;

typedef struct summary {
    turn_t turn;
    end_of_game_t eog;
    sfMusic *music[NB_MUSIC];
    sfBool music_status[NB_MUSIC];
    window_t win;
    map_t map;
    user_exp_t usexp;
    inv_t inv;
    shop_t shop;
    tanks_sb tank_dt;
    fight_spr_t fight_spr;
    fight_t fight;   //Structure à envoyer dans la fonction de Paul
    i_fight_t i_fight;
    menu_t menu;               //Structure contenant les informations du menu
    short scene_number[MAX_SCENES];
    short old_scene_nb[MAX_SCENES];
    short old_scene_settings[MAX_SCENES];
    rpg_wd_t *rpg_wd;
    tmp_pt tmp_p;
    mtime_t *mtime;
    loading_t loading;
    history_t history;
    history_content_t history_content;
    rain_t rain;
} summary_t;

/** Function declaration **/

char rpg(void);
char default_scenes(summary_t *);
char init_time(summary_t *);
char init_world(summary_t *);
char init_menu(summary_t *);
char main_game(summary_t *);
void start_pause(summary_t *);
char init_user_exp(summary_t *);
char user_stat(summary_t *);
void disp_line(summary_t *, int, line_t *);
char init_time(summary_t *);
char init_world(summary_t *);
char init_inventory(summary_t *);
char inventory(summary_t *);
char scene(summary_t *, int);
void move_scene(short *, int);
void remove_scene(summary_t *, short);
void new_scene(summary_t *, short);
char scene(summary_t *, int);
char init_shop(summary_t *);
char disp_shop(summary_t *);
char init_stars(summary_t *s);
char new_tank(summary_t *s);
int mouse_in_rectangle(summary_t *s, sfRectangleShape *rs);
void new_tank_from_inv(summary_t *s, int i);
//Window function
char create_window(summary_t *);
//Events functions
void events(summary_t *);
//Loading screen
char loading_screen(summary_t *);
//Open sprites
char open_menu_sprites(summary_t *);
//Init game function
char main_init(summary_t *);
//DISPLAY WORLD
void display_world(summary_t *);
void set_water(summary_t *s);
void create_water_points(summary_t *, int, int, sfVector2i);
//destroy_ressources functions
void destroy_useless_texture(summary_t *);
char create_sprite_sand(cube_t *cube);
char create_sprite_snow(cube_t *cube);
char create_sprite_bush(cube_t *cube);
char create_sprite_dirt(cube_t *cube);
//WORLD
sfVector2f project_iso_point(sfVector3f, float, float, map_t *);
void move_map(summary_t *);
void display_cube(summary_t *);
void cube_assignation(summary_t *, int, int, int);
char cube_exist(summary_t *, int, int, int);
void edit_cube(summary_t *, int, int, int);
void water(summary_t *, int, int);
void draw_cube(summary_t *, int, int, int );
char three_check(summary_t *, int, int);
sfVector3f get_pos_corner(map_t *map, window_t *win);
//FACES
void top_1(summary_t *, int, int, int);
void top_2(summary_t *, int, int, int);
void bottom(summary_t *, int, int, int);
void front(summary_t *, int, int, int);
void top(summary_t *, int, int, int);
void right(summary_t *, int, int, int);
void back(summary_t *, int, int, int);
void left(summary_t *, int, int, int);
void mouse(window_t *);
//PARSER
void class_assignement(char c, entity_t *obj, int pos, tmp_pt *tmp);
char team_assignement(char *c, entity_t *obj, int pos, tmp_pt *tmp);
char rotation_assignement(char *c, entity_t *obj, int pos, tmp_pt *tmp);
char line(char *, char *);
char error(char *);
char new_class(summary_t *, char *, char *, char *);
char new_value(summary_t *, char *, char *, char *);
char comment(summary_t *, char *, char *, char *);
char end(char *, char *, char *);
char new_c(char *, char *, char *);
char size_x_p(summary_t *, char *, char *, char *);
char size_y_p(summary_t *, char *, char *, char *);
char size_z_p(summary_t *, char *, char *, char *);
char size(summary_t *, char *, char *, char *);
char water_p(summary_t *, char *, char *, char *);
char flat_p(summary_t *, char *, char *, char *);
char mountain_p(summary_t *, char *, char *, char *);
char basic_p(summary_t *s, char *str, char *statement, char *save);
char fast_p(summary_t *s, char *str, char *statement, char *save);
char shop(summary_t *s, char *str, char *statement, char *save);
char strong_p(summary_t *s, char *str, char *statement, char *save);
char attack_p(summary_t *, char *, char *, char *);
char life_p(summary_t *, char *, char *, char *);
char moves_p(summary_t *, char *, char *, char *);
char map_p(summary_t *, char *, char *, char *);
char red_p(summary_t *, char *, char *, char *);
char blue_p(summary_t *, char *, char *, char *);
char init_parsing(summary_t *);
char parse_map(summary_t *);
char set_all_maps_null(map_t **, int);
char init_map_p(summary_t *, char *);
char init_actual_map_p(summary_t *, int, char *);
char create_map_units(map_t *, char *, tmp_pt *);
char create_map_landscape(map_t *, char *, tmp_pt *);
int find_pos(summary_t *, char *);
char init_units(summary_t *, char *);
char parser(summary_t *);
char defense_p(summary_t *s, char *str, char *statement, char *save);
char names(summary_t *, char *, char *, char *);
char is_name(char, tmp_pt *);
void default_values(map_t *);
char complete_units_data(rpg_wd_t *);
char back_left(summary_t *s, char *str, char *statement, char *save);
char back_right(summary_t *s, char *str, char *statement, char *save);
char front_right(summary_t *s, char *str, char *statement, char *save);
char front_left(summary_t *s, char *str, char *statement, char *save);
//SPRITES
char open_fight_scenes_sprites(summary_t *);
char open_fight_opponents_sprites(summary_t *);
char parse_units(summary_t *);
char create_shape_tank(cube_t *);
char create_sprite_floor(cube_t *);
void cube_points_tank(summary_t *, int, int, int);
void points_2d(map_t *map);
void cube_points_shop(summary_t *s, int k, int j, int i);
char create_shape_shop(cube_t *cube);
void cube_points_bush(summary_t *s, int k, int j, int i);
void draw_entity(summary_t *s, int k, int j, int i);
char init_tanks_stat(summary_t *summary);
void display_tank_stats(summary_t *s, int j, int i);
//COLOR
sfColor light_grey_b(void);
sfColor dark(sfColor color);
sfColor water_c(void);
sfVector3f get_pos_tiles(map_t *, window_t *);
int entity_movement(map_t *);
int get_gap(int , int);
char fight_scenes(summary_t *);
int game_back(summary_t *s, int clicked, mtime_t *t);
char init_mvt(summary_t *summary);
void get_direction(map_t *map, int *direction_prior);
void display_fight_sprite(summary_t *sum);
void display_background(summary_t *sum);
void set_tank_position_street(summary_t *sum);
void set_tank_position_beach(summary_t *sum);
void tank_management(summary_t *sum);
void flash_management(summary_t *sum, float t_fire);
void dif_var_modification(summary_t *sum, float t_fire);
void init_rect(summary_t *sum, int l_x, int r_x);
int dif_offset_exp(float t_fire);
int dif_offset_tank(float t_fire);
void draw_shape_entity_base(summary_t *, sfVector2f *, sfConvexShape *);
void draw_shape_entity_right(summary_t *, sfVector2f *, sfConvexShape *);
void draw_shape_entity_left(summary_t *, sfVector2f *, sfConvexShape *);
void draw_shape_entity_back(summary_t *, sfVector2f *, sfConvexShape *);
void draw_shape_entity(summary_t *, sfVector2f *, sfConvexShape *);
int rotation(int, float);
char init_pp(user_sprites_t *);
char init_stats(user_sprites_t *);
sfConvexShape *top_color2(summary_t *, int, int, int);
void water_display_left(summary_t *, int, int, int);
char is_moutain(entity_t **en, int j, int i, sfVector3i size);
char is_water(entity_t **en, int j, int i, sfVector3i size);
char open_history_assets(summary_t *sum);
char history_scene(summary_t *sum);
char open_eof(summary_t *sum);
void history_events(summary_t *sum);
int m_getnb(const char *str);
char game_over(summary_t *sum);
char victory(summary_t *sum);
void game_over_or_victory_events(summary_t *sum);
int start_fight(fight_t start, fight_t end);
char disp_shop_win(shop_t *, summary_t *);
char disp_shop_text(shop_t *, summary_t *);
void shop_events(summary_t *);
void inv_events(summary_t *);
int m_slen(const char *str);
char create_textures_fight_opponents(fight_spr_t *);
char create_sprites_fight_opponents(fight_spr_t *);
void display_bubble(const summary_t *, int);
int next_map(summary_t *);
void pass_to_history(summary_t *);
int get_path_pos(mvt_t);
char rain_init(summary_t *);
void turn_management(summary_t *sum);
char rain(summary_t *);
void fill_fight_struct(summary_t *s, sfVector2f atk_pos,
    sfVector2f def_pos);
char getl(entity_t **entity, sfVector2f atk_pos, sfVector2f def_pos, char team
);
char get_back(entity_t **entity, sfVector2f atk_pos, sfVector2f def_pos,
    char team);
char get_unit_type(entity_t **entity, sfVector2f atk_pos, sfVector2f def_pos,
    char team);
void default_parsing(summary_t *s);
void points_2d(map_t *map);
sfConvexShape *top_color1(summary_t *s, UNUSED int k, int j, int i);

#endif //MY_RPG_MY_RPG_H

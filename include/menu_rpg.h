/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#ifndef MUL_MY_RPG_2018_MENU_RPG_H
#define MUL_MY_RPG_2018_MENU_RPG_H

#include "my_rpg.h"

// Menu macros definition

#define FONT_MENU "assets/font_menu.ttf"
//Backscreen
#define BACK_MAIN_MENU "assets/back.png"
#define LOAD_SCREEN "assets/loading_screen.png"
#define PAUSE_SCREEN "assets/pause.png"
#define SETTINGS_SCREEN "assets/back_settings.png"
//Play button
#define PLAY_BASE "assets/play_button_base.png"
#define PLAY_CLICK "assets/play_button_clicked.png"
#define PLAY_MOUSE "assets/play_button_pos_mouse.png"
//Settings button
#define SET_BASE  "assets/settings_button_base.png"
#define SET_CLICK "assets/settings_button_clicked.png"
#define SET_MOUSE "assets/settings_button_pos_mouse.png"
//Quit button
#define QIT_BASE "assets/quit_button_base.png"
#define QIT_CLICK "assets/quit_button_clicked.png"
#define QIT_MOUSE "assets/quit_button_pos_mouse.png"
//Left arrow
#define BLUE_L_ARROW "assets/arrows/left_blue_arrow.png"
#define GREEN_L_ARROW "assets/arrows/left_green_arrow.png"
#define RED_L_ARROW "assets/arrows/left_red_arrow.png"
//Right arrow
#define BLUE_R_ARROW "assets/arrows/right_blue_arrow.png"
#define GREEN_R_ARROW "assets/arrows/right_green_arrow.png"
#define RED_R_ARROW "assets/arrows/right_red_arrow.png"
//Back to main menu button
#define BACK_BASE "assets/back_button_base.png"
#define BACK_CLIC "assets/back_button_click.png"
#define BACK_MOUS "assets/back_button_mouse.png"

#define MAIN_BASE "assets/back_button_base.png"
#define MAIN_MOUS "assets/back_button_click.png"
#define MAIN_CLIC "assets/back_button_mouse.png"
//Music path
#define MENU_MUSIC "assets/music_menus.ogg"


// End menu macros definition

// Macros tab sprites
#define BASE 0
#define MOUS 1
#define CLIC 2

#define BLUE_AR 0
#define GREEN_AR 1
#define RED_AR 2
// End macros tab sprites

/* Buttons positions */

//Play button
#define PLAY_X_MIN (830)
#define PLAY_X_MAX (PLAY_X_MIN + 260)
#define PLAY_Y_MIN (300)
#define PLAY_Y_MAX (PLAY_Y_MIN + 122)
#define C_PLAY_BUT ((sfVector2f){PLAY_X_MIN, PLAY_Y_MIN})
#define PLAY_X_EQU pos[0] - 1
#define PLAY_Y_EQU pos[1] - 20

//Back button
#define BACK_X_MIN (830)
#define BACK_X_MAX (BACK_X_MIN + 260)
#define BACK_Y_MIN (800)
#define BACK_Y_MAX (BACK_Y_MIN + 122)
#define C_BACK_BUT ((sfVector2f){BACK_X_MIN, BACK_Y_MIN})
#define BACK_X_EQU pos[0] - 1
#define BACK_Y_EQU pos[1] - 20

//Settings button
#define SET_X_MIN (830)
#define SET_X_MAX (SET_X_MIN + 260)
#define SET_Y_MIN (450)
#define SET_Y_MAX (SET_Y_MIN + 122)
#define C_SET_BUT ((sfVector2f){SET_X_MIN, SET_Y_MIN})
#define SET_X_EQU pos[0] - 1
#define SET_Y_EQU pos[1] - 30

//Quit the game
#define QIT_X_MIN (830)
#define QIT_X_MAX (QIT_X_MIN + 260)
#define QIT_Y_MIN (600)
#define QIT_Y_MAX (QIT_Y_MIN + 122)
#define C_QIT_BUT ((sfVector2f){QIT_X_MIN, QIT_Y_MIN})
#define QIT_X_EQU pos[0] - 1
#define QIT_Y_EQU pos[1] - 40

//Back to main_menu
#define BCK_X_MIN (830)
#define BCK_X_MAX (BCK_X_MIN + 260)
#define BCK_Y_MIN (850)
#define BCK_Y_MAX (BCK_Y_MIN + 122)
#define C_BCK_BUT ((sfVector2f){BCK_X_MIN, BCK_Y_MIN})
#define BCK_X_EQU pos[0] - 1
#define BCK_Y_EQU pos[1] - 40

//Position of arrows in the settings menu
#define L1_AR (sfVector2f){1000, 300}
#define L2_AR (sfVector2f){1000, 430}
#define L3_AR (sfVector2f){1000, 560}
#define L4_AR (sfVector2f){1000, 690}
#define R1_AR (sfVector2f){1500, 300}
#define R2_AR (sfVector2f){1500, 430}
#define R3_AR (sfVector2f){1500, 560}
#define R4_AR (sfVector2f){1500, 690}

/* End buttons positions */

//Init sprites
char open_sprites_settings(menu_t *);
char create_line_quit(menu_t *);
char create_line_play(menu_t *);
char open_textures_menu(menu_t *);
//Menu functions
char main_scenes(summary_t *);
char menu_main(summary_t *);
char menu_quit(summary_t *);
char menu_settings(summary_t *);
char menu_pause(summary_t *);
//Menu buttons functions
void play_button(int const *, summary_t *);
void play_button_pause(int const *, summary_t *);
void settings_button(int const *, summary_t *);
void setup_scene_pause(summary_t *);
void quit_button(int const *, summary_t *);
void back_main_button(int const *, summary_t *);
//Calc positons mouse
int calc_y_position(window_t, int);
int calc_x_position(window_t, int);
//Menu settings
void display_content_settings(summary_t *);
char init_text_settings(settings_t *);
void display_r_arrow(summary_t *, int, sfVector2f);
void display_l_arrow(summary_t *, int, sfVector2f);
void setup_the_arrows(summary_t *, char);
void setup_button_back(summary_t *, int const [2]);
//Change settings
void chg_full_screen(summary_t *, char);
void chg_v_sync(summary_t *, char);
void chg_framerate(summary_t *, char);
void chg_sound(summary_t *, char);
//Line init
char create_line_back_menu(menu_t *);
//Pause the musics
void set_pause_music(summary_t *);
void restart_pause_music(summary_t *);

#endif //MUL_MY_RPG_2018_MENU_RPG_H

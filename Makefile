##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	gcc

I_DIR	=	-I include/ -I lib/my/include

CFLAGS	+=	$(I_DIR)
CFLAGS	+=	-W -Wall -Wextra

LDFLAGS	+=	$(LIB_MY) $(LIB_CSFML) $(LIB_MATHS)

LIB_CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

LIB_MATHS	=	-lm

LIB_MY	=	-L./lib/my -lmy

NAME	=	my_rpg

SRC	=		src/main.o	\
			src/parser/map/init_p.o	\
			src/parser/map/parse.o	\
			src/parser/map/variables/map/names.o	\
			src/parser/map/parser.o	\
			src/parser/map/analyse/classes.o	\
			src/parser/map/analyse/line.o	\
			src/parser/map/analyse/new_data.o	\
			src/parser/map/variables/map/assignement_entity.o	\
			src/parser/map/variables/map/assignement_type.o	\
			src/parser/map/variables/map/assignement_map.o	\
			src/parser/map/variables/map/init_new_map.o	\
			src/parser/map/variables/map/landscape.o	\
			src/parser/map/variables/map/map.o	\
			src/parser/map/variables/map/team.o	\
			src/parser/map/variables/map/units.o	\
			src/parser/map/variables/units/init_units.o	\
			src/parser/map/variables/units/stat.o	\
			src/back/xy_assignement.o	\
			src/parser/map/variables/size.o	\
			src/parser/map/variables/map/rotation.o	\
			src/parser/map/complete_units_data.o	\
			src/parser/history/history_parser.o	\
			src/window/create_window.o	\
			src/game/world_sprite/cube_tank2.o	\
			src/events/events.o	\
			src/events/events_2.o	\
			src/menu/menu_main/menu_main.o	\
			src/menu/menu_quit/menu_quit.o	\
			src/menu/menu_main/line.o	\
			src/scenes/scenes.o	\
			src/events/scene_management.o	\
			src/game/game_organization/main_game.o	\
			src/game/initialization/main_init.o	\
			src/game/initialization/init_map.o	\
			src/game/initialization/init_cube.o	\
			src/game/initialization/create_map.o	\
			src/game/initialization/init_stars.o	\
			src/game/initialization/init_user_exp_2.o	\
			src/game/world/display_world.o	\
			src/game/world/create_map/map_2d.o	\
			src/game/world/create_map/map_3d.o	\
			src/game/world/logistic/replace_points.o	\
			src/game/world/logistic/find_k.o	\
			src/game/world/logistic/evolution.o	\
			src/game/world/logistic/mouse_pos/get_mouse_pos.o	\
			src/game/world/logistic/mouse_pos/higher.o	\
			src/game/world/logistic/mouse_pos/point_in_square.o	\
			src/game/world/create_map/create_water.o	\
			src/game/world/water.o	\
			src/game/world/move.o	\
			src/game/world/cube/display_cube.o	\
			src/game/world/displaying.o	\
			src/game/world/displaying_2.o	\
			src/game/world/displaying_3.o	\
			src/game/world/colors/colors_3.o	\
			src/game/world/colors/colors_2.o	\
			src/game/world/cube/cube_checkout.o	\
			src/game/world/cube/cube.o	\
			src/game/world/cube/cube_faces.o	\
			src/game/world/cube/cube_faces_2.o	\
			src/game/world/line.o	\
			src/game/world_sprite/floor.o	\
			src/game/world_sprite/perso.o	\
			src/game/world_sprite/cube_shop.o	\
			src/game/inventory/star.o	\
			src/game/inventory/inventory.o	\
			src/events/mouse.o	\
			src/game/world_sprite/cube_tank.o	\
			src/game/world_sprite/shop.o	\
			src/game/world_sprite/cube_bush.o	\
			src/game/default/default_map.o	\
			src/game/default/default_scenes.o	\
			src/menu/menu_settings/menu_settings.o	\
			src/menu/open_sprites_main_menu.o	\
			src/destroy_ressources/destroy_ressources.o	\
			src/menu/loading_screen/loading_screen.o	\
			src/menu/menu_pause/menu_pause.o    \
			src/fight/open_opponents_sprite_fight.o \
			src/fight/open_scenes_sprite_fight.o	\
			src/fight/display.o \
			src/fight/tank_and_flash_management.o   \
			src/fight/offset.o  \
			src/menu/init_menu.o			\
			src/back/back.o				\
			src/back/back_2.o	\
			src/back/mouvement/entity_mouvement.o	\
			src/game/initialization/init_mvt.o \
			src/fight/fight_scenes.o	\
			src/game/initialization/init_mvt.o	\
			src/menu/menu_main/play_button.o	\
			src/menu/menu_main/settings_button.o	\
			src/menu/menu_main/quit_button.o	\
			src/menu/open_sprites_settings.o	\
			src/game/inventory/shop.o	\
			src/game/inventory/shop_2.o	\
			src/game/inventory/new_tank.o	\
			src/game/initialization/init_shop.o	\
			src/game/initialization/init_user_exp.o	\
			src/game/initialization/init_tanks_stat.o	\
			src/game/initialization/init_world.o	\
			src/game/initialization/init_time.o	\
			src/game/initialization/init_inventory.o	\
			src/game/world_sprite/display_tank_stats.o	\
			src/game/world_sprite/floor2.o	\
			src/menu/menu_settings/display_content_settings.o	\
			src/game/user_stat/main_user_stat.o	\
			src/back/mouvement/get_direction.o	\
			src/menu/menu_settings/move_settings_menu.o	\
			src/menu/menu_settings/chg_settings.o	\
			src/menu/menu_settings/back_button_settings.o \
			src/history/open_history_assets.o \
			src/history/history_scene.o \
			src/menu/menu_settings/back_button_settings.o	\
			src/back/mouvement/get_path.o	\
			src/menu/open_sprites_menu.o	\
			src/game/world/cube/cube_2.o	\
			src/game/world/cube/cube_3.o	\
			src/game/world/cube/cube_4.o	\
			src/menu/menu_pause/back_main_menu_but.o	\
			src/menu/menu_pause/set_sound_pause.o	\
			src/end_of_game/open_eog_sprite.o   \
			src/fight/open_sprites_fight.o	\
			src/history/pass_next_game.o	\
			src/game/world/next_map.o	\
			src/back/fight_calcul.o	\
			src/back/back_3.o	\
			src/back/mouvement/set_fight.o	\
			src/rain_particules/rain_particules_init.o	\
			src/turn_management/turn_management.o	\
			src/back/fill_fight_struct.o

all: $(NAME)

$(NAME):	$(SRC)
	@make -C lib/my
	@$(CC) -o $@ $^ $(LDFLAGS)
	@printf "[\033[0;32mbuilt\033[0m] % 58s\n" $(NAME) | tr ' ' '.'

debug:	CFLAGS += -g
debug:	re

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@printf "[\033[0;36mcompiled\033[0m] % 55s\n" $< | tr ' ' '.'

clean:
	@rm -f $(SRC)
	@printf "[\033[0;31mremoved\033[0m] % 55s\n" $(SRC) | tr ' ' '.'

fclean:		clean
	@make fclean -C lib/my
	@rm -f $(NAME)
	@printf "[\033[0;31mremoved\033[0m] % 55s\n" $(NAME) | tr ' ' '.'


re:		fclean all

/*
** EPITECH PROJECT, 2019
** create_window
** File description:
** create_window
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include "my_rpg.h"
#include "menu_rpg.h"
#include "destroy_ressources.h"
#include "history_parser.h"

char (*rpg_main_init_func[])(summary_t *s) =
{
    open_menu_sprites, open_fight_opponents_sprites,
    open_fight_scenes_sprites, init_time, init_world, default_scenes,
    init_menu, init_mvt, init_user_exp, init_tanks_stat, history_parser,
    open_history_assets, open_eof, rain_init, NULL
};

char create_window(summary_t *summary)
{
    sfVideoMode mode = {1920, 1080, 32};

    summary->win.window = sfRenderWindow_create(mode, "my_RPG",
        sfClose | sfResize, NULL);
    if (!summary->win.window)
        return (FAILURE);
    return (SUCCESS);
}

void update_loading_screen(summary_t *s)
{
    short val = 440;

    sfRenderWindow_drawSprite(s->win.window, s->loading.sprite, NULL);
    for (int a = 0; a < s->loading.position; ++a) {
        sfRectangleShape_setPosition(s->loading.shape, (sfVector2f){val, 477});
        DrawRectangleShape(s->win.window, s->loading.shape, NULL);
        val += (int)(1034 / (LEN_INIT - 1));
    }
    ++s->loading.position;
    sfRenderWindow_display(s->win.window);
}

char rpg(void)
{
    summary_t summary;

    if (create_window(&summary) == FAILURE ||
        loading_screen(&summary) == FAILURE)
        return (FAILURE);
    for (int i = 0; rpg_main_init_func[i]; ++i) {
        if (rpg_main_init_func[i](&summary) == FAILURE)
            return (FAILURE);
        update_loading_screen(&summary);
    }
    if (main_scenes(&summary) == FAILURE)
        return (FAILURE);
    destroy_ressources(&summary);
    return (SUCCESS);
}
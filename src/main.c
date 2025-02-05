/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** main.c
*/

#include "duck_hunt.h"

void restart_data(game_t *game, sprite_t *sprite)
{
    game->state = 0;
    game->sound->sound_coin = 1;
    game->lifes = 3;
    game->count_hits = 0;
    sprite->one_ups =
        sfTexture_createFromFile("graphics/3_lifes.png", NULL);
    sprite->life_bar = sfSprite_create();
}

void restart_loop(game_t *game, sprite_t *sprite,
    mouse_t *mouse, button_t *button)
{
    display_score(game);
    check_music(game, sprite);
    sfSprite_destroy(sprite->life_bar);
    sfTexture_destroy(sprite->one_ups);
    restart_data(game, sprite);
    get_lifes(sprite);
    loop(game, sprite, mouse, button);
}

void loop(game_t *game, sprite_t *sprite, mouse_t *mouse, button_t *button)
{
    float speed = 7.0f;

    while (sfRenderWindow_isOpen(game->window)) {
        process_events(game);
        tracer(game, mouse);
        if (game->state == 0) {
            check_music(game, sprite);
            menu_state(game, mouse, sprite, button);
        }
        if (game->state == 1) {
            check_music(game, sprite);
            play_state(game, mouse, sprite, button);
        }
        if (update_pos(game, sprite, &speed) == 0)
            break;
    }
    if (update_pos(game, sprite, &speed) == 0) {
        game->sound->game_over = 1;
        restart_loop(game, sprite, mouse, button);
    }
}

static void get_all(game_t *game, sprite_t *sprite,
    mouse_t *mouse, button_t *button)
{
    get_sprite(sprite);
    sprite->one_ups =
        sfTexture_createFromFile("graphics/3_lifes.png", NULL);
    sprite->life_bar = sfSprite_create();
    get_lifes(sprite);
    get_mouse(game, mouse);
    get_playbutton(button);
    get_menubutton(button);
    get_sounds(game);
    get_score(game);
}

void set(game_t *game, button_t *button)
{
    game->state = 0;
    game->lifes = 3;
    game->final_score = 0;
    game->sound = malloc(sizeof(sound_t));
    game->race_started = 0;
    game->sound->sound_coin = 0;
    game->count_hits = 0;
    game->sound->game_over = 0;
    button->menu_button_clicked = 0;
}

static void help(void)
{
    my_putstr("USAGE:\n");
    my_putstr("    ./my_hunter\n\n");
    my_putstr("DESCRIPTION:\n");
    my_putstr("    Left click on Mario/Lakitu to gain points.\n");
    my_putstr("    If you miss one, you loose a life (you only have 3)\n");
    my_putstr("    Click on play to start the game, ");
    my_putstr("click on the 'X' button to get back to the menu,\n");
    my_putstr("    click again to close the window.\n");
}

static int my_hunter(game_t *game, sprite_t *sprite,
    mouse_t *mouse, button_t *button)
{
    if (!game || !sprite || !mouse || !button)
        return 84;
    get_window(game);
    if (!game->window) {
        free(game);
        return 84;
    }
    set(game, button);
    get_all(game, sprite, mouse, button);
    loop(game, sprite, mouse, button);
    clean(game, sprite, mouse, button);
    return 0;
}

int main(int argc, char **argv, char *env[])
{
    game_t *game = malloc(sizeof(game_t));
    sprite_t *sprite = malloc(sizeof(sprite_t));
    mouse_t *mouse = malloc(sizeof(mouse_t));
    button_t *button = malloc(sizeof(button_t));

    if (argc > 2 || !game || !sprite || !mouse || !button || is_a_tty(env)) {
        free_all(game, sprite, mouse, button);
        return 84;
    }
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0)
            help();
        else
            return 84;
    } else
        my_hunter(game, sprite, mouse, button);
    return EXIT_SUCCESS;
}

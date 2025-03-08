/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** main.c
*/

#include "../include/duck_hunt.h"

static void process_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->window);
        if (game->state == 2)
            sfRenderWindow_close(game->window);
    }
}

void restart_loop(game_t *game, sprite_t *sprite,
    mouse_t *mouse, button_t *button)
{
    check_music(game, button);
    game->state = 0;
    game->count_fails = 0;
    game->sound_coin = 1;
    loop(game, sprite, mouse, button);
}

void loop(game_t *game, sprite_t *sprite, mouse_t *mouse, button_t *button)
{
    float speed = 7.0f;

    while (sfRenderWindow_isOpen(game->window)) {
        process_events(game);
        tracer(game, mouse);
        if (game->state == 0) {
            check_music(game, button);
            menu_state(game, mouse, sprite, button);
        }
        if (game->state == 1) {
            check_music(game, button);
            play_state(game, mouse, sprite, button);
        }
        if (update_pos(game, sprite, button, &speed) == 0)
            break;
    }
    if (update_pos(game, sprite, button, &speed) == 0)
        restart_loop(game, sprite, mouse, button);
}

void get_all(game_t *game, sprite_t *sprite, mouse_t *mouse, button_t *button)
{
    get_sprite(sprite);
    get_mouse(game, mouse);
    get_playbutton(button);
    get_menubutton(button);
    get_sounds(game);
}

void set(game_t *game, button_t *button)
{
    game->state = 0;
    game->count_fails = 0;
    game->race_started = 0;
    game->sound_coin = 0;
    button->menu_button_clicked = 0;
}

int main(void)
{
    game_t *game = malloc(sizeof(game_t));
    sprite_t *sprite = malloc(sizeof(sprite_t));
    mouse_t *mouse = malloc(sizeof(mouse_t));
    button_t *button = malloc(sizeof(button_t));

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
    return EXIT_SUCCESS;
}

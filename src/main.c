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
    }
}

void clean(game_t *game, sprite_t *sprite, mouse_t *mouse, button_t *button)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(mouse->mouse);
    sfTexture_destroy(mouse->target);
    sfSprite_destroy(game->image);
    sfTexture_destroy(game->background);
    sfRenderWindow_destroy(game->window);
    free(game);
    free(sprite);
    free(mouse);
    free(button);
}

void menu_state(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button)
{
    display_menu(game, mouse, sprite, button);
    if (display_menu(game, mouse, sprite, button) == 1)
        game->state = 1;
}

void play_state(game_t *game, mouse_t *mouse, sprite_t *sprite, int *frame)
{
    int animation_framerate = 10;

    display_game(game, mouse, sprite);
    if (*frame == 0)
        animate_sprite(sprite);
    *frame = (*frame + 1) % animation_framerate;
}

void loop(game_t *game, sprite_t *sprite, mouse_t *mouse, button_t *button)
{
    int frame = 0;
    float speed = 7.0f;

    game->state = 0;
    game->count_fails = 0;
    while (sfRenderWindow_isOpen(game->window)) {
        process_events(game);
        tracer(game, mouse);
        if (game->state == 0) {
            menu_state(game, mouse, sprite, button);
        } else
            play_state(game, mouse, sprite, &frame);
        if (update_pos(game, sprite, &speed) == 0)
            break;
    }
    if (update_pos(game, sprite, &speed) == 0)
        loop(game, sprite, mouse, button);
}

int main(void)
{
    game_t *game = malloc(sizeof(game_t));
    sprite_t *sprite = malloc(sizeof(sprite_t));
    mouse_t *mouse = malloc(sizeof(mouse_t));
    button_t *button = malloc(sizeof(mouse_t));

    if (!game)
        return 84;
    get_window(game);
    if (!game->window) {
        free(game);
        return 84;
    }
    get_background(game);
    get_sprite(sprite);
    get_mouse(game, mouse);
    get_playbutton(button);
    loop(game, sprite, mouse, button);
    clean(game, sprite, mouse, button);
    return EXIT_SUCCESS;
}

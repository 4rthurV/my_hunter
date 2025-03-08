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

void loop(game_t *game, sprite_t *sprite, mouse_t *mouse, button_t *button)
{
    float speed = 7.0f;

    game->state = 0;
    game->count_fails = 0;
    while (sfRenderWindow_isOpen(game->window)) {
        process_events(game);
        tracer(game, mouse);
        if (game->state == 0) {
            menu_state(game, mouse, sprite, button);
        } else
            play_state(game, mouse, sprite);
        if (update_pos(game, sprite, &speed) == 0)
            break;
    }
    if (update_pos(game, sprite, &speed) == 0)
        loop(game, sprite, mouse, button);
}

void get_all(game_t *game, sprite_t *sprite, mouse_t *mouse, button_t *button)
{
    get_sprite(sprite);
    get_mouse(game, mouse);
    get_playbutton(button);
    get_menubutton(button);
}

int main(void)
{
    game_t *game = malloc(sizeof(game_t));
    sprite_t *sprite = malloc(sizeof(sprite_t));
    mouse_t *mouse = malloc(sizeof(mouse_t));
    button_t *button = malloc(sizeof(button_t));

    game->music = sfMusic_createFromFile("audios/CoconutMall 8bit.wav");
    if (!game || !sprite || !mouse || !button || !game->music)
        return 84;
    sfMusic_setLoop(game->music, sfTrue);
    get_window(game);
    if (!game->window) {
        free(game);
        return 84;
    }
    get_all(game, sprite, mouse, button);
    sfMusic_play(game->music);
    loop(game, sprite, mouse, button);
    clean(game, sprite, mouse, button);
    return EXIT_SUCCESS;
}

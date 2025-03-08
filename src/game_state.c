/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** game_state.c
*/

#include "../include/duck_hunt.h"

void menu_state(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button)
{
    int menu_result = display_menu(game, mouse, sprite, button);

    if (menu_result == 1)
        game->state = 1;
    else if (menu_result == 2)
        game->state = 2;
}

void play_state(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button)
{
    float animation_delay = 0.35;
    sfTime elapsed;
    float elapsed_seconds;
    int quit_play = display_game(game, mouse, sprite, button);

    elapsed = sfClock_getElapsedTime(game->clock);
    elapsed_seconds = sfTime_asSeconds(elapsed);
    if (elapsed_seconds > animation_delay) {
        animate_sprite(sprite);
        sfClock_restart(game->clock);
    }
    if (quit_play == 1)
        game->state = 0;
}

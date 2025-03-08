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
    if (display_menu(game, mouse, sprite, button) == 1)
        game->state = 1;
}

void play_state(game_t *game, mouse_t *mouse, sprite_t *sprite)
{
    float animation_delay = 0.35;
    sfTime elapsed;
    float elapsed_seconds;

    display_game(game, mouse, sprite);
    elapsed = sfClock_getElapsedTime(game->clock);
    elapsed_seconds = sfTime_asSeconds(elapsed);
    if (elapsed_seconds > animation_delay) {
        animate_sprite(sprite);
        sfClock_restart(game->clock);
    }
}

/*
** EPITECH PROJECT, 2024
** MUL (C Graphical Programing)
** File description:
** event.c
*/

#include "../include/duck_hunt.h"

void process_events(game_t *game)
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

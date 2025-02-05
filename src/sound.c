/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** sound.c
*/

#include "../include/duck_hunt.h"

void get_sounds(game_t *game)
{
    game->music = sfMusic_createFromFile("audios/CoconutMall 8bit.ogg");
    game->loose = sfMusic_createFromFile("audios/Loose.wav");
    game->coin = sfMusic_createFromFile("audios/coin.ogg");
    sfMusic_setVolume(game->coin, 35);
}

void check_music(game_t *game, button_t *button)
{
    if (game->state == 0) {
        if (sfMusic_getStatus(game->music) == sfPlaying &&
            button->menu_button_clicked != 1) {
            sfMusic_stop(game->music);
            sfMusic_play(game->loose);
        }
        if (sfMusic_getStatus(game->loose) != sfPlaying)
            sfMusic_stop(game->music);
    } else if (game->state == 1 && sfMusic_getStatus(game->music) != sfPlaying)
        sfMusic_play(game->music);
}

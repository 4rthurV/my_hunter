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
}

void check_music(game_t *game)
{
    if (game->state == 0 && sfMusic_getStatus(game->music) == sfPlaying)
        sfMusic_stop(game->music);
    else if (game->state == 1 && sfMusic_getStatus(game->music) != sfPlaying)
        sfMusic_play(game->music);
}

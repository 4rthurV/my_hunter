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
    game->koopa = sfMusic_createFromFile("audios/koopa.ogg");
    sfMusic_setVolume(game->music, 40);
    sfMusic_setVolume(game->loose, 50);
    sfMusic_setVolume(game->coin, 40);
    sfMusic_setVolume(game->koopa, 100);
}

void which_sound(game_t *game, sprite_t *sprite)
{
    if (sprite->sprite_position.y > 540) {
        sfMusic_stop(game->coin);
        sfMusic_stop(game->koopa);
        sfMusic_play(game->coin);
    } else {
        sfMusic_stop(game->coin);
        sfMusic_stop(game->koopa);
        sfMusic_play(game->koopa);
    }
}

void sound_click(game_t *game, sprite_t *sprite)
{
    if (game->sound_coin == 1) {
        which_sound(game, sprite);
        game->sound_coin = 0;
    }
}

void check_music(game_t *game, sprite_t *sprite)
{
    sound_click(game, sprite);
    if (game->state == 0) {
        if (game->game_over == 1) {
            sfMusic_stop(game->music);
            sfMusic_stop(game->coin);
            sfMusic_stop(game->koopa);
            sfMusic_play(game->loose);
            game->game_over = 0;
            sfMusic_setPlayingOffset(game->loose, sfSeconds(0));
        }
        if (sfMusic_getStatus(game->loose) != sfPlaying)
            sfMusic_stop(game->music);
    } else if (game->state == 1 && sfMusic_getStatus(game->music) != sfPlaying)
        sfMusic_play(game->music);
}

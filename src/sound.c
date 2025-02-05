/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** sound.c
*/

#include "../include/duck_hunt.h"

void get_sounds(game_t *game)
{
    game->sound->music = sfMusic_createFromFile("audios/CoconutMall 8bit.ogg");
    game->sound->loose = sfMusic_createFromFile("audios/Loose.wav");
    game->sound->coin = sfMusic_createFromFile("audios/coin.ogg");
    game->sound->koopa = sfMusic_createFromFile("audios/koopa.ogg");
    game->sound->OneUp = sfMusic_createFromFile("audios/loose_life.ogg");
    sfMusic_setVolume(game->sound->music, 40);
    sfMusic_setVolume(game->sound->loose, 50);
    sfMusic_setVolume(game->sound->coin, 30);
    sfMusic_setVolume(game->sound->OneUp, 40);
    sfMusic_setVolume(game->sound->koopa, 100);
}

void which_sound(game_t *game, sprite_t *sprite)
{
    if (sprite->sprite_position.y > 540) {
        sfMusic_stop(game->sound->coin);
        sfMusic_stop(game->sound->koopa);
        sfMusic_play(game->sound->coin);
    } else {
        sfMusic_stop(game->sound->coin);
        sfMusic_stop(game->sound->koopa);
        sfMusic_play(game->sound->koopa);
    }
}

void sound_click(game_t *game, sprite_t *sprite)
{
    if (game->sound->sound_coin == 1) {
        which_sound(game, sprite);
        game->sound->sound_coin = 0;
    }
}

void loose_one_up(game_t *game)
{
    if (sfMusic_getStatus(game->sound->OneUp) == sfPlaying)
        sfMusic_stop(game->sound->OneUp);
    sfMusic_play(game->sound->OneUp);
}

void check_music(game_t *game, sprite_t *sprite)
{
    sound_click(game, sprite);
    if (game->state == 0) {
        if (game->sound->game_over == 1) {
            sfMusic_stop(game->sound->music);
            sfMusic_stop(game->sound->coin);
            sfMusic_stop(game->sound->koopa);
            sfMusic_play(game->sound->loose);
            game->sound->game_over = 0;
            sfMusic_setPlayingOffset(game->sound->loose, sfSeconds(0));
            sfMusic_setPlayingOffset(game->sound->OneUp, sfSeconds(0));
        }
        if (sfMusic_getStatus(game->sound->loose) != sfPlaying)
            sfMusic_stop(game->sound->music);
    } else if (game->state == 1 &&
        sfMusic_getStatus(game->sound->music) != sfPlaying) {
        sfMusic_stop(game->sound->loose);
        sfMusic_play(game->sound->music);
    }
}

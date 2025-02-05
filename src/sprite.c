/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** sprite.c
*/

#include "../include/duck_hunt.h"

void which_sprite(sprite_t *sprite, float *y_pos)
{
    sfIntRect rect = {0, 0, 321, 349};

    sprite->sprite_position = (sfVector2f){-150.0f, *y_pos};
    if (*y_pos > 540.0f) {
        sfTexture_destroy(sprite->texture);
        sprite->texture =
            sfTexture_createFromFile("graphics/spritesheet_mario.png", NULL);
    } else {
        sfTexture_destroy(sprite->texture);
        sprite->texture =
            sfTexture_createFromFile("graphics/lakitu.png", NULL);
    }
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, rect);
}

void reset_sprite(sprite_t *sprite, int *clicked, float *y_pos)
{
    *clicked = 0;
    which_sprite(sprite, y_pos);
}

void accel(game_t *game, float *speed)
{
    if (game->count_hits >= 0 && game->count_hits < 5)
        *speed += 0.3;
    if (game->count_hits >= 5 && game->count_hits < 10)
        *speed += 0.6;
    if (game->count_hits >= 10 && game->count_hits < 15)
        *speed += 0.9;
    if (game->count_hits >= 15 && game->count_hits < 20)
        *speed += 1.2;
    if (game->count_hits >= 20)
        *speed += 1.5;
}

int game_over(game_t *game, float *speed)
{
    if (game->lifes == 0) {
        game->final_score = 1;
        *speed = 7.0f;
        return 0;
    }
    return 1;
}

int update_pos(game_t *game, sprite_t *sprite, float *speed)
{
    int y_max = 100;
    int y_min = 800;
    float y_pos = 0;
    int clicked = 0;

    srand(time(0));
    y_pos = y_max + rand() % (y_min - y_max + 1);
    sprite->sprite_position.x += *speed;
    clicked = sprite_isclicked(game, sprite, &clicked);
    if (sprite->sprite_position.x > 1920)
        one_up(game, sprite);
    if (sprite->sprite_position.x > 1920 || clicked == 1) {
        reset_sprite(sprite, &clicked, &y_pos);
        accel(game, speed);
    }
    sfSprite_setPosition(sprite->sprite, sprite->sprite_position);
    return game_over(game, speed);
    return 1;
}

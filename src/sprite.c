/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** sprite.c
*/

#include "../include/duck_hunt.h"

int update_pos(game_t *game, sprite_t *sprite, float *speed)
{
    int y_max = 0;
    int y_min = 800;
    float y_pos = 0;
    int clicked = 0;

    srand(time(0));
    y_pos = y_max + rand() % (y_min - y_max + 1);
    sprite->sprite_position.x += *speed;
    clicked = sprite_isclicked(game, sprite, &clicked);
    if (sprite->sprite_position.x > 1920)
        game->count_fails += 1;
    if (sprite->sprite_position.x > 1920 || clicked == 1) {
        clicked = 0;
        sprite->sprite_position = (sfVector2f){-150.0f, y_pos};
        *speed += 0.3;
    }
    if (game->count_fails == 3)
        return 0;
    sfSprite_setPosition(sprite->sprite, sprite->sprite_position);
    return 1;
}

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
        *speed += 0.3;
        which_sprite(sprite, &y_pos);
    }
    if (game->count_fails == 3)
        return 0;
    sfSprite_setPosition(sprite->sprite, sprite->sprite_position);
    return 1;
}

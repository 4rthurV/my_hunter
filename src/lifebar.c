/*
** EPITECH PROJECT, 2024
** MUL (C Graphical Programing)
** File description:
** lifebar.c
*/

#include "../include/duck_hunt.h"

void get_lifes(sprite_t *sprite)
{
    sfSprite_setTexture(sprite->life_bar, sprite->one_ups, sfTrue);
    sfSprite_setScale(sprite->life_bar, (sfVector2f){1.475f, 1.475f});
    sfSprite_setPosition(sprite->life_bar, (sfVector2f){10.0f, 10.0f});
}

void two_lifes(game_t *game, sprite_t *sprite)
{
    if (game->lifes == 2) {
        sfMusic_stop(game->OneUp);
        sfMusic_play(game->OneUp);
        sprite->one_ups =
            sfTexture_createFromFile("graphics/2_lifes.png", NULL);
        sprite->life_bar = sfSprite_create();
        get_lifes(sprite);
        sfRenderWindow_drawSprite(game->window, sprite->life_bar, NULL);
    }
}

void one_life(game_t *game, sprite_t *sprite)
{
    if (game->lifes == 1) {
        sfMusic_stop(game->OneUp);
        sfMusic_play(game->OneUp);
        sprite->one_ups =
            sfTexture_createFromFile("graphics/1_life.png", NULL);
        sprite->life_bar = sfSprite_create();
        get_lifes(sprite);
        sfRenderWindow_drawSprite(game->window, sprite->life_bar, NULL);
    }
}

void no_more_life(game_t *game, sprite_t *sprite)
{
    if (game->lifes == 0) {
        sprite->one_ups =
            sfTexture_createFromFile("graphics/game_over.png", NULL);
        sprite->life_bar = sfSprite_create();
        get_lifes(sprite);
        sfRenderWindow_drawSprite(game->window, sprite->life_bar, NULL);
    }
}

void one_up(game_t *game, sprite_t *sprite)
{
    game->lifes -= 1;
    sfSprite_destroy(sprite->life_bar);
    sfTexture_destroy(sprite->one_ups);
    two_lifes(game, sprite);
    one_life(game, sprite);
    no_more_life(game, sprite);
}

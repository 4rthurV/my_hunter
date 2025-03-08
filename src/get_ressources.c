/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** get_ressources.c
*/

#include "../include/duck_hunt.h"

void get_window(game_t *game)
{
    game->mode = (sfVideoMode){1920, 1080, 32};
    game->window = sfRenderWindow_create(game->mode, "SFML window",
        sfResize | sfClose | sfFullscreen, NULL);
}

void get_background(game_t *game)
{
    game->background =
        sfTexture_createFromFile("graphics/background.png", NULL);
    game->image = sfSprite_create();
    sfSprite_setTexture(game->image, game->background, sfTrue);
    sfSprite_setScale(game->image, (sfVector2f){8.0f, 8.0f});
}

void get_sprite(game_t *game)
{
    sfIntRect rect = {642, 0, 321, 349};

    game->texture =
        sfTexture_createFromFile("graphics/spritesheet_yoshi.png", NULL);
    game->sprite = sfSprite_create();
    sfSprite_setTexture(game->sprite, game->texture, sfTrue);
    sfSprite_setTextureRect(game->sprite, rect);
    sfSprite_setScale(game->sprite, (sfVector2f){0.3f, 0.3f});
}

void get_mouse(game_t *game)
{
    game->target = sfTexture_createFromFile("graphics/shell.png", NULL);
    game->mouse = sfSprite_create();
    sfSprite_setTexture(game->mouse, game->target, sfTrue);
    sfSprite_setScale(game->mouse, (sfVector2f){0.075f, 0.075f});
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfWindow_setMouseCursorVisible((sfWindow*)game->window, sfFalse);
}

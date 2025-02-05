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
        sfTexture_createFromFile("graphics/background_menu.png", NULL);
    game->image = sfSprite_create();
    sfSprite_setTexture(game->image, game->background, sfTrue);
    sfSprite_setScale(game->image, (sfVector2f){0.01f, 0.01f});
}

void get_sprite(sprite_t *sprite)
{
    sfIntRect rect = {0, 0, 321, 349};
    int y_max = 500;
    int y_min = 1000;
    float y_pos = 0;

    srand(time(0));
    y_pos = y_max + rand() % (y_min - y_max + 1);
    sprite->texture =
        sfTexture_createFromFile("graphics/spritesheet_mario.png", NULL);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, rect);
    sfSprite_setScale(sprite->sprite, (sfVector2f){0.3f, 0.3f});
    sprite->sprite_position = (sfVector2f){-200.0f, y_pos};
    sfSprite_setPosition(sprite->sprite, sprite->sprite_position);
}

void get_mouse(game_t *game, mouse_t *mouse)
{
    mouse->target = sfTexture_createFromFile("graphics/shell.png", NULL);
    mouse->mouse = sfSprite_create();
    sfSprite_setTexture(mouse->mouse, mouse->target, sfTrue);
    sfSprite_setScale(mouse->mouse, (sfVector2f){0.075f, 0.075f});
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfWindow_setMouseCursorVisible((sfWindow*)game->window, sfFalse);
}

void get_playbutton(button_t *button)
{
    button->button = sfTexture_createFromFile("graphics/playbutton.png", NULL);
    button->play = sfSprite_create();
    sfSprite_setTexture(button->play, button->button, sfTrue);
    sfSprite_setScale(button->play, (sfVector2f){0.45f, 0.45f});
    sfSprite_setPosition(button->play, (sfVector2f){790.0f, 600.0f});
}

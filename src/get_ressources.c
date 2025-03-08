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
    game->clock = sfClock_create();
}

void get_sprite(sprite_t *sprite)
{
    sfIntRect rect = {0, 0, 321, 349};
    int y_max = 800;
    int y_min = 900;
    float y_pos = 0;

    srand(time(0));
    y_pos = y_max + rand() % (y_min - y_max);
    sprite->texture =
        sfTexture_createFromFile("graphics/spritesheet_mario.png", NULL);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, rect);
    sfSprite_setScale(sprite->sprite, (sfVector2f){0.3f, 0.3f});
    sprite->sprite_position = (sfVector2f){-150.0f, y_pos};
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
    button->playbutton =
        sfTexture_createFromFile("graphics/playbutton.png", NULL);
    button->play = sfSprite_create();
    sfSprite_setTexture(button->play, button->playbutton, sfTrue);
    sfSprite_setScale(button->play, (sfVector2f){2.4f, 2.4f});
    sfSprite_setPosition(button->play, (sfVector2f){833.0f, 590.0f});
}

void get_menubutton(button_t *button)
{
    button->menubutton =
        sfTexture_createFromFile("graphics/menubutton.png", NULL);
    button->menu = sfSprite_create();
    sfSprite_setTexture(button->menu, button->menubutton, sfTrue);
    sfSprite_setScale(button->menu, (sfVector2f){1.75f, 1.75f});
    sfSprite_setPosition(button->menu, (sfVector2f){1815.0f, 10.0f});
}

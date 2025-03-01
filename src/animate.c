/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** animate.c
*/

#include "../include/duck_hunt.h"

void animate_sprite(sprite_t *sprite)
{
    sfIntRect area = sfSprite_getTextureRect(sprite->sprite);

    area.left = (area.left + 321);
    if (area.left > 642)
        area.left = 0;
    sfSprite_setTextureRect(sprite->sprite, area);
}

void animate_clickedplay(game_t *game, mouse_t *mouse, button_t *button)
{
    sfTexture *clickedTexture =
    sfTexture_createFromFile("graphics/clicked_playbutton.png", NULL);

    sfSprite_setTexture(button->play, clickedTexture, sfTrue);
    draw_menu(game, mouse, button);
}

static void animate_clickedplay2(game_t *game,
    mouse_t *mouse, button_t *button)
{
    sfSprite_setTexture(button->play, button->playbutton, sfTrue);
    draw_menu(game, mouse, button);
}

void animate_playbutton(game_t *game, mouse_t *mouse, button_t *button)
{
    sfClock *clock = sfClock_create();

    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 0.2f)
        animate_clickedplay(game, mouse, button);
    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 0.275f)
        animate_clickedplay2(game, mouse, button);
    sfClock_destroy(clock);
}

static void animate_clickedmenu(game_t *game,
    mouse_t *mouse, button_t *button)
{
    sfTexture *clickedTexture =
    sfTexture_createFromFile("graphics/clicked_menubutton.png", NULL);

    sfSprite_setTexture(button->menu, clickedTexture, sfTrue);
    draw_menu(game, mouse, button);
}

static void animate_clickedmenu2(game_t *game,
    mouse_t *mouse, button_t *button)
{
    sfSprite_setTexture(button->menu, button->menubutton, sfTrue);
    draw_menu(game, mouse, button);
}

void animate_menubutton(game_t *game, mouse_t *mouse, button_t *button)
{
    sfClock *clock = sfClock_create();

    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 0.2f)
        animate_clickedmenu(game, mouse, button);
    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 0.3f)
        animate_clickedmenu2(game, mouse, button);
    sfClock_destroy(clock);
}

/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** display.c
*/

#include "../include/duck_hunt.h"

void draw(game_t *game, mouse_t *mouse, button_t *button)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->image, NULL);
    sfRenderWindow_drawSprite(game->window, button->play, NULL);
    sfRenderWindow_drawSprite(game->window, button->menu, NULL);
    sfRenderWindow_drawSprite(game->window, mouse->mouse, NULL);
    sfRenderWindow_display(game->window);
}

int display_menu(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button)
{
    int playbutton_clicked = 0;
    int menubutton_clicked = 0;

    game->background =
        sfTexture_createFromFile("graphics/starting_screen.png", NULL);
    game->image = sfSprite_create();
    sfSprite_setTexture(game->image, game->background, sfTrue);
    sfSprite_setScale(game->image, (sfVector2f){1.95f, 1.9f});
    draw(game, mouse, button);
    sprite->sprite_position.x = -200.0f;
    if (playbutton_isclicked(game, button, &playbutton_clicked) == 1) {
        click_play(game, mouse, button);
        return 1;
    }
    if (menubutton_isclicked(game, button, &menubutton_clicked) == 1) {
        click_menu(game, mouse, button);
        return 2;
    }
    return 0;
}

void display_game(game_t *game, mouse_t *mouse,
    sprite_t *sprite)
{
    sfRenderWindow_clear(game->window, sfBlack);
    game->background =
    sfTexture_createFromFile("graphics/background.png", NULL);
    game->image = sfSprite_create();
    sfSprite_setTexture(game->image, game->background, sfTrue);
    sfSprite_setScale(game->image, (sfVector2f){8.0f, 8.0f});
    sfRenderWindow_drawSprite(game->window, game->image, NULL);
    sfRenderWindow_drawSprite(game->window, sprite->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, mouse->mouse, NULL);
    sfRenderWindow_display(game->window);
    sfRenderWindow_drawSprite(game->window, sprite->sprite, NULL);
}

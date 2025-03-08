/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** display.c
*/

#include "../include/duck_hunt.h"

void animate_playbutton(game_t *game, mouse_t *mouse, button_t *button)
{
    sfClock *clock = sfClock_create();
    sfTexture *clickedTexture =
    sfTexture_createFromFile("graphics/clicked_playbutton.png", NULL);

    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 0.2f) {
        sfSprite_setTexture(button->play, clickedTexture, sfTrue);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->image, NULL);
        sfRenderWindow_drawSprite(game->window, button->play, NULL);
        sfRenderWindow_drawSprite(game->window, mouse->mouse, NULL);
        sfRenderWindow_display(game->window);
    }
    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 0.275f) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->image, NULL);
        sfSprite_setTexture(button->play, button->button, sfTrue);
        sfRenderWindow_drawSprite(game->window, button->play, NULL);
        sfRenderWindow_drawSprite(game->window, mouse->mouse, NULL);
        sfRenderWindow_display(game->window);
    }
}

int display_menu(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button)
{
    int playbutton_clicked = 0;

    game->background =
        sfTexture_createFromFile("graphics/starting_screen.png", NULL);
    game->image = sfSprite_create();
    sfSprite_setTexture(game->image, game->background, sfTrue);
    sfSprite_setScale(game->image, (sfVector2f){1.95f, 1.9f});
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->image, NULL);
    sfRenderWindow_drawSprite(game->window, button->play, NULL);
    sfRenderWindow_drawSprite(game->window, mouse->mouse, NULL);
    sfRenderWindow_display(game->window);
    sprite->sprite_position.x = -200.0f;
    if (playbutton_isclicked(game, button, &playbutton_clicked) == 1) {
        click_play(game, mouse, button);
        return 1;
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

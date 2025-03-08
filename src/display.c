/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** display.c
*/

#include "../include/duck_hunt.h"

int display_menu(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button)
{
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(button->play);

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
    if (game->event.type == sfEvtMouseButtonPressed &&
        game->event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&spriteBounds,
        game->event.mouseButton.x, game->event.mouseButton.y)) {
        sprite->sprite_position.x = -200.0f;
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

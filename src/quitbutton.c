/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** quitbutton.c
*/

#include "../include/duck_hunt.h"

int menubutton_isclicked(game_t *game, button_t *button,
    sprite_t *sprite, int *button_clicked)
{
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(button->menu);

    if (game->event.type == sfEvtMouseButtonPressed &&
        game->event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&spriteBounds,
        game->event.mouseButton.x, game->event.mouseButton.y)) {
            *button_clicked = 1;
            sprite->one_ups =
                sfTexture_createFromFile("graphics/3_lifes.png", NULL);
            sprite->life_bar = sfSprite_create();
            get_lifes(sprite);
        }
    return *button_clicked;
}

void click_menu(game_t *game, mouse_t *mouse, button_t *button)
{
    sfTexture *clickedTexture =
    sfTexture_createFromFile("graphics/clicked_menubutton.png", NULL);

    animate_menubutton(game, mouse, button);
    sfTexture_destroy(clickedTexture);
}

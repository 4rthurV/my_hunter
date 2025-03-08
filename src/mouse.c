/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** mouse.c
*/

#include "../include/duck_hunt.h"

int sprite_isclicked(game_t *game, sprite_t *sprite,
    button_t *button, int *sprite_clicked)
{
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(sprite->sprite);

    if (game->event.type == sfEvtMouseButtonPressed &&
        game->event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&spriteBounds,
        game->event.mouseButton.x, game->event.mouseButton.y)) {
            game->count_hits += 1;
            *sprite_clicked = 1;
            game->sound_coin = 1;
            check_music(game, button);
        }
    return *sprite_clicked;
}

int playbutton_isclicked(game_t *game, button_t *button,
    int *playbutton_clicked)
{
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(button->play);

    if (game->event.type == sfEvtMouseButtonPressed &&
        game->event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&spriteBounds,
        game->event.mouseButton.x, game->event.mouseButton.y))
            *playbutton_clicked = 1;
    return *playbutton_clicked;
}

void click_play(game_t *game, mouse_t *mouse, button_t *button)
{
    sfTexture *clickedTexture =
    sfTexture_createFromFile("graphics/clicked_playbutton.png", NULL);

    animate_playbutton(game, mouse, button);
    sfTexture_destroy(clickedTexture);
}

int quitbutton_isclicked(game_t *game, button_t *button,
    int *quitbutton_clicked)
{
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(button->menu);

    if (game->event.type == sfEvtMouseButtonPressed &&
        game->event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&spriteBounds,
        game->event.mouseButton.x, game->event.mouseButton.y)) {
            button->menu_button_clicked = 1;
            *quitbutton_clicked = 1;
    }
    return *quitbutton_clicked;
}

void click_quit(game_t *game, mouse_t *mouse, button_t *button)
{
    sfTexture *clickedTexture =
    sfTexture_createFromFile("graphics/clicked_menubutton.png", NULL);

    animate_menubutton(game, mouse, button);
    sfTexture_destroy(clickedTexture);
}

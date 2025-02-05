/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** mouse.c
*/

#include "../include/duck_hunt.h"

void tracer(game_t *game, mouse_t *mouse)
{
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(game->window);

    sfSprite_setPosition(mouse->mouse, (sfVector2f)
        {mousePosition.x - (sfSprite_getGlobalBounds(mouse->mouse).width / 2),
        mousePosition.y - (sfSprite_getGlobalBounds(mouse->mouse).height
        / 2)});
}

int sprite_isclicked(game_t *game, sprite_t *sprite, int *sprite_clicked)
{
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(sprite->sprite);

    if (game->event.type == sfEvtMouseButtonPressed &&
        game->event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&spriteBounds,
        game->event.mouseButton.x, game->event.mouseButton.y)) {
            game->count_hits += 1;
            *sprite_clicked = 1;
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
    sfClock *clock = sfClock_create();
    sfTexture *clickedTexture =
    sfTexture_createFromFile("graphics/clicked_playbutton.png", NULL);

    animate_playbutton(game, mouse, button);
    sfTexture_destroy(clickedTexture);
    sfClock_destroy(clock);
}

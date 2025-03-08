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

int mouse_isclicked(game_t *game, sprite_t *sprite, int *clicked)
{
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(sprite->sprite);
    int hits = 0;

    if (game->event.type == sfEvtMouseButtonPressed &&
        game->event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&spriteBounds,
        game->event.mouseButton.x, game->event.mouseButton.y)) {
            *clicked = 1;
            printf("hits : %d\n", hits);
    }
    return *clicked;
}

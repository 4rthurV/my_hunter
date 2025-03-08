/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** crosshair.c
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

/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** clean.c
*/

#include "../include/duck_hunt.h"

void clean(game_t *game, sprite_t *sprite, mouse_t *mouse, button_t *button)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(mouse->mouse);
    sfTexture_destroy(mouse->target);
    sfSprite_destroy(button->play);
    sfTexture_destroy(button->playbutton);
    sfSprite_destroy(button->menu);
    sfTexture_destroy(button->menubutton);
    sfSprite_destroy(game->image);
    sfTexture_destroy(game->background);
    sfClock_destroy(game->clock);
    sfMusic_destroy(game->music);
    sfRenderWindow_destroy(game->window);
    free(game);
    free(sprite);
    free(mouse);
    free(button);
}

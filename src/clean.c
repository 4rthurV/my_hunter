/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** clean.c
*/

#include "../include/duck_hunt.h"

void clean_sounds(game_t *game)
{
    sfMusic_destroy(game->sound->music);
    sfMusic_destroy(game->sound->coin);
    sfMusic_destroy(game->sound->loose);
    sfMusic_destroy(game->sound->OneUp);
    sfMusic_destroy(game->sound->koopa);
}

void clean_sprites(game_t *game, sprite_t *sprite,
    mouse_t *mouse, button_t *button)
{
    sfSprite_destroy(sprite->sprite);
    sfSprite_destroy(mouse->mouse);
    sfSprite_destroy(button->play);
    sfSprite_destroy(button->menu);
    sfSprite_destroy(game->image);
    sfSprite_destroy(sprite->life_bar);
}

void clean_textures(game_t *game, sprite_t *sprite,
    mouse_t *mouse, button_t *button)
{
    sfTexture_destroy(sprite->texture);
    sfTexture_destroy(mouse->target);
    sfTexture_destroy(button->playbutton);
    sfTexture_destroy(button->menubutton);
    sfTexture_destroy(sprite->one_ups);
    sfTexture_destroy(game->background);
}

void free_all(game_t *game, sprite_t *sprite, mouse_t *mouse, button_t *button)
{
    free(game->sound);
    free(game);
    free(sprite);
    free(mouse);
    free(button);
}

void clean(game_t *game, sprite_t *sprite, mouse_t *mouse, button_t *button)
{
    clean_sounds(game);
    clean_sprites(game, sprite, mouse, button);
    clean_textures(game, sprite, mouse, button);
    sfText_destroy(game->text);
    sfFont_destroy(game->font);
    sfClock_destroy(game->clock);
    sfRenderWindow_destroy(game->window);
    free_all(game, sprite, mouse, button);
}

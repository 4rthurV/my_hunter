/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** main.c
*/

#include "../include/duck_hunt.h"

static void process_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->window);
    }
}

void tracer(game_t *game)
{
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(game->window);

    sfSprite_setPosition(game->mouse, (sfVector2f)
        {mousePosition.x - (sfSprite_getGlobalBounds(game->mouse).width / 2),
        mousePosition.y - (sfSprite_getGlobalBounds(game->mouse).height / 2)});
}

void display_all(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->image, NULL);
    sfRenderWindow_drawSprite(game->window, game->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->mouse, NULL);
    sfRenderWindow_display(game->window);
}

void clean(game_t *game)
{
    sfSprite_destroy(game->sprite);
    sfTexture_destroy(game->texture);
    sfSprite_destroy(game->mouse);
    sfTexture_destroy(game->target);
    sfSprite_destroy(game->image);
    sfTexture_destroy(game->background);
    sfRenderWindow_destroy(game->window);
}

void loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        process_events(game);
        tracer(game);
        display_all(game);
    }
}

int main(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return 84;
    get_window(game);
    if (!game->window) {
        free(game);
        return 84;
    }
    get_background(game);
    get_sprite(game);
    get_mouse(game);
    loop(game);
    clean(game);
    free(game);
    return EXIT_SUCCESS;
}

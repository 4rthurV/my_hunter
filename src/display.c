/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** display.c
*/

#include "../include/duck_hunt.h"

void draw_menu(game_t *game, mouse_t *mouse, button_t *button)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->image, NULL);
    if (game->final_score == 1) {
        sfText_setPosition(game->text, (sfVector2f){620.0, 480.0});
        sfText_setColor(game->text, sfWhite);
        sfRenderWindow_drawText(game->window, game->text, NULL);
    }
    sfRenderWindow_drawSprite(game->window, button->play, NULL);
    sfRenderWindow_drawSprite(game->window, button->menu, NULL);
    sfRenderWindow_drawSprite(game->window, mouse->mouse, NULL);
    sfRenderWindow_display(game->window);
}

int display_menu(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button)
{
    int playbutton_clicked = 0;
    int menubutton_clicked = 0;

    game->lifes = 3;
    game->background =
        sfTexture_createFromFile("graphics/starting_screen.png", NULL);
    game->image = sfSprite_create();
    sfSprite_setTexture(game->image, game->background, sfTrue);
    sfSprite_setScale(game->image, (sfVector2f){1.95f, 1.9f});
    draw_menu(game, mouse, button);
    sprite->sprite_position.x = -200.0f;
    if (playbutton_isclicked(game, button, &playbutton_clicked) == 1) {
        click_play(game, mouse, button);
        return 1;
    }
    if (menubutton_isclicked(game, button, sprite, &menubutton_clicked) == 1) {
        click_menu(game, mouse, button);
        return 2;
    }
    return 0;
}

void from_play_to_menu(game_t *game, sprite_t *sprite,
    mouse_t *mouse, button_t *button)
{
    game->state = 0;
    sfRenderWindow_clear(game->window, sfBlack);
    display_menu(game, mouse, sprite, button);
}

void draw_game(game_t *game, sprite_t *sprite,
    mouse_t *mouse, button_t *button)
{
    sfRenderWindow_drawSprite(game->window, game->image, NULL);
    display_score(game);
    sfRenderWindow_drawSprite(game->window, sprite->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, sprite->life_bar, NULL);
    sfRenderWindow_drawSprite(game->window, button->menu, NULL);
    sfRenderWindow_drawSprite(game->window, mouse->mouse, NULL);
    sfRenderWindow_display(game->window);
    sfRenderWindow_drawSprite(game->window, sprite->sprite, NULL);
    game->final_score = 0;
}

int display_game(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button)
{
    int quitbutton_clicked = 0;

    sfRenderWindow_clear(game->window, sfBlack);
    game->background =
    sfTexture_createFromFile("graphics/background.png", NULL);
    game->image = sfSprite_create();
    sfSprite_setTexture(game->image, game->background, sfTrue);
    sfSprite_setScale(game->image, (sfVector2f){8.0f, 8.0f});
    draw_game(game, sprite, mouse, button);
    if (quitbutton_isclicked(game, button, &quitbutton_clicked) == 1) {
        from_play_to_menu(game, sprite, mouse, button);
        return 1;
    }
    return 0;
}

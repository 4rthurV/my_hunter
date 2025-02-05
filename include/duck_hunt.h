/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** duck_hunt.h
*/

#ifndef DUCK_HUNT_H
    #define DUCK_HUNT_H
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>

typedef struct game_s {
    sfVideoMode mode;
    sfRenderWindow* window;
    sfTexture* background;
    sfSprite* image;
    sfEvent event;
    int count_fails;
    int state;
} game_t;
typedef struct button_s {
    sfTexture* button;
    sfSprite* play;
} button_t;
typedef struct sprite_s {
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f sprite_position;
} sprite_t;
typedef struct mouse_s {
    sfTexture* target;
    sfSprite* mouse;
} mouse_t;

void get_window(game_t *game);
void get_sprite(sprite_t *sprite);
void get_mouse(game_t *game, mouse_t *mouse);
void get_playbutton(button_t *button);
void animate_sprite(sprite_t *sprite);
int update_pos(game_t *game, sprite_t *sprite, float *speed);
void tracer(game_t *game, mouse_t *mouse);
int mouse_isclicked(game_t *game, sprite_t *sprite, int *clicked);
int display_menu(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button);
void display_game(game_t *game, mouse_t *mouse, sprite_t *sprite);
#endif

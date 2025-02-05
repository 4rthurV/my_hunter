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

typedef struct game_s {
    sfVideoMode mode;
    sfRenderWindow* window;
    sfTexture* texture;
    sfTexture* target;
    sfTexture* background;
    sfSprite* sprite;
    sfSprite* mouse;
    sfSprite* image;
    sfEvent event;
} game_t;

void get_window(game_t *game);
void get_background(game_t *game);
void get_sprite(game_t *game);
void get_mouse(game_t *game);
#endif

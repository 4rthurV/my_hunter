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
    #include <SFML/System.h>
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
    sfClock* clock;
    sfMusic* music;
    sfMusic* loose;
    sfMusic* coin;
    int count_fails;
    int state;
    int count_hits;
    int race_started;
    int sound_coin;
} game_t;
typedef struct button_s {
    sfTexture* playbutton;
    sfSprite* play;
    sfTexture* menubutton;
    sfSprite* menu;
    int menu_button_clicked;
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
void get_menubutton(button_t *button);
void get_sounds(game_t *game);
void check_music(game_t *game, button_t *button);
void loop(game_t *game, sprite_t *sprite, mouse_t *mouse, button_t *button);
void animate_sprite(sprite_t *sprite);
void animate_playbutton(game_t *game, mouse_t *mouse, button_t *button);
void animate_menubutton(game_t *game, mouse_t *mouse, button_t *button);
int update_pos(game_t *game, sprite_t *sprite,
    button_t *button, float *speed);
void which_sprite(sprite_t *sprite, float *y_pos);
void tracer(game_t *game, mouse_t *mouse);
int sprite_isclicked(game_t *game, sprite_t *sprite,
    button_t *button, int *clicked);
int playbutton_isclicked(game_t *game, button_t *button,
    int *playbutton_clicked);
int menubutton_isclicked(game_t *game, button_t *button,
    int *menubutton_clicked);
int quitbutton_isclicked(game_t *game, button_t *button,
    int *button_clicked);
int display_menu(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button);
int display_game(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button);
void draw(game_t *game, mouse_t *mouse, button_t *button);
void click_play(game_t *game, mouse_t *mouse, button_t *button);
void click_menu(game_t *game, mouse_t *mouse, button_t *button);
void click_quit(game_t *game, mouse_t *mouse, button_t *button);
void menu_state(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button);
void play_state(game_t *game, mouse_t *mouse,
    sprite_t *sprite, button_t *button);
void from_play_to_menu(game_t *game, sprite_t *sprite,
    mouse_t *mouse, button_t *button);
void clean(game_t *game, sprite_t *sprite, mouse_t *mouse, button_t *button);
#endif

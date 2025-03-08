/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** score.c
*/

#include "../include/duck_hunt.h"

char *my_scorecat(game_t *game, char *scoretext)
{
    char *score_str = int_to_str(game->count_hits);
    int len_scoretext = my_strlen(scoretext);
    int len_score = my_strlen(score_str);
    char *result = malloc(len_scoretext + len_score + 1);

    for (int i = 0; i < len_scoretext; i++)
        result[i] = scoretext[i];
    for (int i = 0; i < len_score; i++)
        result[len_scoretext + i] = score_str[i];
    result[len_scoretext + len_score] = '\0';
    free(score_str);
    return result;
}

char *int_to_str(int num)
{
    int len = 0;
    int temp = num;
    char *str;

    if (num == 0)
        len = 1;
    while (temp != 0) {
        temp /= 10;
        len++;
    }
    str = malloc(len + 1);
    str[len] = '\0';
    for (int i = len - 1; i >= 0; i--) {
        str[i] = (num % 10) + '0';
        num /= 10;
    }
    return str;
}

void display_score(game_t *game)
{
    char *scoretext = "Your score is : ";
    char *final_score = my_scorecat(game, scoretext);

    sfText_setString(game->text, final_score);
    sfText_setPosition(game->text, (sfVector2f){570.0, 705.0});
    sfText_setScale(game->text, (sfVector2f){0.6f, 0.6f});
    sfText_setLetterSpacing(game->text, 1.4);
    sfText_setOutlineThickness(game->text, 1.1);
    sfText_setColor(game->text, sfBlack);
    sfRenderWindow_drawText(game->window, game->text, NULL);
}

void get_score(game_t *game)
{
    game->font = sfFont_createFromFile("graphics/mariokart_wii.ttf");
    game->text = sfText_create();
    sfText_setFont(game->text, game->font);
    sfText_setCharacterSize(game->text, 50);
}

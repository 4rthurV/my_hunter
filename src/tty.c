/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-arthur.vignes
** File description:
** tty.c
*/

#include "../include/duck_hunt.h"

int is_a_tty(char *env[])
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "DISPLAY=", 8) == 0)
            return 1;
    }
    return 0;
}

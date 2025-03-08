/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** display characters of a string
*/

#include "../include/duck_hunt.h"

int my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}

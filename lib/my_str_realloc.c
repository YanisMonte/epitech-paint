/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_str_realloc.c
*/

#include "../include/lib.h"

char *my_str_realloc(char *str, int size)
{
    char *new_str = malloc(sizeof(char) * (size + 1));
    int old_size = my_strlen(str);

    new_str[size] = '\0';
    for (int i = 0; i < size; i++) {
        if (i < old_size) {
            new_str[i] = str[i];
        } else {
            new_str[i] = ' ';
        }
    }
    return (new_str);
}

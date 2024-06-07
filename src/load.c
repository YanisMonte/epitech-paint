/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-yanis.monte
** File description:
** load.c
*/

#include "../include/paint.h"

void load_file(graphic_t *graphic)
{
    char *buffer = NULL;
    size_t n = 0;
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();

    my_putstr("entrez le nom du fichier : ");
    getline(&buffer, &n, stdin);
    buffer = my_str_realloc(buffer, my_strlen(buffer) - 1);
    texture = sfTexture_createFromFile(buffer, NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    graphic->file_to_load = sprite;
}

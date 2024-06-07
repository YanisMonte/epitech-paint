/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-yanis.monte
** File description:
** save.c
*/

#include "../include/paint.h"

void save(sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    sfTexture *texture = sfTexture_create(size.x, size.y);
    sfImage *image;
    char *buffer = NULL;
    size_t n = 0;

    sfTexture_updateFromRenderWindow(texture, window, 0, 0);
    image = sfTexture_copyToImage(texture);
    my_putstr("entrez le nom du fichier : ");
    getline(&buffer, &n, stdin);
    buffer = my_str_realloc(buffer, my_strlen(buffer) - 1);
    sfImage_saveToFile(image, my_strcat(buffer, ".jpg"));
    my_putstr("fichier enregisté avec succés\n");
}

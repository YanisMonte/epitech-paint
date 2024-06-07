/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-yanis.monte
** File description:
** display_layer.c
*/

#include "../include/paint.h"

void display_elt(sfRenderWindow *window, img_t *img)
{
    pixel_t *pixel;

    if (img == NULL)
        return;
    display_elt(window, img->next);
    pixel = img->pixel;
    while (pixel != NULL) {
        sfRenderWindow_drawCircleShape(window, pixel->shape, NULL);
        pixel = pixel->next;
    }
    img = img->next;
}

void display_layer(graphic_t *graphic, sfRenderWindow *window)
{
    layer_t *tmp_layer = graphic->layer;
    img_t *tmp;

    if (graphic->file_to_load != NULL)
        sfRenderWindow_drawSprite(window, graphic->file_to_load, NULL);
    while (tmp_layer != NULL) {
        tmp = tmp_layer->img;
        display_elt(window, tmp);
        tmp_layer = tmp_layer->next;
    }
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-yanis.monte
** File description:
** free_linked_list.c
*/

#include "../include/paint.h"

static void free_pixel(pixel_t **pixel)
{
    pixel_t *temp;

    while ((*pixel) != NULL) {
        temp = (*pixel);
        (*pixel) = (*pixel)->next;
        free(temp);
    }
}

void free_img(img_t **img)
{
    img_t *temp;

    while ((*img) != NULL) {
        temp = (*img);
        free_pixel(&(temp->pixel));
        (*img) = (*img)->next;
        free(temp);
    }
    free(*img);
}

void free_layer(layer_t **layer)
{
    layer_t *temp;

    while ((*layer) != NULL) {
        temp = (*layer);
        free_img(&(temp->img));
        (*layer) = (*layer)->next;
        free(temp);
    }
    free(*layer);
}

void free_graphic(graphic_t *graphic)
{
    if (graphic->file_to_load != NULL) {
        sfTexture_destroy(sfSprite_getTexture(graphic->file_to_load));
        sfSprite_destroy(graphic->file_to_load);
    }
    free_layer(&(graphic->layer));
    free(graphic);
}

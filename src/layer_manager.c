/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-yanis.monte
** File description:
** layer.c
*/

#include "../include/paint.h"

void add_layer(layer_t **layer)
{
    layer_t *new_layer = malloc(sizeof(layer_t));

    new_layer->next = NULL;
    new_layer->img = NULL;
    new_layer->been = NULL;
    add_img(&(new_layer->img));
    while (*layer != NULL) {
        *layer = (*layer)->next;
    }
    *layer = new_layer;
}

void add_img(img_t **img)
{
    img_t *new = malloc(sizeof(img_t));

    new->pixel = NULL;
    new->next = *img;
    *img = new;
}

void draw(sfRenderWindow *window, pixel_t **pixel, graphic_t *gra)
{
    sfVector2u windowsize = sfRenderWindow_getSize(window);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    float x = windowsize.x / gra->start_window_size.x;
    float y = windowsize.y / gra->start_window_size.y;
    sfVector2f position = (sfVector2f) {mouse.x / x, mouse.y / y};
    sfCircleShape *circle = sfCircleShape_create();
    pixel_t *new = malloc(sizeof(pixel_t));

    sfCircleShape_setRadius(circle, gra->size);
    sfCircleShape_setFillColor(circle, gra->color);
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setOrigin(circle, (sfVector2f) {gra->size, gra->size});
    new->next = *pixel;
    new->shape = circle;
    *pixel = new;
}

graphic_t *init_graphic(sfRenderWindow *window)
{
    graphic_t *graphic;
    sfVector2u size = sfRenderWindow_getSize(window);

    if (window == NULL)
        return (NULL);
    graphic = malloc(sizeof(graphic_t));
    graphic->layer = NULL;
    graphic->file_to_load = NULL;
    graphic->is_pressed = 0;
    graphic->size = 5;
    graphic->start_window_size = (sfVector2f) {size.x, size.y};
    graphic->color = sfBlack;
    graphic->lastcolor = sfBlack;
    add_layer(&(graphic->layer));
    return (graphic);
}

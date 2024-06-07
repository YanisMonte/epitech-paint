/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-yanis.monte
** File description:
** undo_redo.c
*/

#include "../include/paint.h"

void redo(layer_t **layer)
{
    img_t *new;

    if ((*layer)->been == NULL || (*layer)->been->pixel == NULL)
        return;
    new = malloc(sizeof(img_t));
    new->next = (*layer)->img;
    new->pixel = (*layer)->been->pixel;
    (*layer)->img = new;
    new = new->next;
    (*layer)->been = (*layer)->been->next;
    if ((*layer)->been == NULL)
        add_img(&(*layer)->been);
}

void undo(layer_t **layer)
{
    img_t *new;

    if ((*layer)->img->pixel == NULL)
        return;
    new = malloc(sizeof(img_t));
    new->next = (*layer)->been;
    new->pixel = (*layer)->img->pixel;
    (*layer)->been = new;
    new = new->next;
    (*layer)->img = (*layer)->img->next;
    if ((*layer)->img == NULL)
        add_img(&(*layer)->img);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-yanis.monte
** File description:
** add_line_between_point.c
*/

#include "../include/paint.h"

static sfVector2f get_step(sfVector2f distance, int size)
{
    sfVector2f step;

    step.x = distance.x;
    step.y = distance.y;
    while (step.x > size / 2 || step.x < size / 2 * -1
    || step.y > size / 2 || step.y < size / 2 * -1) {
        step.x /= 2;
        step.y /= 2;
    }
    return (step);
}

static sfVector2f get_distance(sfVector2f p1, sfVector2f p2)
{
    sfVector2f distance;

    distance.x = p1.x - p2.x;
    distance.y = p1.y - p2.y;
    return (distance);
}

static sfCircleShape *get_circle(int size, sfColor color,
    sfVector2f pos, sfVector2f distance)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f position;

    position.x = pos.x - distance.x;
    position.y = pos.y - distance.y;
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setRadius(circle, size);
    sfCircleShape_setOrigin(circle, (sfVector2f) {size, size});
    sfCircleShape_setPosition(circle, (sfVector2f) position);
    return (circle);
}

void add_line_between_point(img_t **img, int size, sfColor color)
{
    sfVector2f p1 = sfCircleShape_getPosition((*img)->pixel->shape);
    sfVector2f p2;
    sfVector2f distance;
    sfVector2f step;
    pixel_t *new;

    if ((*img)->pixel->next == NULL)
        return;
    p2 = sfCircleShape_getPosition((*img)->pixel->next->shape);
    distance = get_distance(p1, p2);
    step = get_step(distance, size);
    while (distance.x > size / 2 || distance.x < size / 2 * -1
    || distance.y > size / 2 || distance.y < size / 2 * -1) {
        distance.x -= step.x;
        distance.y -= step.y;
        new = malloc(sizeof(pixel_t));
        new->next = (*img)->pixel;
        new->shape = get_circle(size, color, p1, distance);
        (*img)->pixel = new;
    }
}

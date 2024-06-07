/*
** EPITECH PROJECT, 2024
** choose_color
** File description:
** choose_color
*/

#include "../../include/paint.h"

void find_color(ui_t *ui, sfMouseButtonEvent *mb, graphic_t *graphic,
    sfRenderWindow *w)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(ui->edit->tools->rgb_sprite);
    sfImage *image = sfImage_create(512, 512);
    sfColor color = sfColor_fromRGB(80, 80, 80);
    sfColor compare = sfColor_fromRGB(255, 255, 255);
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f temp = {(mb->x - (ws.x * 0.73)), (mb->y - (ws.y * 0.06))};

    if (sfFloatRect_contains(&pos, mb->x, mb->y)) {
        image = sfTexture_copyToImage(ui->edit->tools->rgb_texture);
        color = sfImage_getPixel(image, temp.x, temp.y);
        if (color.r != compare.r || color.g != compare.g
            || color.b != compare.b)
            graphic->color = color;
    }
}

void reedo_arrow(sfRenderWindow *w, ui_t *ui)
{
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f posab = {(float)(ws.x * 0.75), (float)(ws.y * 0.55)};
    sfVector2f sizeab = {(float)(ws.x * 0.11), (float)(ws.y * 0.2)};
    sfVector2f posar = {(float)(ws.x * 0.87), (float)(ws.y * 0.55)};
    sfVector2f sizear = {(float)(ws.x * 0.11), (float)(ws.y * 0.2)};

    sfRectangleShape_setPosition(ui->edit->tools->ab_hb, posab);
    sfRectangleShape_setSize(ui->edit->tools->ab_hb, sizeab);
    sfRectangleShape_setPosition(ui->edit->tools->ar_hb, posar);
    sfRectangleShape_setSize(ui->edit->tools->ar_hb, sizear);
}

/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-yanis.monte
** File description:
** pencil
*/

#include "../../include/paint.h"

void reedo_size(sfRenderWindow *w, ui_t *ui)
{
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f pos_less = {(float)(ws.x * 0.814), (float)(ws.y * 0.72)};
    sfVector2f pos_more = {(float)(ws.x * 0.875), (float)(ws.y * 0.72)};
    sfVector2f size = {80.f, 80.f};

    sfRectangleShape_setPosition(ui->edit->tools->hl, pos_less);
    sfRectangleShape_setSize(ui->edit->tools->hl, size);
    sfRectangleShape_setPosition(ui->edit->tools->hm, pos_more);
    sfRectangleShape_setSize(ui->edit->tools->hm, size);
}

void reedo_pen_and_eraser(sfRenderWindow *w, ui_t *ui)
{
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f pos_pen = {(float)(ws.x * 0.74), (float)(ws.y * 0.805)};
    sfVector2f pos_hitbox = {(float)(ws.x * 0.875), (float)(ws.y * 0.805)};
    sfVector2f size = {222.f, 200.f};

    sfRectangleShape_setPosition(ui->edit->tools->eh, pos_hitbox);
    sfRectangleShape_setSize(ui->edit->tools->eh, size);
    sfRectangleShape_setPosition(ui->edit->tools->ph, pos_pen);
    sfRectangleShape_setSize(ui->edit->tools->ph, size);
}

static void do_pen(tools_t *tools, sfRenderWindow *w)
{
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f pos = {(float)(ws.x * 0.74), (float)(ws.y * 0.78)};
    sfVector2f scale = {0.45f, 0.45f};
    sfVector2f pos_e = {(float)(ws.x * 0.88), (float)(ws.y * 0.80)};
    sfVector2f scale_e = {0.41f, 0.41f};
    sfVector2f posless = {(float)(ws.x * 0.82), (float)(ws.y * 0.70)};

    sfSprite_setTexture(tools->pencil, tools->pencil_texture, sfTrue);
    sfSprite_setPosition(tools->pencil, pos);
    sfSprite_setScale(tools->pencil, scale);
    sfSprite_setTexture(tools->eraser, tools->eraser_texture, sfTrue);
    sfSprite_setPosition(tools->eraser, pos_e);
    sfSprite_setScale(tools->eraser, scale_e);
    sfText_setPosition(tools->less, posless);
    sfText_setString(tools->less, "-");
    sfText_setFont(tools->less, tools->font);
    sfText_setCharacterSize(tools->less, 100);
    sfText_setFillColor(tools->less, sfBlack);
}

static void do_size(tools_t *tools, sfRenderWindow *w)
{
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f posmore = {(float)(ws.x * 0.88), (float)(ws.y * 0.70)};
    sfVector2f pos_more = {(float)(ws.x * 0.875), (float)(ws.y * 0.72)};
    sfVector2f size_more = {80.f, 80.f};
    sfVector2f pos_less = {(float)(ws.x * 0.814), (float)(ws.y * 0.72)};

    sfText_setPosition(tools->more, posmore);
    sfText_setString(tools->more, "+");
    sfText_setFont(tools->more, tools->font);
    sfText_setCharacterSize(tools->more, 100);
    sfText_setFillColor(tools->more, sfBlack);
    sfRectangleShape_setSize(tools->hm, size_more);
    sfRectangleShape_setFillColor(tools->hm, sfTransparent);
    sfRectangleShape_setOutlineThickness(tools->hm, 3.0);
    sfRectangleShape_setOutlineColor(tools->hm, sfBlack);
    sfRectangleShape_setPosition(tools->hm, pos_more);
    sfRectangleShape_setSize(tools->hl, size_more);
    sfRectangleShape_setFillColor(tools->hl, sfTransparent);
    sfRectangleShape_setOutlineThickness(tools->hl, 3.0);
    sfRectangleShape_setPosition(tools->hl, pos_less);
}

static void do_hitbox(tools_t *tools, sfRenderWindow *w)
{
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f pos_pen = {(float)(ws.x * 0.74), (float)(ws.y * 0.805)};
    sfVector2f size_more = {222.f, 200.f};
    sfVector2f pos_era = {(float)(ws.x * 0.875), (float)(ws.y * 0.805)};

    sfRectangleShape_setSize(tools->eh, size_more);
    sfRectangleShape_setFillColor(tools->eh, sfTransparent);
    sfRectangleShape_setOutlineThickness(tools->eh, 3.0);
    sfRectangleShape_setOutlineColor(tools->eh, sfBlack);
    sfRectangleShape_setPosition(tools->eh, pos_era);
    sfRectangleShape_setSize(tools->ph, size_more);
    sfRectangleShape_setFillColor(tools->ph, sfTransparent);
    sfRectangleShape_setOutlineThickness(tools->ph, 3.0);
    sfRectangleShape_setOutlineColor(tools->ph, sfBlack);
    sfRectangleShape_setPosition(tools->ph, pos_pen);
    sfRectangleShape_setOutlineColor(tools->hl, sfBlack);
}

tools_t *init_pen_erase(tools_t *tools, sfRenderWindow *w)
{
    tools->pencil_texture = sfTexture_createFromFile("assets/pen.png", NULL);
    tools->eraser_texture = sfTexture_createFromFile("assets/erase.png", NULL);
    tools->eraser = sfSprite_create();
    tools->pencil = sfSprite_create();
    tools->ph = sfRectangleShape_create();
    tools->eh = sfRectangleShape_create();
    tools->less = sfText_create();
    tools->more = sfText_create();
    tools->font = sfFont_createFromFile("assets/Monocraft.ttf");
    tools->hl = sfRectangleShape_create();
    tools->hm = sfRectangleShape_create();
    do_pen(tools, w);
    do_size(tools, w);
    do_hitbox(tools, w);
    return tools;
}

/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-yanis.monte
** File description:
** tools
*/

#include "../../include/paint.h"

static void do_arrow_sprite(tools_t *tools, sfVector2u ws, sfVector2f pos)
{
    sfVector2f sizear = {(float)(ws.x * 0.11), (float)(ws.y * 0.2)};
    sfVector2f sizeab = {(float)(ws.x * 0.11), (float)(ws.y * 0.2)};
    sfVector2f posar = {(float)(ws.x * 0.87), (float)(ws.y * 0.55)};
    sfVector2f posab = {(float)(ws.x * 0.75), (float)(ws.y * 0.55)};
    sfVector2f scale_arrow = {0.05f, 0.05f};
    sfVector2f pos_arrow = {(float)(ws.x * 0.87), (float)(ws.y * 0.55)};

    sfRectangleShape_setPosition(tools->ar_hb, posar);
    sfRectangleShape_setSize(tools->ar_hb, sizear);
    sfRectangleShape_setOutlineThickness(tools->ar_hb, 3.0);
    sfRectangleShape_setFillColor(tools->ar_hb, sfTransparent);
    sfRectangleShape_setPosition(tools->ab_hb, posab);
    sfRectangleShape_setSize(tools->ab_hb, sizeab);
    sfRectangleShape_setOutlineThickness(tools->ab_hb, 3.0);
    sfRectangleShape_setOutlineColor(tools->ab_hb, sfBlack);
    sfSprite_setPosition(tools->arrowr_sprite, pos);
    sfSprite_setScale(tools->arrowr_sprite, scale_arrow);
    sfSprite_setPosition(tools->arrowr_sprite, pos_arrow);
    sfSprite_setScale(tools->arrowr_sprite, scale_arrow);
    sfRectangleShape_setFillColor(tools->ab_hb, sfTransparent);
}

tools_t *do_arrows(tools_t *tools, sfRenderWindow *w, sfVector2f pos)
{
    sfVector2u ws = sfRenderWindow_getSize(w);

    tools->ar_hb = sfRectangleShape_create();
    tools->ab_hb = sfRectangleShape_create();
    do_arrow_sprite(tools, ws, pos);
    return tools;
}

static void set_back_and_text(tools_t *tools, sfVector2f pos,
    sfVector2f size, sfVector2u windowsize)
{
    sfVector2f scale_arrow = {0.05f, 0.05f};
    sfVector2f pos_arrow;

    pos_arrow.x = (float)(windowsize.x * 0.75);
    pos_arrow.y = (float)(windowsize.y * 0.55);
    sfRectangleShape_setSize(tools->back, size);
    sfRectangleShape_setOutlineThickness(tools->back, 3.0);
    sfRectangleShape_setOutlineColor(tools->back, sfBlack);
    sfRectangleShape_setFillColor(tools->back, sfColor_fromRGB(80, 80, 80));
    sfRectangleShape_setPosition(tools->back, pos);
    sfSprite_setTexture(tools->rgb_sprite, tools->rgb_texture, sfTrue);
    sfSprite_setPosition(tools->rgb_sprite, pos);
    sfSprite_setTexture(tools->arrowback_sprite,
        tools->ab_texture, sfTrue);
    sfSprite_setPosition(tools->arrowback_sprite, pos_arrow);
    sfSprite_setScale(tools->arrowback_sprite, scale_arrow);
}

tools_t *init_tools(sfRenderWindow *w)
{
    tools_t *t = malloc(sizeof(tools_t));
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f size = {(float)(ws.x * 0.27), (float)(ws.y * 0.931)};
    sfVector2f pos = {(float)(ws.x * 0.73), (float)(ws.y * 0.068)};

    t->rgb_texture = sfTexture_createFromFile("assets/RGB1.png", NULL);
    t->ab_texture = sfTexture_createFromFile("assets/back_arrow.png", NULL);
    t->ar_texture = sfTexture_createFromFile("assets/right_arrow.png", NULL);
    if (!t->rgb_texture || !t->ab_texture || !t->ar_texture)
        return NULL;
    t->arrowback_sprite = sfSprite_create();
    t->rgb_sprite = sfSprite_create();
    t->arrowr_sprite = sfSprite_create();
    t->back = sfRectangleShape_create();
    sfSprite_setTexture(t->arrowr_sprite, t->ar_texture, sfTrue);
    t = do_arrows(t, w, pos);
    t = init_pen_erase(t, w);
    sfRectangleShape_setOutlineColor(t->ar_hb, sfBlack);
    set_back_and_text(t, pos, size, ws);
    return t;
}

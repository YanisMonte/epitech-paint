/*
** EPITECH PROJECT, 2024
** edit
** File description:
** edit
*/

#include "../../include/paint.h"

void reedo_edit(sfRenderWindow *w, ui_t *ui)
{
    sfVector2f size;
    sfVector2u windowsize = sfRenderWindow_getSize(w);

    ui->edit->pos_edit.y = 1.f;
    ui->edit->pos_edit.x = (float)(windowsize.x * 0.060);
    size.x = (float)(windowsize.x * 0.055);
    size.y = (float)(windowsize.y * 0.062);
    sfRectangleShape_setPosition(ui->edit->edit_hitbox, ui->edit->pos_edit);
    sfRectangleShape_setSize(ui->edit->edit_hitbox, size);
}

void change_color_edit(ui_t *ui)
{
    sfColor back = sfColor_fromRGB(80, 80, 80);

    if (ui->state_edit == PRESSED_EDIT) {
        sfRectangleShape_setFillColor(ui->edit->edit_visible,
            sfColor_fromRGB(230, 230, 230));
        sfText_setFillColor(ui->edit->edit_text, sfColor_fromRGB(35, 35, 35));
    }
    if (ui->state_edit == RELEASED_EDIT) {
        sfRectangleShape_setFillColor(ui->edit->edit_visible, back);
        sfText_setFillColor(ui->edit->edit_text, sfWhite);
    }
    if (ui->state_edit == HOVER_EDIT) {
        sfRectangleShape_setFillColor(ui->edit->edit_visible,
            sfColor_fromRGB(170, 170, 170));
        sfText_setFillColor(ui->edit->edit_text, sfWhite);
    }
}

static void set_back_and_text(edit_t *edit, sfVector2f pos,
    sfVector2f size, sfVector2f pos_back)
{
    sfColor back = sfColor_fromRGB(80, 80, 80);

    sfRectangleShape_setSize(edit->edit_hitbox, size);
    sfRectangleShape_setOutlineThickness(edit->edit_hitbox, 3.0);
    sfRectangleShape_setOutlineColor(edit->edit_hitbox, sfBlack);
    sfRectangleShape_setFillColor(edit->edit_hitbox, sfTransparent);
    sfRectangleShape_setPosition(edit->edit_hitbox, pos_back);
    sfRectangleShape_setSize(edit->edit_visible, size);
    sfRectangleShape_setOutlineThickness(edit->edit_visible, 3.0);
    sfRectangleShape_setOutlineColor(edit->edit_visible, sfBlack);
    sfRectangleShape_setFillColor(edit->edit_visible, back);
    sfRectangleShape_setPosition(edit->edit_visible, pos_back);
    sfText_setPosition(edit->edit_text, pos);
    sfText_setString(edit->edit_text, "Edit");
    sfText_setFont(edit->edit_text, edit->font);
    sfText_setCharacterSize(edit->edit_text, 37);
    sfText_setFillColor(edit->edit_text, sfWhite);
}

edit_t *init_edit(sfRenderWindow *w)
{
    edit_t *edit = malloc(sizeof(edit_t));
    sfVector2f pos = {121.f, 10.f};
    sfVector2f size;
    sfVector2u windowsize = sfRenderWindow_getSize(w);

    if (!edit)
        return NULL;
    edit->tools = init_tools(w);
    edit->pos_edit.y = 1.f;
    edit->pos_edit.x = (float)(windowsize.x * 0.060);
    size.x = (float)(windowsize.x * 0.055);
    size.y = (float)(windowsize.y * 0.062);
    edit->font = sfFont_createFromFile("assets/Monocraft.ttf");
    if (edit->tools == NULL || edit->font == NULL)
        return NULL;
    edit->edit_text = sfText_create();
    edit->edit_hitbox = sfRectangleShape_create();
    edit->edit_visible = sfRectangleShape_create();
    set_back_and_text(edit, pos, size, edit->pos_edit);
    return edit;
}

/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include "../../include/paint.h"
void reedo_file(sfRenderWindow *w, ui_t *ui)
{
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f size = {(float)(ws.x * 0.055), (float)(ws.y * 0.070)};
    sfVector2f pos_new = {(float)(ws.x * 0.00005), (float)(ws.y * 0.068)};
    sfVector2f size_all = {(float)(ws.x * 0.122), (float)(ws.y * 0.065)};
    sfVector2f pos_open = {(float)(ws.x * 0.00005), (float)(ws.y * 0.14)};
    sfVector2f pos_save = {(float)(ws.x * 0.00005), (float)(ws.y * 0.211)};

    ui->file->pos_file.y = 1.f;
    ui->file->pos_file.x = (float)(ws.x * 0.0005);
    sfRectangleShape_setPosition(ui->file->file_hitbox, ui->file->pos_file);
    sfRectangleShape_setSize(ui->file->file_hitbox, size);
    sfRectangleShape_setPosition(ui->file->new_file_h, pos_new);
    sfRectangleShape_setSize(ui->file->new_file_h, size_all);
    sfRectangleShape_setPosition(ui->file->open_file_h, pos_open);
    sfRectangleShape_setSize(ui->file->open_file_h, size_all);
    sfRectangleShape_setPosition(ui->file->save_file_h, pos_save);
    sfRectangleShape_setSize(ui->file->save_file_h, size_all);
}

void change_color_file(ui_t *ui)
{
    sfColor back = sfColor_fromRGB(80, 80, 80);

    if (ui->state_file == PRESSED_FILE) {
        sfRectangleShape_setFillColor(ui->file->file_visible,
            sfColor_fromRGB(230, 230, 230));
        sfText_setFillColor(ui->file->file_text, sfColor_fromRGB(35, 35, 35));
    }
    if (ui->state_file == RELEASED_FILE) {
        sfRectangleShape_setFillColor(ui->file->file_visible, back);
        sfText_setFillColor(ui->file->file_text, sfWhite);
    }
    if (ui->state_file == HOVER_FILE) {
        sfRectangleShape_setFillColor(ui->file->file_visible,
            sfColor_fromRGB(170, 170, 170));
        sfText_setFillColor(ui->file->file_text, sfWhite);
    }
}

static void set_back_and_text(file_t *file, sfVector2f pos,
    sfVector2f size, sfVector2f pos_back)
{
    sfColor back = sfColor_fromRGB(80, 80, 80);

    sfRectangleShape_setSize(file->file_hitbox, size);
    sfRectangleShape_setOutlineThickness(file->file_hitbox, 3.0);
    sfRectangleShape_setOutlineColor(file->file_hitbox, sfBlack);
    sfRectangleShape_setFillColor(file->file_hitbox, sfTransparent);
    sfRectangleShape_setPosition(file->file_hitbox, pos_back);
    sfRectangleShape_setSize(file->file_visible, size);
    sfRectangleShape_setOutlineThickness(file->file_visible, 3.0);
    sfRectangleShape_setOutlineColor(file->file_visible, sfBlack);
    sfRectangleShape_setFillColor(file->file_visible, back);
    sfRectangleShape_setPosition(file->file_visible, pos_back);
    sfText_setPosition(file->file_text, pos);
    sfText_setString(file->file_text, "File");
    sfText_setFont(file->file_text, file->font);
    sfText_setCharacterSize(file->file_text, 37);
    sfText_setFillColor(file->file_text, sfWhite);
}

static void do_file_back(file_t *file, sfRenderWindow *w, sfColor color)
{
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f pos_new = {(float)(ws.x * 0.00005), (float)(ws.y * 0.068)};
    sfVector2f pos_open = {(float)(ws.x * 0.00005), (float)(ws.y * 0.14)};
    sfVector2f pos_save = {(float)(ws.x * 0.00005), (float)(ws.y * 0.2115)};
    sfVector2f size = {(float)(ws.x * 0.122), (float)(ws.y * 0.065)};

    sfRectangleShape_setSize(file->new_file_b, size);
    sfRectangleShape_setOutlineThickness(file->new_file_b, 3.0);
    sfRectangleShape_setOutlineColor(file->new_file_b, sfBlack);
    sfRectangleShape_setFillColor(file->new_file_b, color);
    sfRectangleShape_setPosition(file->new_file_b, pos_new);
    sfRectangleShape_setSize(file->open_file_b, size);
    sfRectangleShape_setOutlineThickness(file->open_file_b, 3.0);
    sfRectangleShape_setOutlineColor(file->open_file_b, sfBlack);
    sfRectangleShape_setFillColor(file->open_file_b, color);
    sfRectangleShape_setPosition(file->open_file_b, pos_open);
    sfRectangleShape_setSize(file->save_file_b, size);
    sfRectangleShape_setOutlineColor(file->save_file_b, sfBlack);
    sfRectangleShape_setFillColor(file->save_file_b, color);
    sfRectangleShape_setPosition(file->save_file_b, pos_save);
}

static void do_file_hitbox(file_t *file, sfRenderWindow *w)
{
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f pos_new = {(float)(ws.x * 0.00005), (float)(ws.y * 0.068)};
    sfVector2f pos_open = {(float)(ws.x * 0.00005), (float)(ws.y * 0.14)};
    sfVector2f pos_save = {(float)(ws.x * 0.00005), (float)(ws.y * 0.211)};
    sfVector2f size = {(float)(ws.x * 0.122), (float)(ws.y * 0.065)};

    sfRectangleShape_setSize(file->new_file_h, size);
    sfRectangleShape_setOutlineThickness(file->new_file_h, 3.0);
    sfRectangleShape_setOutlineColor(file->new_file_h, sfBlack);
    sfRectangleShape_setFillColor(file->new_file_h, sfTransparent);
    sfRectangleShape_setPosition(file->new_file_h, pos_new);
    sfRectangleShape_setSize(file->open_file_h, size);
    sfRectangleShape_setOutlineThickness(file->open_file_h, 3.0);
    sfRectangleShape_setOutlineColor(file->open_file_h, sfBlack);
    sfRectangleShape_setFillColor(file->open_file_h, sfTransparent);
    sfRectangleShape_setPosition(file->open_file_h, pos_open);
    sfRectangleShape_setSize(file->save_file_h, size);
    sfRectangleShape_setOutlineThickness(file->save_file_h, 3.0);
    sfRectangleShape_setFillColor(file->save_file_h, sfTransparent);
    sfRectangleShape_setPosition(file->save_file_h, pos_save);
}

static void do_file_name(file_t *file, sfRenderWindow *w)
{
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f pos_new = {(float)(ws.x * 0.005), (float)(ws.y * 0.07)};
    sfVector2f pos_open = {(float)(ws.x * 0.005), (float)(ws.y * 0.145)};
    sfVector2f pos_save = {(float)(ws.x * 0.005), (float)(ws.y * 0.218)};

    sfText_setPosition(file->new_file, pos_new);
    sfText_setString(file->new_file, "New File");
    sfText_setFont(file->new_file, file->font);
    sfText_setCharacterSize(file->new_file, 37);
    sfText_setFillColor(file->new_file, sfWhite);
    sfText_setPosition(file->open_file, pos_open);
    sfText_setString(file->open_file, "Open File");
    sfText_setFont(file->open_file, file->font);
    sfText_setCharacterSize(file->open_file, 37);
    sfText_setFillColor(file->open_file, sfWhite);
    sfText_setPosition(file->save_file, pos_save);
    sfText_setString(file->save_file, "Save File");
    sfText_setFont(file->save_file, file->font);
    sfText_setCharacterSize(file->save_file, 37);
    sfText_setFillColor(file->save_file, sfWhite);
}

file_t *begin_file(file_t *file)
{
    file->file_text = sfText_create();
    file->file_hitbox = sfRectangleShape_create();
    file->file_visible = sfRectangleShape_create();
    file->new_file = sfText_create();
    file->new_file_h = sfRectangleShape_create();
    file->open_file = sfText_create();
    file->open_file_h = sfRectangleShape_create();
    file->save_file = sfText_create();
    file->save_file_h = sfRectangleShape_create();
    file->save_file_b = sfRectangleShape_create();
    file->open_file_b = sfRectangleShape_create();
    file->new_file_b = sfRectangleShape_create();
    file->pos_file.y = 1.f;
    file->font = sfFont_createFromFile("assets/Monocraft.ttf");
    return file;
}

file_t *init_file(sfRenderWindow *w)
{
    file_t *file = malloc(sizeof(file_t));
    sfVector2u ws = sfRenderWindow_getSize(w);
    sfVector2f pos = {5.f, 10.f};
    sfVector2f size = {(float)(ws.x * 0.055), (float)(ws.y * 0.062)};
    sfColor colorback = sfColor_fromRGB(80, 80, 80);

    if (!file)
        return NULL;
    file->pos_file.x = (float)(ws.x * 0.0005);
    file = begin_file(file);
    if (file->font == NULL)
        return NULL;
    do_file_name(file, w);
    do_file_hitbox(file, w);
    do_file_back(file, w, colorback);
    sfRectangleShape_setOutlineThickness(file->save_file_b, 3.0);
    sfRectangleShape_setOutlineColor(file->save_file_h, sfBlack);
    set_back_and_text(file, pos, size, file->pos_file);
    return file;
}

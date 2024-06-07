/*
** EPITECH PROJECT, 2024
** help
** File description:
** help
*/

#include "../../include/paint.h"

void change_color(ui_t *ui)
{
    sfColor back = sfColor_fromRGB(80, 80, 80);

    if (ui->state_help == PRESSED_HELP) {
        sfRectangleShape_setFillColor(ui->help->help_visible,
            sfColor_fromRGB(230, 230, 230));
        sfText_setFillColor(ui->help->help_text, sfColor_fromRGB(35, 35, 35));
    }
    if (ui->state_help == RELEASED_HELP) {
        sfRectangleShape_setFillColor(ui->help->help_visible, back);
        sfText_setFillColor(ui->help->help_text, sfWhite);
    }
    if (ui->state_help == HOVER_HELP) {
        sfRectangleShape_setFillColor(ui->help->help_visible,
            sfColor_fromRGB(170, 170, 170));
        sfText_setFillColor(ui->help->help_text, sfWhite);
    }
}

void reedo_help(sfRenderWindow *w, ui_t *ui)
{
    sfVector2f size;
    sfVector2u windowsize = sfRenderWindow_getSize(w);

    ui->help->pos_help.y = 1.f;
    ui->help->pos_help.x = (float)(windowsize.x * 0.120);
    size.x = (float)(windowsize.x * 0.055);
    size.y = (float)(windowsize.y * 0.062);
    sfRectangleShape_setPosition(ui->help->help_hitbox, ui->help->pos_help);
    sfRectangleShape_setSize(ui->help->help_hitbox, size);
}

static void set_back_and_text(help_t *help, sfVector2f pos,
    sfVector2f size, sfVector2f pos_back)
{
    sfColor back = sfColor_fromRGB(80, 80, 80);

    sfRectangleShape_setSize(help->help_hitbox, size);
    sfRectangleShape_setOutlineThickness(help->help_hitbox, 3.0);
    sfRectangleShape_setOutlineColor(help->help_hitbox, sfBlack);
    sfRectangleShape_setFillColor(help->help_hitbox, sfTransparent);
    sfRectangleShape_setPosition(help->help_hitbox, pos_back);
    sfRectangleShape_setSize(help->help_visible, size);
    sfRectangleShape_setOutlineThickness(help->help_visible, 3.0);
    sfRectangleShape_setOutlineColor(help->help_visible, sfBlack);
    sfRectangleShape_setFillColor(help->help_visible, back);
    sfRectangleShape_setPosition(help->help_visible, pos_back);
    sfText_setPosition(help->help_text, pos);
    sfText_setString(help->help_text, "Help");
    sfText_setFont(help->help_text, help->font);
    sfText_setCharacterSize(help->help_text, 37);
    sfText_setFillColor(help->help_text, sfWhite);
    sfText_setFont(help->help_dest_text, help->font);
}

static help_t *init_dest(help_t *help, sfRenderWindow *w)
{
    sfVector2u windowsize = sfRenderWindow_getSize(w);
    sfVector2f size;
    sfVector2f pos;

    help->help_dest = sfRectangleShape_create();
    size.x = (float)(windowsize.x * 0.60);
    size.y = (float)(windowsize.y * 0.81);
    pos.y = (float)(windowsize.x * 0.1);
    pos.x = (float)(windowsize.x * 0.25);
    sfRectangleShape_setSize(help->help_dest, size);
    sfRectangleShape_setOutlineThickness(help->help_dest, 3.0);
    sfRectangleShape_setOutlineColor(help->help_dest, sfBlack);
    sfRectangleShape_setFillColor(help->help_dest,
        sfColor_fromRGB(80, 80, 80));
    sfRectangleShape_setPosition(help->help_dest, pos);
    return help;
}

help_t *init_text(help_t *help, sfRenderWindow *w)
{
    sfVector2u windowsize = sfRenderWindow_getSize(w);
    sfVector2f pos;
    char *text = "  Martin BONTE / Yanis MONTE\n\n- File [New/OPen/Save]";

    text = my_strcat(text, "\n- Edit [Color/Undo/Redo/\nMore Lenght");
    text = my_strcat(text, "/Less Lenght/\nPencil/Eraser]\n- Help [Help]");
    text = my_strcat(text, "\n^Z for Undo\n^Y for Redo\nWhen Open");
    text = my_strcat(text, " or Save clicked\nThe paint will be stop and ");
    text = my_strcat(text, "you\nmust write the file name in the\nTerminal");
    text = my_strcat(text, "\n\nThe Paint is stop when a\n[File/Edit/Help]");
    text = my_strcat(text, "is open\n");
    help->help_dest_text = sfText_create();
    pos.y = (float)(windowsize.x * 0.1);
    pos.x = (float)(windowsize.x * 0.275);
    sfText_setPosition(help->help_dest_text, pos);
    sfText_setString(help->help_dest_text, text);
    sfText_setCharacterSize(help->help_dest_text, 50);
    sfText_setFillColor(help->help_dest_text, sfWhite);
    return help;
}

help_t *init_help(sfRenderWindow *w)
{
    help_t *help = malloc(sizeof(help_t));
    sfVector2f pos = {236.f, 10.f};
    sfVector2u wsize = sfRenderWindow_getSize(w);
    sfVector2f size = {(float)(wsize.x * 0.055), (float)(wsize.y * 0.062)};

    if (!help)
        return NULL;
    help = init_dest(help, w);
    help = init_text(help, w);
    help->pos_help.y = 1.f;
    help->pos_help.x = (float)(wsize.x * 0.120);
    help->font = sfFont_createFromFile("assets/Monocraft.ttf");
    if (help->font == NULL)
        return NULL;
    help->help_text = sfText_create();
    help->help_hitbox = sfRectangleShape_create();
    help->help_visible = sfRectangleShape_create();
    set_back_and_text(help, pos, size, help->pos_help);
    return help;
}

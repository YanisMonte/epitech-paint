/*
** EPITECH PROJECT, 2024
** interface
** File description:
** interface
*/

#include "../../include/paint.h"


static sfBool is_hover_help(ui_t *ui, sfFloatRect te, sfMouseMoveEvent *mm)
{
    if (ui->state_help == PRESSED_HELP)
        return sfFalse;
    if (sfFloatRect_contains(&te, mm->x, mm->y)) {
        ui->state_help = HOVER_HELP;
        return sfTrue;
    } else {
        ui->state_help = RELEASED_HELP;
    }
    return sfFalse;
}

sfBool is_clicked(ui_t *ui, sfMouseButtonEvent *mb)
{
    sfFloatRect th = sfRectangleShape_getGlobalBounds(ui->help->help_hitbox);
    sfFloatRect te = sfRectangleShape_getGlobalBounds(ui->edit->edit_hitbox);
    sfFloatRect tf = sfRectangleShape_getGlobalBounds(ui->file->file_hitbox);

    if (is_cliked_help(ui, th, mb) == sfTrue)
        return sfTrue;
    if (is_cliked_edit(ui, te, mb) == sfTrue)
        return sfTrue;
    if (is_clicked_file(ui, tf, mb) == sfTrue)
        return sfTrue;
    return sfFalse;
}

sfBool is_hover(ui_t *ui, sfMouseMoveEvent *mm)
{
    sfFloatRect th = sfRectangleShape_getGlobalBounds(ui->help->help_hitbox);
    sfFloatRect te = sfRectangleShape_getGlobalBounds(ui->edit->edit_hitbox);
    sfFloatRect tf = sfRectangleShape_getGlobalBounds(ui->file->file_hitbox);

    if (is_hover_help(ui, th, mm) == sfTrue)
        return sfTrue;
    if (is_hover_edit(ui, te, mm) == sfTrue)
        return sfTrue;
    if (is_hover_file(ui, tf, mm) == sfTrue)
        return sfTrue;
    return sfFalse;
}

void init_back(ui_t *ui, sfRenderWindow *w)
{
    sfVector2f pos = {0.f, 0.f};
    sfVector2u windowsize = sfRenderWindow_getSize(w);

    ui->size_back.x = (float)windowsize.x;
    ui->size_back.y = (float)(windowsize.y * BORDER_BACKGROUND);
    ui->back = sfRectangleShape_create();
    sfRectangleShape_setPosition(ui->back, pos);
    sfRectangleShape_setSize(ui->back, ui->size_back);
    sfRectangleShape_setOutlineThickness(ui->back, 1.0);
    sfRectangleShape_setOutlineColor(ui->back, sfBlack);
    sfRectangleShape_setFillColor(ui->back, sfColor_fromRGB(50, 50, 50));
}

ui_t *init_ui(sfRenderWindow *w)
{
    ui_t *ui;

    if (w == NULL)
        return (NULL);
    ui = malloc(sizeof(ui_t));
    init_back(ui, w);
    ui->help = init_help(w);
    ui->edit = init_edit(w);
    ui->file = init_file(w);
    ui->state_edit = NONE_EDIT;
    ui->state_file = NONE_FILE;
    ui->state_help = NONE_HELP;
    ui->is_clicked = is_clicked;
    ui->is_hover = is_hover;
    if (!ui->help || !ui->edit || !ui->file)
        return NULL;
    return ui;
}

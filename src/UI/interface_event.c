/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** interface_event
*/

#include "../../include/paint.h"

sfBool is_hover_edit(ui_t *ui, sfFloatRect temp_edit, sfMouseMoveEvent *mm)
{
    if (ui->state_edit == PRESSED_EDIT)
        return sfFalse;
    if (sfFloatRect_contains(&temp_edit, mm->x, mm->y)) {
        ui->state_edit = HOVER_EDIT;
        return sfTrue;
    } else {
        ui->state_edit = RELEASED_EDIT;
    }
    return sfFalse;
}

sfBool is_hover_file(ui_t *ui, sfFloatRect temp_file, sfMouseMoveEvent *mm)
{
    if (ui->state_file == PRESSED_FILE)
        return sfFalse;
    if (sfFloatRect_contains(&temp_file, mm->x, mm->y)) {
        ui->state_file = HOVER_FILE;
        return sfTrue;
    } else {
        ui->state_file = RELEASED_FILE;
    }
    return sfFalse;
}

sfBool is_clicked_file(ui_t *ui, sfFloatRect tf, sfMouseButtonEvent *mb)
{
    if (sfFloatRect_contains(&tf, mb->x, mb->y)) {
        if (ui->state_file == PRESSED_FILE) {
            ui->state_file = RELEASED_FILE;
            return sfTrue;
        }
        ui->state_edit = RELEASED_EDIT;
        ui->state_help = RELEASED_HELP;
        ui->state_file = PRESSED_FILE;
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_cliked_edit(ui_t *ui, sfFloatRect temp_edit, sfMouseButtonEvent *mb)
{
    if (sfFloatRect_contains(&temp_edit, mb->x, mb->y)) {
        if (ui->state_edit == PRESSED_EDIT) {
            ui->state_edit = RELEASED_EDIT;
            return sfTrue;
        }
        ui->state_file = RELEASED_FILE;
        ui->state_help = RELEASED_HELP;
        ui->state_edit = PRESSED_EDIT;
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_cliked_help(ui_t *ui, sfFloatRect temp_help, sfMouseButtonEvent *mb)
{
    if (sfFloatRect_contains(&temp_help, mb->x, mb->y)) {
        if (ui->state_help == PRESSED_HELP) {
            ui->state_help = RELEASED_HELP;
            return sfTrue;
        }
        ui->state_edit = RELEASED_EDIT;
        ui->state_file = RELEASED_FILE;
        ui->state_help = PRESSED_HELP;
        return sfTrue;
    }
    return sfFalse;
}

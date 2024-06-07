/*
** EPITECH PROJECT, 2024
** free
** File description:
** free
*/

#include "../include/paint.h"

void free_tools(ui_t *ui)
{
    sfTexture_destroy(ui->edit->tools->ab_texture);
    sfTexture_destroy(ui->edit->tools->ar_texture);
    sfTexture_destroy(ui->edit->tools->eraser_texture);
    sfTexture_destroy(ui->edit->tools->pencil_texture);
    sfTexture_destroy(ui->edit->tools->rgb_texture);
    sfRectangleShape_destroy(ui->edit->tools->ab_hb);
    sfRectangleShape_destroy(ui->edit->tools->ar_hb);
    sfRectangleShape_destroy(ui->edit->tools->back);
    sfRectangleShape_destroy(ui->edit->tools->eh);
    sfRectangleShape_destroy(ui->edit->tools->hl);
    sfRectangleShape_destroy(ui->edit->tools->hm);
    sfRectangleShape_destroy(ui->edit->tools->ph);
    sfSprite_destroy(ui->edit->tools->rgb_sprite);
    sfSprite_destroy(ui->edit->tools->arrowr_sprite);
    sfSprite_destroy(ui->edit->tools->arrowback_sprite);
    sfSprite_destroy(ui->edit->tools->eraser);
    sfSprite_destroy(ui->edit->tools->pencil);
    sfText_destroy(ui->edit->tools->less);
    sfText_destroy(ui->edit->tools->more);
    sfFont_destroy(ui->edit->tools->font);
}

void free_help(ui_t *ui)
{
    sfRectangleShape_destroy(ui->help->help_visible);
    sfRectangleShape_destroy(ui->help->help_hitbox);
    sfFont_destroy(ui->help->font);
    sfText_destroy(ui->help->help_text);
    sfRectangleShape_destroy(ui->help->help_dest);
    sfText_destroy(ui->help->help_dest_text);
    free(ui->help);
}

void free_edit(ui_t *ui)
{
    free_tools(ui);
    free(ui->edit->tools);
    free(ui->edit);
}

void free_file(ui_t *ui)
{
    sfRectangleShape_destroy(ui->file->file_visible);
    sfRectangleShape_destroy(ui->file->file_hitbox);
    sfFont_destroy(ui->file->font);
    sfText_destroy(ui->file->file_text);
    free(ui->file);
}

void free_them_all(ui_t *ui)
{
    sfText_destroy(ui->file->open_file);
    sfText_destroy(ui->file->save_file);
    sfText_destroy(ui->file->new_file);
    sfText_destroy(ui->edit->edit_text);
    sfRectangleShape_destroy(ui->back);
    sfRectangleShape_destroy(ui->file->new_file_h);
    sfRectangleShape_destroy(ui->edit->edit_visible);
    sfRectangleShape_destroy(ui->edit->edit_hitbox);
    sfRectangleShape_destroy(ui->file->new_file_b);
    sfRectangleShape_destroy(ui->file->open_file_b);
    sfRectangleShape_destroy(ui->file->save_file_b);
    sfRectangleShape_destroy(ui->file->save_file_h);
    sfRectangleShape_destroy(ui->file->open_file_h);
    sfFont_destroy(ui->edit->font);
    free_help(ui);
    free_edit(ui);
    free_file(ui);
    free(ui);
}

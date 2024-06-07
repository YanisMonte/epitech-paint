/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint
*/

#include "../include/paint.h"

static void print_edit(sfRenderWindow *w, ui_t *ui)
{
    sfRenderWindow_drawRectangleShape(w, ui->edit->tools->back, NULL);
    sfRenderWindow_drawSprite(w, ui->edit->tools->rgb_sprite, NULL);
    sfRenderWindow_drawSprite(w, ui->edit->tools->arrowback_sprite, NULL);
    sfRenderWindow_drawSprite(w, ui->edit->tools->arrowr_sprite, NULL);
    sfRenderWindow_drawSprite(w, ui->edit->tools->pencil, NULL);
    sfRenderWindow_drawSprite(w, ui->edit->tools->eraser, NULL);
    sfRenderWindow_drawText(w, ui->edit->tools->less, NULL);
    sfRenderWindow_drawText(w, ui->edit->tools->more, NULL);
}

static void print_global_button(sfRenderWindow *w, ui_t *ui)
{
    sfRenderWindow_drawRectangleShape(w, ui->back, NULL);
    sfRenderWindow_drawRectangleShape(w, ui->help->help_visible, NULL);
    sfRenderWindow_drawText(w, ui->help->help_text, NULL);
    sfRenderWindow_drawRectangleShape(w, ui->edit->edit_visible, NULL);
    sfRenderWindow_drawText(w, ui->edit->edit_text, NULL);
    sfRenderWindow_drawRectangleShape(w, ui->file->file_visible, NULL);
    sfRenderWindow_drawText(w, ui->file->file_text, NULL);
}

void draw_these_buttons(sfRenderWindow *w, ui_t *ui)
{
    print_global_button(w, ui);
    if (ui->state_file == PRESSED_FILE) {
        sfRenderWindow_drawRectangleShape(w, ui->file->open_file_b, NULL);
        sfRenderWindow_drawRectangleShape(w, ui->file->new_file_b, NULL);
        sfRenderWindow_drawRectangleShape(w, ui->file->save_file_b, NULL);
        sfRenderWindow_drawText(w, ui->file->new_file, NULL);
        sfRenderWindow_drawText(w, ui->file->open_file, NULL);
        sfRenderWindow_drawText(w, ui->file->save_file, NULL);
    }
    if (ui->state_help == PRESSED_HELP) {
        sfRenderWindow_drawRectangleShape(w, ui->help->help_dest, NULL);
        sfRenderWindow_drawText(w, ui->help->help_dest_text, NULL);
    }
    if (ui->state_edit == PRESSED_EDIT) {
        print_edit(w, ui);
    }
}

int my_paint(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfUint32 s = sfResize | sfClose;
    sfRenderWindow* window = sfRenderWindow_create(mode, "My_paint", s, NULL);
    ui_t *ui = init_ui(window);
    graphic_t *graphic = init_graphic(window);

    if (!window || !ui || !graphic)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        display_layer(graphic, window);
        analyse_events(window, ui, graphic);
        draw_these_buttons(window, ui);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    free_them_all(ui);
    free_img(&(graphic->layer->been));
    free_graphic(graphic);
    return 0;
}

int tty_handling(char **env)
{
    for (int i = 0; env[i] != 0; i++) {
        if (env[i][0] == 'D' && env[i][1] == 'I')
            return 1;
    }
    return 84;
}

int main(__attribute__((unused))int argc,
    __attribute__((unused))char **argv, char **env)
{
    if (tty_handling(env) == 84)
        return 84;
    my_paint();
    return 0;
}

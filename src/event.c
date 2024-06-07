/*
** EPITECH PROJECT, 2024
** event
** File description:
** event
*/
#include "../include/paint.h"

void event_file(ui_t *ui, sfMouseButtonEvent *mb, graphic_t *gra,
    sfRenderWindow *w)
{
    sfFloatRect open = sfRectangleShape_getGlobalBounds(ui->file->open_file_h);
    sfFloatRect new = sfRectangleShape_getGlobalBounds(ui->file->new_file_h);
    sfFloatRect s_r = sfRectangleShape_getGlobalBounds(ui->file->save_file_h);

    if (sfFloatRect_contains(&new, mb->x, mb->y)) {
        free_layer(&(gra->layer));
        add_layer(&(gra->layer));
        sfSprite_destroy(gra->file_to_load);
        gra->file_to_load = NULL;
        return;
    }
    if (sfFloatRect_contains(&open, mb->x, mb->y)) {
        load_file(gra);
        return;
    }
    if (sfFloatRect_contains(&s_r, mb->x, mb->y)) {
        save(w);
        return;
    }
}

static void event_tools(ui_t *ui, sfMouseButtonEvent *mb, graphic_t *gra)
{
    sfFloatRect m = sfRectangleShape_getGlobalBounds(ui->edit->tools->hm);
    sfFloatRect less = sfRectangleShape_getGlobalBounds(ui->edit->tools->hl);
    sfFloatRect era = sfRectangleShape_getGlobalBounds(ui->edit->tools->eh);
    sfFloatRect pen = sfRectangleShape_getGlobalBounds(ui->edit->tools->ph);

    if (sfFloatRect_contains(&m, mb->x, mb->y)) {
        gra->size += 3;
        return;
    }
    if (sfFloatRect_contains(&less, mb->x, mb->y)) {
        gra->size -= 3;
        return;
    }
    if (sfFloatRect_contains(&era, mb->x, mb->y)) {
        gra->lastcolor = gra->color;
        gra->color = sfColor_fromRGB(255, 255, 255);
        return;
    }
    if (sfFloatRect_contains(&pen, mb->x, mb->y))
        gra->color = gra->lastcolor;
}

static void event_arrow(ui_t *ui, sfMouseButtonEvent *mb, graphic_t *gra)
{
    sfFloatRect ab = sfRectangleShape_getGlobalBounds(ui->edit->tools->ab_hb);
    sfFloatRect ar = sfRectangleShape_getGlobalBounds(ui->edit->tools->ar_hb);

    if (sfFloatRect_contains(&ab, mb->x, mb->y)) {
        undo(&(gra->layer));
        return;
    }
    if (sfFloatRect_contains(&ar, mb->x, mb->y)) {
        redo(&(gra->layer));
        return;
    }
}

static void event_write(sfRenderWindow *w, sfEvent evt, graphic_t *gra)
{
    if (evt.type == sfEvtMouseButtonPressed) {
        free_img(&(gra->layer->been));
        add_img(&(gra->layer->img));
        draw(w, &(gra->layer->img->pixel), gra);
        add_line_between_point(&(gra->layer->img), gra->size, gra->color);
    } else if (evt.type == sfEvtMouseMoved) {
        draw(w, &(gra->layer->img->pixel), gra);
        add_line_between_point(&(gra->layer->img), gra->size, gra->color);
    }
}

static void event_key_board(graphic_t *graphic)
{
    if (sfKeyboard_isKeyPressed(sfKeyLControl) &&
    sfKeyboard_isKeyPressed(sfKeyZ) && graphic->is_pressed == 0) {
        graphic->is_pressed = 1;
        undo(&(graphic->layer));
    } else if (sfKeyboard_isKeyPressed(sfKeyLControl) &&
    sfKeyboard_isKeyPressed(sfKeyY) && graphic->is_pressed == 0) {
        graphic->is_pressed = 1;
        redo(&(graphic->layer));
    } else
        graphic->is_pressed = 0;
}

static void reedo_all(sfRenderWindow *window, ui_t *ui, sfEvent evt)
{
    if (evt.type == sfEvtResized) {
        reedo_help(window, ui);
        reedo_edit(window, ui);
        reedo_file(window, ui);
        reedo_arrow(window, ui);
        reedo_pen_and_eraser(window, ui);
        reedo_size(window, ui);
    }
}

void analyse_events(sfRenderWindow *window, ui_t *ui, graphic_t *graphic)
{
    sfEvent evt;

    while (sfRenderWindow_pollEvent(window, &evt)) {
        is_open(window, evt);
        event_mouse(evt, ui, graphic, window);
        reedo_all(window, ui, evt);
        if (sfMouse_isButtonPressed(sfMouseLeft)
            && ui->state_edit != PRESSED_EDIT && ui->state_file != PRESSED_FILE
            && ui->state_help != PRESSED_HELP)
            event_write(window, evt, graphic);
        event_key_board(graphic);
        if (sfKeyboard_isKeyPressed(sfKeyComma))
            save(window);
        if (sfKeyboard_isKeyPressed(sfKeyDelete))
            load_file(graphic);
    }
}

void event_mouse(sfEvent even, ui_t *ui, graphic_t *gra, sfRenderWindow *w)
{
    if (even.type == sfEvtMouseMoved)
        ui->is_hover(ui, &even.mouseMove);
    if (even.type == sfEvtMouseButtonPressed) {
        ui->is_clicked(ui, &even.mouseButton);
        if (ui->state_edit == PRESSED_EDIT) {
            find_color(ui, &even.mouseButton, gra, w);
            event_arrow(ui, &even.mouseButton, gra);
            event_tools(ui, &even.mouseButton, gra);
        }
        if (ui->state_file == PRESSED_FILE)
            event_file(ui, &even.mouseButton, gra, w);
    }
    change_color(ui);
    change_color_edit(ui);
    change_color_file(ui);
}

int is_open(sfRenderWindow* W, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(W);
    return 0;
}

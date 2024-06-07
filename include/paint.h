/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-yanis.monte
** File description:
** paint.h
*/

#ifndef PAINT_H
    #define PAINT_H

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include "lib.h"
    #include <SFML/Audio.h>
    #include <SFML/System.h>

    #define TABX 1920
    #define TABY 1080
    #define BORDER_BACKGROUND 0.065

typedef struct pixel_s {
    sfCircleShape *shape;
    struct pixel_s *next;
} pixel_t;

typedef struct img_s {
    pixel_t *pixel;
    struct img_s *next;
} img_t;

typedef struct layer_s {
    img_t *img;
    img_t *been;
    struct layer_s *next;
} layer_t;

typedef struct graphic_s {
    layer_t *layer;
    int is_pressed;
    sfColor color;
    int size;
    sfVector2f start_window_size;
    sfColor lastcolor;
    sfSprite *file_to_load;
} graphic_t;

/* Begin of UI */

enum state_help {
    NONE_HELP = 0,
    HOVER_HELP,
    PRESSED_HELP,
    RELEASED_HELP,
};

enum state_file {
    NONE_FILE = 0,
    HOVER_FILE,
    PRESSED_FILE,
    RELEASED_FILE,
};

enum state_edit {
    NONE_EDIT = 0,
    HOVER_EDIT,
    PRESSED_EDIT,
    RELEASED_EDIT,
};

typedef struct file_s {
    sfVector2f pos_file;
    sfRectangleShape *file_visible;
    sfRectangleShape *file_hitbox;
    sfFont *font;
    sfText *file_text;
    sfText *new_file;
    sfText *open_file;
    sfText *save_file;
    sfRectangleShape *new_file_h;
    sfRectangleShape *open_file_h;
    sfRectangleShape *save_file_h;
    sfRectangleShape *new_file_b;
    sfRectangleShape *open_file_b;
    sfRectangleShape *save_file_b;
} file_t;

typedef struct tools_s {
    sfTexture *rgb_texture;
    sfTexture *ab_texture;
    sfTexture *ar_texture;
    sfTexture *pencil_texture;
    sfTexture *eraser_texture;
    sfRectangleShape *back;
    sfRectangleShape *ar_hb;
    sfRectangleShape *eh;
    sfRectangleShape *ph;
    sfRectangleShape *ab_hb;
    sfRectangleShape *hl;
    sfRectangleShape *hm;
    sfSprite *rgb_sprite;
    sfSprite *arrowback_sprite;
    sfSprite *arrowr_sprite;
    sfSprite *pencil;
    sfSprite *eraser;
    sfText *less;
    sfText *more;
    sfFont *font;
}tools_t;

typedef struct edit_s {
    sfVector2f pos_edit;
    sfRectangleShape *edit_visible;
    sfRectangleShape *edit_hitbox;
    sfFont *font;
    sfText *edit_text;
    tools_t *tools;
} edit_t;

typedef struct help_s {
    sfVector2f pos_help;
    sfRectangleShape *help_visible;
    sfRectangleShape *help_hitbox;
    sfFont *font;
    sfText *help_text;
    sfRectangleShape *help_dest;
    sfText *help_dest_text;
} help_t;

typedef struct ui_s {
    sfRectangleShape *back;
    sfVector2f size_back;
    help_t *help;
    edit_t *edit;
    file_t *file;
    enum state_help state_help;
    enum state_edit state_edit;
    enum state_file state_file;
    sfBool(*is_clicked) (struct ui_s *, sfMouseButtonEvent *);
    sfBool(*is_hover) (struct ui_s *, sfMouseMoveEvent *);
} ui_t;

void free_them_all(ui_t *ui);
ui_t *init_ui(sfRenderWindow *w);
void change_color(ui_t *ui);
help_t *init_help(sfRenderWindow *w);
void reedo_help(sfRenderWindow *w, ui_t *ui);
edit_t *init_edit(sfRenderWindow *w);
void change_color_edit(ui_t *ui);
void reedo_edit(sfRenderWindow *w, ui_t *ui);
file_t *init_file(sfRenderWindow *w);
void change_color_file(ui_t *ui);
void reedo_file(sfRenderWindow *w, ui_t *ui);
void reedo_arrow(sfRenderWindow *w, ui_t *ui);
void reedo_pen_and_eraser(sfRenderWindow *w, ui_t *ui);
void reedo_size(sfRenderWindow *w, ui_t *ui);

sfBool is_hover_edit(ui_t *ui, sfFloatRect temp_edit, sfMouseMoveEvent *mm);
sfBool is_hover_file(ui_t *ui, sfFloatRect temp_file, sfMouseMoveEvent *mm);
sfBool is_clicked_file(ui_t *ui, sfFloatRect tp, sfMouseButtonEvent *mb);
sfBool is_cliked_edit(ui_t *ui, sfFloatRect temp_edit, sfMouseButtonEvent *mb);
sfBool is_cliked_help(ui_t *ui, sfFloatRect temp_help, sfMouseButtonEvent *mb);

tools_t *init_tools(sfRenderWindow *w);
tools_t *init_pen_erase(tools_t *tools, sfRenderWindow *w);
void find_color(ui_t *ui, sfMouseButtonEvent *mb, graphic_t *graphic,
    sfRenderWindow *w);
/* End of UI*/

void add_img(img_t **img);
void free_img(img_t **img);
void undo(layer_t **layer);
void redo(layer_t **layer);
void add_layer(layer_t **layer);
void free_graphic(graphic_t *graphic);
void display_layer(graphic_t *graphic, sfRenderWindow *window);
void draw(sfRenderWindow *window, pixel_t **pixel, graphic_t *gra);

void save(sfRenderWindow *window);
void load_file(graphic_t *graphic);

void draw_these_buttons(sfRenderWindow *w, ui_t *ui);
void add_line_between_point(img_t **img, int size, sfColor color);
void analyse_events(sfRenderWindow *window, ui_t *ui, graphic_t *graphic);

int is_open(sfRenderWindow* W, sfEvent event);
void event_mouse(sfEvent even, ui_t *ui, graphic_t *gra, sfRenderWindow *w);
void event_file(ui_t *ui, sfMouseButtonEvent *mb, graphic_t *gra,
    sfRenderWindow *w);
graphic_t *init_graphic(sfRenderWindow *window);
void free_layer(layer_t **layer);

#endif

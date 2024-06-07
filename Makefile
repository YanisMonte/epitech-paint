##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC		= 	lib/mini_printf.c 				\
			lib/my_getnbr.c 				\
			lib/my_put_nbr.c 				\
			lib/my_putchar.c 				\
			lib/my_putstr.c 				\
			lib/my_str_to_word_array.c 		\
			lib/my_strcpy.c 				\
			lib/my_strdup.c 				\
			lib/my_strncpy.c 				\
			lib/my_strlen.c 				\
			lib/my_strcat.c 				\
			lib/my_str_realloc.c 			\
											\
			src/UI/help.c 					\
			src/UI/interface.c 				\
			src/UI/edit.c 					\
			src/UI/file.c 					\
			src/UI/tools.c 					\
			src/UI/interface_event.c 		\
			src/UI/choose_color.c 			\
			src/UI/pencil.c 				\
											\
			src/event.c 					\
			src/free.c						\
			src/my_paint.c 					\
			src/layer_manager.c 			\
			src/display_layer.c 			\
			src/undo_redo.c 				\
			src/free_linked_list.c 			\
			src/add_line_between_point.c 	\
											\
			src/save.c 						\
			src/load.c 						\


OBJ 	= 	$(SRC:.c=.o)

NAME    =   my_paint

CFLAGS 	= 	-Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ) -lmy
	gcc -o $(NAME) $(OBJ) -lm -lcsfml-system -lcsfml-graphics -lcsfml-window

clean:
	@echo "Cleaning..."
	@rm -f $(OBJ)
	@echo "Clean completed."

fclean: clean
	@echo "Full Cleaning..."
	@rm -f $(NAME)
	@echo "Full Clean completed."

re:    fclean all

debug: $(OBJ)
	gcc -o $(NAME) $(OBJ) -g

##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =	my_hunter.c	\
			sprite_param.c	\
			events.c	\
			create_sprite.c	\
			create_sprite2.c	\
			set_sprite.c	\
			sprite_animation.c	\
			sprite_animation2.c	\
			destroy_variable.c	\
			create_text.c	\
			add_to_struct.c


OBJ     =	$(SRC:.c=.o)

NAME    =	my_hunter

CPPFLAGS	=	-I./include

CFLAGS	=	-Wall -Wextra -g3

LDFLAGS	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio\
	-L./lib/my -lmy

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my libmy
	make -C ./lib/my clean
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re

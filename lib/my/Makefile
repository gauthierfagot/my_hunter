##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =	int_to_str.c	\
			my_putchar.c	\
			my_putstr.c	\

OBJ     =	$(SRC:.c=.o)

NAME    =	libmy

CPPFLAGS	=	-I./include

all:    $(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME).a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME).a

re:     fclean all

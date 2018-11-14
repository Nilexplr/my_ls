##
## EPITECH PROJECT, 2017
## My_popup_2017
## File description:
## Makefile
##

SRC	=	./src/my_ls.c		\
		./src/linked_list.c	\
		./src/parsing.c	\
		./src/inside_folder.c	\
		./src/display_flag.c	\
		./src/option_rmaj.c	\
		./src/run_flag.c	\
		./src/date_function.c	\
		./src/find_total.c	\
		./src/my_sort_word.c	\
		./src/option_r.c	\
		./src/option_d.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -W -Wall -Wextra -Werror --pedantic

NAME	=	my_ls

LIB_DIR	=	./lib/my

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJ) -L$(LIB_DIR) -lmy $(CFLAGS)
		rm $(OBJ)

clean:
	rm -f $(OBJ) $(LIB_OBJ) *.gc*

fclean:	clean
	rm -f $(NAME) $(UT)

re:	fclean all

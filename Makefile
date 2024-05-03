##
## EPITECH PROJECT, 2023
## lola
## File description:
## lala
##

SRC	=	main.c	\
		error_handling.c \
		get_tab_from_file.c \
		my_str_to_word_array_condition.c \
		init_struct.c \
		my_bubble_sort.c

OBJ	=	$(SRC:.c=.o)

NAME	=	duo

LIBSHELL =	-L./include/



all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L -lmy $(LIBSHELL)

clean:
	rm $(OBJ)

fclean:
	rm $(NAME) -f
	rm $(OBJ) -f

re:	fclean all

.PHONY : all clean fclean re

##
## EPITECH PROJECT, 2024
## make
## File description:
## make
##

NAME	=	42sh

SRC		=	main.c									\
			com_alias.c								\
			unalias.c								\
			alias.c									\
			alias_cmp.c								\
			execute_alias.c							\
			strstr.c								\
			my_cd.c									\
			scripts.c								\
			exe.c									\
			my_env.c								\
			globbings.c								\
			next_my_env.c							\
			choose_env_print.c						\
			next_pipe.c								\
			history/history.c						\
			linked_list_management/delete_in_list.c	\
			linked_list_management/destroy_list.c	\
			linked_list_management/display_list.c	\
			linked_list_management/push_to_list.c 	\
			next_my_get_line.c						\
			my_get_line.c							\
			next_exec.c

OBJ		=	$(SRC:.c=.o)

DEBUGFLAGS	=	--leak-check=full --show-leak-kinds=all -s

OTHERDEBUGFLAGS	=	--track-origins=yes --log-file="data"

all:	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(SRC) -L. -lmy

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all

run: re
	./$(NAME)
	make fclean

debug: fclean
	make -C lib/my
	gcc -g3 -o $(NAME) $(SRC) -L. -lmy

valgrind:
	valgrind $(DEBUGFLAGS) $(OTHERDEBUGFLAGS) ./$(NAME)

.PHONY: all clean fclean re run

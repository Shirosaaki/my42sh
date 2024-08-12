##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME	=	../../libmy.a

SRC	=	get_color.c 				\
		my_compute_power_rec.c 		\
		my_compute_square_root.c 	\
		my_find_prime_sup.c 		\
		my_getnbr.c 				\
		my_isneg.c 					\
		my_is_prime.c 				\
		my_putchar.c 				\
		my_putnbr.c 				\
		my_putstr.c 				\
		my_showmem.c 				\
		my_showstr.c 				\
		my_sort_int_array.c 		\
		my_strcapitalize.c 			\
		my_strcat.c 				\
		my_strcmp.c 				\
		my_str_is_alpha.c 			\
		my_str_islower.c 			\
		my_str_isnum.c 				\
		my_str_isprintable.c 		\
		my_str_isupper.c 			\
		my_strlen.c					\
		my_strlowcase.c				\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strpy.c					\
		my_swap.c					\
		rm_null_element.c			\
		my_str_to_word_array.c		\
		my_tablen.c					\
		rm_first_tab.c				\
		rm_lastn.c					\
		my_put_tab.c				\
		my_strdup.c					\
		my_strndup.c				\
		my_strisalpha.c				\
		my_find_c.c

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

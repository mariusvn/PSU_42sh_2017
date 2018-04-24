##
## EPITECH PROJECT, 2017
## libmy compilator
## File description:
## compiles a libmy.a
##

SRC	=	my_compute_power_rec.c\
		my_compute_square_root.c\
		my_find_prime_sup.c\
		my_getnbr.c\
		my_isneg.c\
		my_is_prime.c\
		my_putchar.c\
		my_put_nbr.c\
		my_putstr.c\
		my_revstr.c\
		my_showstr.c\
		my_show_word_array.c\
		my_sort_int_array.c\
		my_strcapitalize.c\
		my_strcat.c\
		my_strcmp.c\
		my_strcpy.c\
		my_strdup.c\
		my_str_isalpha.c\
		my_str_islower.c\
		my_str_isnum.c\
		my_str_isprintable.c\
		my_str_isupper.c\
		my_strlen.c\
		my_strlowcase.c\
		my_strncat.c\
		my_strncmp.c\
		my_strncpy.c\
		my_strstr.c\
		my_strupcase.c\
		my_swap.c\
		my_putnbr_base.c\
		my_is_digit.c\
		my_putlong_base.c\
		printf.c\
		flags_a.c\
		flags_b.c\
		flags_c.c\
		my_split.c\
		get_next_line.c

OBJ	=	$(SRC:%.c=%.o)

NAME	=	libmy.a

NAMEB	=	my

HEADER	=	my.h

FINAL	=	$(NAME)

RED	=	\033[31m
YELLOW	=	\033[93m
BLUE	=	\033[34m
GREEN	=	\033[32m
STDCLR	=	\033[0m

all:	$(NAME) cph

$(NAME): $(OBJ)
	@echo "$(YELLOW)\tBuilding $(NAMEB) library $(STDCLR)"
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@echo "$(YELLOW)\tCompiling $^"
	@gcc -c $^ -o $@ -g -I ./

clean:
	@echo "$(YELLOW)\tCleaning $(NAMEB) library files $(STDCLR)"
	@rm -f *.o
	@rm -rf ../../include/$(HEADER)

endclean:
	@echo "$(YELLOW)\tRemoving $(NAMEB) objects files $(STDCLR)"
	@rm -f *.o

fclean:	clean
	@rm -f $(FINAL)

rmh:
	@rm -f ../../include/$(HEADER)

cph:	rmh
	@cp $(HEADER) ../../include/$(HEADER)

re:	fclean all

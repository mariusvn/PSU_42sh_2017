##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

SRC		=	$(wildcard src/*/*.c)	\
			$(wildcard src/*.c)

NAME	=	mysh

CFLAGS	=	-I include -L lib/my -lmy -g -W -Wall -Wextra -L lib/linkify \
		-Wno-unused-parameter -Wno-unused-variable -llinkify

OBJ		=	$(SRC:%.c=%.o)

RED	=	\033[31m
YELLOW	=	\033[93m
BLUE	=	\033[34m
GREEN	=	\033[32m
STDCLR	=	\033[0m

all:	$(NAME)


$(NAME):	$(OBJ)
	@echo "$(YELLOW)\tBuilding $(NAME) executable$(STDCLR)"
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

%.o: %.c
	@cd lib/my && $(MAKE) --no-print-directory
	@cd lib/linkify && $(MAKE) --no-print-directory
	@gcc -c $^ -o $@ $(CFLAGS)

clean:
	@echo "$(YELLOW)\tCleaning directory$(STDCLR)"
	@cd lib/my && $(MAKE) clean --no-print-directory
	@cd lib/linkify && $(MAKE) clean --no-print-directory
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(YELLOW)\tFcleaning directory$(STDCLR)"
	@cd lib/my && $(MAKE) fclean --no-print-directory
	@cd lib/linkify && $(MAKE) fclean --no-print-directory
	@rm -rf $(NAME)

re: fclean all

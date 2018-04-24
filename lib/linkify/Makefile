##
## EPITECH PROJECT, 2017
## libmy compilator
## File description:
## compiles a libmy.a
##

SRC	=	linkify.c		\
		linkify_b.c

OBJ	=	$(SRC:%.c=%.o)

NAME	=	liblinkify.a

NAMEB	=	linkify

HEADER	=	linkify.h

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

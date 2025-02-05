##
## EPITECH PROJECT, 2024
## makefile
## File description:
## for compilation
##

SRC	=	src/main.c \
		src/get_ressources.c \

OBJ	=	$(SRC:.c=.o)

EXE_NAME	=	duck_hunt

CFLAGS	+=	-Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system

all:	$(EXE_NAME)

$(EXE_NAME): $(OBJ)
	gcc -o $(EXE_NAME) $(OBJ) $(CFLAGS)

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(EXE_NAME)
	rm -f src/*.o

re : fclean all

##
## EPITECH PROJECT, 2024
## makefile
## File description:
## for compilation
##

SRC	=	src/main.c \
		src/get_ressources.c \
		src/mouse.c \
		src/sprite.c \
		src/display.c \
		src/game_state.c \
		src/clean.c \
		src/crosshair.c \
		src/animate.c \

OBJ	=	$(SRC:.c=.o)

EXE_NAME	=	my_hunter

CFLAGS	+=	-Wall -Wextra
CSFMLFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(EXE_NAME)

$(EXE_NAME): $(OBJ)
	gcc -o $(EXE_NAME) $(OBJ) $(CFLAGS) $(CSFMLFLAGS)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(EXE_NAME)
	rm -f src/*.o

re:	fclean all

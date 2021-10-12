##
## EPITECH PROJECT, 2017
## makefile
## File description:
## same
##

SRC	=	./src/beer.c		\
		./src/beer2.c		\
		./src/check_env.c	\
		./src/check_page.c	\
		./src/credits.c		\
		./src/destroy.c		\
		./src/dwarfs.c		\
		./src/end_game.c	\
		./src/event.c		\
		./src/event_practice.c	\
		./src/event_practice2.c	\
		./src/font_set_page.c	\
		./src/font_set_page2.c	\
		./src/home.c		\
		./src/humans.c		\
		./src/init.c		\
		./src/init2.c		\
		./src/init3.c		\
		./src/inventory.c	\
		./src/main.c		\
		./src/main_page.c	\
		./src/my_strcmp.c	\
		./src/my_putstr.c	\
		./src/night_elf.c	\
		./src/option.c		\
		./src/orcs.c		\
		./src/page.c		\
		./src/page2.c		\
		./src/page3.c		\
		./src/pause.c		\
		./src/pop_character.c	\
		./src/practice.c	\
		./src/pyroco.c		\
		./src/quit.c		\
		./src/recipe.c		\
		./src/rolled.c		\
		./src/tauren.c		\
		./src/time.c		\
		./src/tutorial.c	\
		./src/undead.c		\
		./src/v2f.c		\
		./src/visual_text.c	\
		./src/visual_text2.c	\
		./src/wings.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -Iinclude

NAME	=	my_cook

all:	$(NAME)

tests_run:
		make -sC ./test
		./test/units-tests

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS) -lc_graph_prog -lm

clean:
		rm -rf $(OBJ)
		make -sC ./test clean

fclean:		clean
		make -sC ./test fclean
		rm -rf $(NAME)

re:		fclean all

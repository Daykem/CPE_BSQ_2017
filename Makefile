##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Made by Devlopers
##

SRC	=	main.c		\
		bsq.c		\
		lib.c

SRC_UT	=	tests/test.c	\
		bsq.c		\
		lib.c		\

CFLAGS	+=	-Iinclude -g3

LDFLAGS	=	-lcriterion -lgcov -L lib/my/ -lmy

NAME_UT	=	unit-tests

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

NAME	=	bsq

all:		$(NAME)

tests_run:	$(OBJ_UT)
	make -C lib/my/
	cc -o $(NAME_UT) $(OBJ_UT) $(LDFLAGS)
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcdo
	rm -f *.gcna
	rm -f *.gcno
	./unit-tests

$(NAME):	$(OBJ)
	make -C lib/my
	gcc $(OBJ) -o $(NAME) -L lib/my -lmy $(CFLAGS)
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcdo
	rm -f *.gcna
	rm -f *.gcno

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f unit-tests
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcdo
	rm -f *.gcna
	rm -f *.gcno

re:	fclean all

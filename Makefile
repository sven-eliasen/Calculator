CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wstrict-prototypes -std=c99
RM = rm -f
NAME = calculator
SRC = main.c calc_func.c calc_func.h
EXEC = ./
LIB = -lm

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIB)

clean:
	$(RM) $(NAME)

re: clean all

install:
	$(EXEC)$(NAME)

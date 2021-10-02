CC = gcc								# Nom du compilateur
CFLAGS = -Wall -Wextra -Werror -Wstrict-prototypes -std=c99		# Les flags
RM = rm -f 								# Commande pour supprimer des fichiers
NAME = main							# Nom de l'exécutable
SRC = main.c calc_func.c calc_func.h						# Les fichiers source. Soir *.c, soit on liste les fichiers
EXEC = ./
LIB = -lm

all:									# Règle all, exécutée par défaut avec la commande "make"
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIB)

# On n'utilise que des variables ici. On modifie les variables, pas la ligne de commande

clean:									# Règle clean, pour supprimer les fichiers générés par le compilateur. On utilise "make clean"
	$(RM) $(NAME)

re: clean all 								# "make re", pour supprimer les anciens fichiers et les génére à nouveau.

install:
	$(EXEC)$(NAME)

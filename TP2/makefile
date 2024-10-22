# Nom de l'exécutable
TARGET = exo_tab_float exo_tab_int exo_matrice exo_tab_2d

# Fichier source
SRCS_tab_float = exo_tab_float.c
SRCS_tab_int = exo_tab_int.c
SRCS_matrice = exo_matrice.c
SRCSH_exotab = exo_tab.h
SRCSH_exotab_2d = exo_tab_2d.c
# Fichier objet généré
OBJS = $(SRCS:.c=.o)

# Compilateur à utiliser
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c11 

#  Bibliothèque
LIBS = -lm

# Règle par défaut
all: $(TARGET)

exo_tab_int: $(SRCS_tab_int) $(SRCSH_exotab)
	$(CC) $(CFLAGS) -o exo_tab_int $(SRCS_tab_int) $(SRCSH_exotab)

exo_tab_float: $(SRCS_tab_float) $(SRCSH_exotab)
	$(CC) $(CFLAGS) -o exo_tab_float $(SRCS_tab_float) $(SRCSH_exotab)

exo_matrice: $(SRCS_matrice) $(SRCSH_exotab)
	$(CC) $(CFLAGS) -o exo_matrice $(SRCS_matrice) $(SRCSH_exotab)
	
exo_tab_2d: $(SRCS_tab_2d) $(SRCSH_exotab_2d)
	$(CC) $(CFLAGS) -o exo_tab_2d $(SRCS_tab_2d) $(SRCSH_exotab)
# Règle pour compiler le fichier .c en fichier .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS) $(TARGET)

# Indique à make que clean n'est pas un fichier, mais une commande à exécuter
.PHONY: clean

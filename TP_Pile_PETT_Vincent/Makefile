# Nom de l'exécutable
TARGET = tp_note_test

# Fichiers source
SRCS = tp_note_test.c tp_note.c

# Fichiers objet générés
OBJS = $(SRCS:.c=.o)

# Compilateur à utiliser
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c11

# Bibliothèque (si nécessaire)
LIBS = -lm

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable de test
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Règle pour compiler les fichiers .c en fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS) $(TARGET)

# Indique à make que clean n'est pas un fichier, mais une commande à exécuter
.PHONY: all clean

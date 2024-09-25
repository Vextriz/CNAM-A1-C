# Nom de l'exécutable
TARGET = exo1

# Fichier source
SRCS = exo1.c

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

# Règle pour créer l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Règle pour compiler le fichier .c en fichier .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS) $(TARGET)

# Indique à make que clean n'est pas un fichier, mais une commande à exécuter
.PHONY: clean

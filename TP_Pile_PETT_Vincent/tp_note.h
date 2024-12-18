#define VRAI 1
#define FAUX 0

#ifndef TP_NOTE_H
#define TP_NOTE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int BOOLEAN;

typedef struct Pile {
    float** blocs;             
    size_t nbr_max_blocs;
    size_t size_bloc;
    size_t nbr_blocs_alloue;
    int sommet;            
} Pile;

Pile* new_pile(size_t size_blocs, size_t nbr_max_blocs);
BOOLEAN push(Pile* pile, float donnee);
float* head(Pile* pile);
BOOLEAN pop(Pile* pile);
BOOLEAN empty(Pile* pile);
void dump(Pile* pile);
void clean(Pile* pile);
void destroy(Pile** pile_ptr);
void shrink(Pile* pile);
void change_bloc_size(Pile* pile, size_t size_blocs);

#endif
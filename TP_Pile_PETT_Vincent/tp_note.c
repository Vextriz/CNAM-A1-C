#include "tp_note.h"

Pile* new_pile(size_t size_bloc, size_t nbr_max_blocs){
    Pile* pile = (Pile*)malloc(sizeof(Pile));
    if (!pile){
        fprintf(stderr,"Erreur lors de la création de la pile");
        return NULL;
    }
    pile->blocs = (float**)malloc(nbr_max_blocs * sizeof(float*));
    if (!pile-> blocs){
        fprintf(stderr,"Erreur lors de l'allocation des blocs");
        free(pile);
        return NULL;
    }
    for (size_t i = 0; i<nbr_max_blocs; i++){
        pile->blocs[i] = (float*)malloc(size_bloc * sizeof(float));
        if (!pile-> blocs[i]){
            fprintf(stderr,"Erreur lors de l'allocation d'un bloc");
            for(size_t j = 0;j <i ;j++){
                free(pile->blocs[i]);
            }
            free(pile->blocs);
            free(pile);
            return NULL;
        }
    }
    pile->nbr_max_blocs = nbr_max_blocs;
    pile->size_bloc = size_bloc;
    pile->nbr_blocs_alloue = 0;
    pile->sommet = -1; 
    return pile;
}
BOOLEAN push(Pile* pile, float donnee){
    if (!pile){
        fprintf(stderr,"La pile n'existe pas");
        return FAUX;
    }
    if (pile->sommet > (int)pile->nbr_max_blocs){
        fprintf(stderr,"Pile pleine impossible d'ajouté un blocs");
        return FAUX;
    }
    pile->sommet++;
      
    int bloc_index = pile->sommet / pile->size_bloc;
    int indice_local = pile->sommet % pile->size_bloc;

    pile->blocs[bloc_index][indice_local] = donnee;
    pile->nbr_blocs_alloue++;
    return VRAI;   
}

float* head(Pile* pile){
    if (!pile) {
        fprintf(stderr,"La pile n'existe pas\n");
        return NULL;
    }

    if (pile->sommet == -1) {
        fprintf(stderr,"Erreur : La pile est vide\n");
        return NULL;
    }
    int bloc_index = pile->sommet / pile->size_bloc;
    int indice_local = pile->sommet % pile->size_bloc;

    return &pile->blocs[bloc_index][indice_local];
}

BOOLEAN pop(Pile* pile){
    if(!pile){
        fprintf(stderr,"La pile n'existe pas\n");
        return FAUX;
    }
        if (pile->sommet == -1) {
        fprintf(stderr,"Erreur : La pile est vide\n");
        return FAUX;
    }
    int bloc_index = pile->sommet / pile->size_bloc;
    int indice_local = pile->sommet % pile->size_bloc;

    pile->blocs[bloc_index][indice_local] = 0.0; // Valeur pour dire que la pile est dépliée
    pile->sommet--;
    pile->nbr_blocs_alloue--;
    return true;
}

BOOLEAN empty(Pile* pile){
    if(!pile){
        fprintf(stderr,"La pile n'existe pas\n");
        return NULL; // Return NULL car ce on ne peut ni mettre faux ni mettre vrai dans ce cas de figure
    }
    if (pile->sommet == -1) {
        printf("Erreur : La pile est vide\n");
        return VRAI;
    }
    return FAUX;
}

void dump(Pile* pile){
    if (!pile) {
        fprintf(stderr, "La pile n'existe pas\n");
        return;
    }

    printf("Pile: ");
    printf("  Taille des blocs: %ld ", pile->size_bloc);
    printf("  Nombre maximal de blocs: %ld ", pile->nbr_max_blocs);
    printf("  Nombre de blocs alloués: %ld", pile->nbr_blocs_alloue);
    printf("  Indice du sommet: %d\n", pile->sommet);

    printf("Contenu de la pile:\n");
    for (int i = 0; i <= pile->sommet; i++) {
        int bloc_index = i / pile->size_bloc;
        int indice_local = i % pile->size_bloc;
        printf("  Indice global %d -> Bloc %d, Indice %d : %.1f\n", i, bloc_index, indice_local, pile->blocs[bloc_index][indice_local]);
    }
}

void clean(Pile* pile){
    if (!pile) {
        fprintf(stderr, "La pile n'existe pas\n");
        return;
    }
    for(size_t i = 0;i<pile->nbr_max_blocs; i++){
        free(pile->blocs[i]);
    }
    pile->sommet = -1;
    pile->nbr_blocs_alloue = 0;
}

void destroy(Pile** pile_ptr) {
    if (!pile_ptr || !(*pile_ptr)) {
        fprintf(stderr, "La pile n'existe pas\n");
        return;
    }
    Pile* pile = *pile_ptr;

    clean(pile); 

    free(pile->blocs);
    free(pile); 

    *pile_ptr = NULL; 
}

void shrink(Pile* pile) {
    if (!pile) {
        fprintf(stderr, "La pile n'existe pas\n");
        return;
    }
    for (size_t i = pile->sommet + 1; i < pile->nbr_max_blocs; i++) {
        if (pile->blocs[i]) {
            free(pile->blocs[i]);
            pile->blocs[i] = NULL;
        }
    }
}
void change_bloc_size(Pile* pile, size_t size_bloc) {
    if (!pile) {
        fprintf(stderr, "La pile n'existe pas\n");
        return;
    }

    if (pile->size_bloc == size_bloc) {
        printf("La taille est la même qu'avant, rien à faire.\n");
        return;
    }

    float* temp_data = (float*)malloc((pile->sommet + 1) * sizeof(float));
    if (!temp_data) {
        fprintf(stderr, "Erreur d'allocation pour les données temporaires\n");
        return;
    }

    int index = 0;
    for (int i = 0; i <= pile->sommet; i++) {
        int bloc_index = i / pile->size_bloc;
        int indice_local = i % pile->size_bloc;
        temp_data[index++] = pile->blocs[bloc_index][indice_local];
    }

    for (size_t i = 0; i < pile->nbr_max_blocs; i++) {
        free(pile->blocs[i]);
    }

    for (size_t i = 0; i < pile->nbr_max_blocs; i++) {
        pile->blocs[i] = (float*)malloc(size_bloc * sizeof(float));
        if (!pile->blocs[i]) {
            fprintf(stderr, "Erreur d'allocation pour un nouveau bloc\n");
            free(temp_data);
            return;
        }
    }

    pile->size_bloc = size_bloc;

    index = 0;
    for (int i = 0; i <= pile->sommet; i++) {
        int bloc_index = i / size_bloc;
        int indice_local = i % size_bloc;
        if (index < (pile->sommet + 1)) {
            pile->blocs[bloc_index][indice_local] = temp_data[index++];
        } else {
            pile->blocs[bloc_index][indice_local] = 0.0; // Remplissage si données insuffisantes
        }
    }
    free(temp_data);
}

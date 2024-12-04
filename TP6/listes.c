#include "listes.h"
typedef struct Noeud {
    int valeur;                // Valeur contenue dans le noeud
    struct Noeud* suivant;     // Pointeur vers le noeud suivant
} Noeud;

typedef struct Liste {
    Noeud* tete;             // Pointeur vers le premier noeud de la liste
    int taille;              // Nombre d'éléments dans la liste
} Liste;

Liste* liste_vide(){
    Liste* liste = malloc(sizeof(Liste));
    liste->tete = NULL;
    liste->taille = 0;
    return liste;
}
Noeud* push_front(Liste* liste, int valeur) {
    Noeud* noeud = malloc(sizeof(Noeud));
    noeud->valeur = valeur;
    noeud->suivant = liste->tete;
    liste->tete = noeud;
    liste->taille++;
    return noeud;
}
void pop_front(Liste * liste){
    if (liste->tete == NULL) {
        return;
    }
    Noeud* temp = liste->tete;
    liste->tete = liste->tete->suivant;
    free(temp);
    liste->taille--;
}
int front_val(Liste* liste){
    if (liste->tete == NULL) {
        return -1;
    }
    return liste->tete->valeur;
}
void print_liste(Liste* liste){
    Noeud* current = liste->tete;
    while (current!= NULL) {
        printf("%d\n", current->valeur);
        current = current->suivant;
    }
    printf("\n");
}
int est_vide(Liste *liste){
    if (liste->taille == 0)
        return 1;
    return 0;
}
Noeud* trouve_premier(Liste* liste, int valeur){
    Noeud* current = liste->tete;
    int i = 0;
    while (current!= NULL) {
        i++;
        if (current->valeur == valeur){
            printf("Index du premier : %d\n", i);
            return current;
        }
        current = current->suivant;
    }
    return NULL;
}
int occurence (Liste* liste, int valeur){
    Noeud* current = liste->tete;
    int count = 0;
    while (current!= NULL) {
        if (current->valeur == valeur)
            count++;
        current = current->suivant;
    }
    return count;
}

Noeud* insert_after(Noeud* noeud, int valeur){
    Noeud* new_noeud = malloc(sizeof(Noeud));
    new_noeud->valeur = valeur;
    new_noeud->suivant = noeud->suivant;
    noeud->suivant = new_noeud;
    return new_noeud;
}
void retire(Liste *liste, Noeud* noeud){
    if (liste->tete == noeud) {
        pop_front(liste);
        return;
    }
    Noeud* current = liste->tete;
    while (current->suivant!= noeud) {
        current = current->suivant;
    }
    current->suivant = noeud->suivant;
    free(noeud);
    liste->taille--;
}

Noeud* push_back(Liste* liste, int valeur){
    Noeud* new_noeud = malloc(sizeof(Noeud));
    new_noeud->valeur = valeur;
    new_noeud->suivant = NULL;
    if (est_vide(liste)) {
        liste->tete = new_noeud;
    } else {
        Noeud* current = liste->tete;
        while (current->suivant != NULL) {
            current = current->suivant;
        }
        current->suivant = new_noeud;
    }
    liste->taille++;
    return new_noeud;
}
void pop_back(Liste* liste){
    if (est_vide(liste)) {
        return;
    }
    if (liste->tete->suivant == NULL) {
        free(liste->tete);
        liste->tete = NULL;
    } else {
        Noeud* current = liste->tete;
        while (current->suivant->suivant!= NULL) {
            current = current->suivant;
        }
        free(current->suivant);
        current->suivant = NULL;
    }
    liste->taille--;
}
int back_val(Liste* liste){
    if (est_vide(liste)) {
        return 0;
    }else{
        Noeud* current = liste->tete;
        while (current->suivant != NULL){
            current = current->suivant;
        }
        return current->valeur;
    }
}
int main(){
    Liste* liste = liste_vide();
    push_back(liste, 10);
    push_back(liste, 20);
    push_back(liste, 30);
    print_liste(liste);
    printf("Occurence de 20 : %d\n", occurence(liste, 20));
    Noeud* premier_deux = trouve_premier(liste, 20);
    insert_after(premier_deux, 25);
    print_liste(liste);
    pop_back(liste);
    print_liste(liste);
    printf ("Première valeur : %d\n",front_val(liste));
    printf ("Dernière valeur : %d\n",back_val(liste));
    return 0;
}
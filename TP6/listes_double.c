#include "listes.h"
typedef struct Noeud {
    int valeur;                // Valeur contenue dans le noeud
    struct Noeud* suivant;     // Pointeur vers le noeud suivant
    struct Noeud* precedent; // Pointeur vers le noeud précédent du noeud courant
} Noeud;

typedef struct Liste {
    Noeud* tete;            // Pointeur vers le premier noeud de la liste
    Noeud* pied;            // Pointeur vers le dernier noeud de la liste
    int taille;             // Nombre d'éléments dans la liste
} Liste;

Liste* liste_vide(){
    Liste* nouvelle_liste = malloc(sizeof(Liste));
    if(nouvelle_liste == NULL) return NULL;
    nouvelle_liste->tete = NULL;
    nouvelle_liste->pied = NULL;
    nouvelle_liste->taille = 0;
    return nouvelle_liste;
}
Noeud* push_front(Liste* liste, int valeur){
    Noeud* nouveau_noeud = malloc(sizeof(Noeud));
    if(nouveau_noeud == NULL) return NULL;
    nouveau_noeud->valeur = valeur;
    nouveau_noeud->suivant = liste->tete;
    nouveau_noeud->precedent = NULL;
    if(liste->tete == NULL) liste->pied = nouveau_noeud;
    liste->tete = nouveau_noeud;
    liste->taille++;
    return nouveau_noeud;
}
void pop_front(Liste *liste){
     if(liste->tete == NULL) return;
    Noeud* temp = liste->tete;
    liste->tete = temp->tete->suivant;
}
int front_val(Liste *liste){
    if(liste->tete == NULL) return -1;
    return liste->tete->valeur;
}
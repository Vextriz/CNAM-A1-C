#include "tp_note.h"

int main() {
    size_t size_blocs = 3;
    size_t nbr_max_blocs = 4;

    Pile* maPile = new_pile(size_blocs, nbr_max_blocs);
    if (!maPile) return 1;

    printf("Test: Pile créée avec succès.\n");

    float donnee1 = 1.1;
    if (push(maPile, donnee1)) {
        printf("Test: Donnée %.1f empilée avec succès.\n", donnee1);
    }

    float donnee2 = 2.2;
    if (push(maPile, donnee2)) {
        printf("Test: Donnée %.1f empilée avec succès.\n", donnee2);
    }
     float donnee3 = 3.3;
    if (push(maPile, donnee3)) {
        printf("Test: Donnée %.1f empilée avec succès.\n", donnee3);
    }

    dump(maPile);

    float* sommet = head(maPile);
    if (sommet) {
        printf("Test: Le sommet de la pile est %.1f.\n", *sommet);
    }

    if (pop(maPile)) {
        printf("Test: Dépilation effectuée avec succès.\n");
    }

    dump(maPile);

    if (empty(maPile)) {
        printf("Test: La pile est vide.\n");
    } else {
        printf("Test: La pile n'est pas vide.\n");
    }

    shrink(maPile);
    printf("Test: Blocs inutilisés libérés.\n");

    dump(maPile);

    change_bloc_size(maPile, 5);
    printf("Test: Taille des blocs modifiée.\n");

    dump(maPile);

    destroy(&maPile);
    printf("Test: Pile détruite avec succès.\n");

    return 0;
}

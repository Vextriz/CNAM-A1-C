#include "exo_tab.h"

typedef int DATA;

void print(DATA array[][], int size1, int size2) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
        printf("%d ", array[i][j]);
        }
    printf("\n");
    }
}

void read(DATA array[][], int size1, int size2) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
        scanf("%d", &array[i][j]);
        }
    }
}
DATA valeur_max(DATA array[][], int size1, int size2){
    int max = array[0][0];  
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (array[i][j] > max)
                max = array[i][j];
        }
    }
    return max ;
}
int occurrence(DATA array[][], int size1, int size2, int el){
    int occ = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (array[i][j] == el)
                occ++;
        }
    }
    return occ;
}
BOOLEAN is_sudoku(int array[3][3]) {
    int compteur[10] = {0};  

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int valeur = array[i][j];
            if (valeur < 1 || valeur > 9) {
                return true;  
            }
            compteur[valeur]++;
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (compteur[i] != 1) {
            return false;  
        }
    }
    
    return true;    
}

int main() {
    int array[3][3] = {
        {5, 3, 4},
        {6, 7, 2},
        {1, 9, 8}
    };

    if (is_sudoku(array)) {
        printf("Le tableau est un Sudoku valide.\n");
    } else {
        printf("Le tableau n'est pas un Sudoku valide.\n");
    }

    return 0;
}
#include <stdio.h>

typedef float Matrix33[3][3];

void readMatrix33(Matrix33* matrix) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%f", &(*matrix)[i][j]);
        }
    }
}

void setId(Matrix33* matrix) {
    for (int i = 0; i < 3; i++) {
        (*matrix)[i][i] = 1.0;
    }
}
void printMatrix33(Matrix33* matrix) {
    for (int i = 0; i < 3; i++) {
        printf("[");
        for(int j = 0; j < 3; j++) {
            printf("%f ", (*matrix)[i][j]);
        }
        printf("]\n");
    }
}
void somme(Matrix33 *matA, Matrix33 * matB, Matrix33 * matApB){
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            (*matApB)[i][j] = (*matA)[i][j] + (*matB)[i][j];
        }
    }
}
void produit (Matrix33 *matA, Matrix33 * matB, Matrix33 * matAfB){
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            float mat = 0.0;
            for (int y = 0; y< 3;y++)
            {
                mat += (*matA)[i][y] * (*matB)[y][j];
            }
            (*matAfB)[i][j] = mat;
        }
    }
}


int main() {
    Matrix33 matrix;
    readMatrix33(&matrix);
    setId(&matrix);
    return 0;
}

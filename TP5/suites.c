#include "suites.h"

int recursive(int Un, int n){
    while( n != 0){
        if (Un == 0){
            return 0;
        }
        else{
            printf("%d\n",Un);
            return recursive(2*Un - 1, n - 1);
        }
    }
    return 0;
}
int syracuse(int Un){
    while (Un != 1){
        if (Un % 2 == 0){
            printf("%d\n",Un);
            return syracuse(Un/2);
        }
        else{
            printf("%d\n",Un);
            return syracuse(3*Un + 1);
        }
    }
    return 0;
}
int chiffres (int Un){
    while (Un != 9){
        printf ("%d\n",Un);
        return chiffres(Un + 1);
    }
    return 0;
}

long fibonnaci(long Un, long Un_, int occ){
    while (occ != 93){        
        printf ("F[%d] = %ld\n",occ,Un);
        return fibonnaci(Un + Un_, Un ,occ+1);
    }
    return 0;
}

int tour_anoy(int n, int A[64], int B[64], int C[64]){
    while (n >= 1){
        tour_anoy(n-1, A, C, B);
        A = C;
        for(int i = 0; i <64;i++){
            printf("N[%d] : |%d| |%d| |%d|\n",n,A[i], B[i], C[i]);
        }
        tour_anoy(n-1, B, A, C);
    }
    return 0;
}

int main() {
    recursive(5,7);
    syracuse(12);
    chiffres(0);
    fibonnaci(1,0,2);
    int A[64], B[64], C[64];
    for (int i = 0; i <64;i++){
        A[i] = i;
    }
    tour_anoy(64,A,B,C);
}
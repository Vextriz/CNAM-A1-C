#include "exo_tab.h"
typedef float DATA;

void print( DATA array[ ], int size ){
    for (int i = 0; i < size; i++)
    {
        printf("%f\n", array[i]);
    }
    
}

void read( DATA array[ ], int size){
    for (int i = 0; i < size; i++)
    {
        scanf("%f", &array[i]);
    }
    
}
void random_fill_float( DATA array[ ], int size, DATA vmin, DATA vmax){
    srand(time(NULL));   
     for (int i = 0; i < size; i++) {
        float scale = rand() / (float)RAND_MAX; 
        float v = vmin + scale * (vmax - vmin); 
        array[i] = v;
    }
}

DATA valeur_max(DATA array[ ], int size){
    int max = array[0];
    for (int i = 0; i < size; i++){
        if (array[i] > max)
            max = array[i];
    }
    printf("Maximum value: %f\n", max);
    return max;
}
void swap_elt(DATA array[ ], int size, int i, int j){
    if (i >= 0 && i < size && j >= 0 && j < size){
        int swap = array[i];
        array[i] = array[j];
        array[j] = swap;
    }
}
int occurrences( DATA array[ ], int size, DATA element){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (array[i] == element)
            count++;
    }
    printf("Number of occurences %d: %d\n", element, count);
    return count;
}
int find_first( DATA array[ ], int size, DATA el ) {
    int occ = -1;
    for (int i = 0; i < size; i++){
        if (array[i] == el)
            occ = i; 
    }
    printf("First occurrence of %d: %d\n", el, occ);
    return occ;  
}
int find_last( DATA array[ ], int size, DATA el ) {
    int occ = -1;
    for(int i = size-1; i > 0 ; i--){
        if(array[i] == el)
            occ = i; 
    }
    printf("Last occurrence of %f: %d\n", el, occ);
    return occ;
}
void reverse( DATA array[ ], int size){
    for (int i = 0; i < size/2; i++){
        swap_elt(array, size, i, size - i - 1);
    }
}
void rotate_right( DATA array[ ], int size){
    DATA temp = array[size - 1];
    for (int i = size - 1; i > 0; i--){
        array[i] = array[i - 1];
    }
    array[0] = temp;

}
void rotate_left( DATA array[ ], int size){
    DATA temp = array[0];
    for(int i = 0; i < size - 1; i++){
        array[i] = array[i + 1];
    }
    array[size - 1] = temp;
}
BOOLEAN is_palindrome(DATA array[ ], int size){
    BOOLEAN bool = VRAI;
    for (int i = 0; i < size / 2; i++){
        if (array[i]!= array[size - i - 1])
            bool = FAUX;
    }
    printf("Is the array palindrome? %s\n", bool? "Yes" : "No");
    return bool;
}
int main(){
    DATA array[10];
    printf("===============READ============================\n");
    read(array, 10);
    printf("===============PRINT============================\n");
    print(array, 10);
    printf("===============RANDOM_FILL_FLOAT====================\n");
    random_fill_float(array, 10, 1, 100);
    printf("===============VALEUR_MAX============================\n");
    valeur_max(array, 10);
    printf("===============SWAP_ELT============================\n");
    swap_elt(array, 10, 2, 5);
    print(array, 10);
    printf("===============OCCURENCES============================\n");
    occurrences(array, 10, 50);
    printf("===============FIND_FIRST============================\n");
    find_first(array, 10, 50);
    printf("===============FIND_LAST============================\n");
    find_last(array, 10, 50);
    printf("===============REVERSE============================\n");
    reverse(array, 10);
    print(array, 10);
    printf("===============ROTATE_RIGHT============================\n");
    rotate_right(array, 10);
    print(array, 10);
    printf("===============ROTATE_LEFT============================\n");
    rotate_left(array, 10);
    print(array, 10);
    printf("===============IS_PALINDROME============================\n");
    is_palindrome(array, 10);
}
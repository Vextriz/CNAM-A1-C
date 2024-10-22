#include "exo_tab.h"
typedef int DATA;

void print( DATA array[ ], int size ){
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
    }
    
}

void read( DATA array[ ], int size){
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    
}
void random_fill_int( DATA array[ ], int size, DATA vmin, DATA vmax){
    srand(time(NULL));   
    for (int i = 0; i < size; i++){
        int v = rand () % ( vmax + 1 - vmin) + vmax + 1;
        array[i] = v;
    }
}

DATA valeur_max(DATA array[ ], int size){
    int max = array[0];
    for (int i = 0; i < size; i++){
        if (array[i] > max)
            max = array[i];
    }
    printf("Maximum value: %d\n", max);
    return max;
}
void swap_elt(DATA array[ ], int size, int i, int j){
    if (i >= 0 && i < size && j >= 0 && j < size){
        DATA swap = array[i];
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
    printf("Last occurrence of %d: %d\n", el, occ);
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
void drapeau_hollandais(){
    char drapeau[30] = "Welterweight champions";
    int red = 0;
    int white = 10;
    int blue = 29;
    int redcount = 0;
    int whitecount = 0;
    int bluecount = 0;
    srand(time(NULL));   
     for (int i = 0; i < 30; i++) {
        int randomIndex = rand() % 3; 
        char randomletter;

        if (randomIndex == 0) {
            randomletter = 'R';
            redcount++;
        } else if (randomIndex == 1) {
            randomletter = 'W';
            whitecount++;
        } else {
            randomletter = 'B';
            bluecount++;
        }

        drapeau[i] = randomletter;
    }
    int i = 0;
    while (white <= blue) {
        if (drapeau[white] == 'R'){
            char colorswap = drapeau[white];
            drapeau[white] = drapeau[red];
            drapeau[red] = colorswap;
            red++;
        }
        else if (drapeau[white] == 'W'){
            white++;
        }
        else {
            char colorswap = drapeau[white];
            drapeau[white] = drapeau[blue];
            drapeau[blue] = colorswap;
            blue--;
        }
        i++;
        printf("Etape %d: red : %d white : %d blue %d  : ", i,red,white,blue);
        for (int i = 0; i < 30; i++ ){
        printf("%c ", drapeau[i]);
    }
        printf("\n");
    }
    for (int i = 0; i < 30; i++ ){
        printf("%c ", drapeau[i]);
    }
    printf("\n");
}
void tri_negatif_positif(){
    int array[10] = {1,-1,1,-1,-1,1,-1,1,1,-1};
    int neg = 0;
    int pos = 9;
    srand(time(NULL));  
    int i = 0; 
    while (neg <= pos) {
        if (array[neg] > 0){
            int numswap = array[neg];
            array[neg] = array[pos];
            array[pos] = numswap;
            pos--;
        }
        else 
        {
            neg++;
        }
    i++;
        printf("Etape : %d : ", i);
        for (int i = 0; i < 10; i++ ){
        printf("%d ", array[i]);
    }
        printf("\n");
    }

}
int main(){
    DATA array[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("===============READ============================\n");
    // read(array, 10);
    printf("===============PRINT============================\n");
    print(array, 10);
    printf("===============RANDOM_FILL============================\n");
    random_fill_int(array, 10, 1, 100);
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
    printf("===============ROTATE_RIGHT==========================\n");
    rotate_right(array, 10);
    print(array, 10);
    printf("===============ROTATE_LEFT==========================\n");
    rotate_left(array, 10);
    print(array, 10);
    printf("===============IS_PALINDROME=========================\n");
    is_palindrome(array, 10);
    printf("===============DRAPEAU_HOLLANDAIS=========================\n");
    drapeau_hollandais();
    printf("===============TRI_NEGATIF_POSITIF=========================\n");
    tri_negatif_positif();
}
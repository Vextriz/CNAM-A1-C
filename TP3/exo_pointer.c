#include "exo_pointer.h"

void arithmetique(){
     char c;
    int i;
    double d;
    long l;
    
    int arr_int[5];
    double arr_double[5];
    
    printf("Adresses des variables de différents types :\n");
    printf("Adresse de char c : %p\n", (void*)&c);
    printf("Adresse de int i : %p\n", (void*)&i);
    printf("Adresse de double d : %p\n", (void*)&d);
    printf("Adresse de long l : %p\n", (void*)&l);
    
    printf("\nDifférences entre adresses des variables (en octets) :\n");
    printf("Différence entre c et i : %ld\n", (long)&i - (long)&c);
    printf("Différence entre i et d : %ld\n", (long)&d - (long)&i);
    printf("Différence entre d et l : %ld\n", (long)&l - (long)&d);
    
    printf("\nAdresses des éléments d'un tableau d'int :\n");
    for (int j = 0; j < 5; j++) {
        printf("Adresse de arr_int[%d] : %p\n", j, (void*)&arr_int[j]);
    }
    
    printf("\nAdresses des éléments d'un tableau de double :\n");
    for (int j = 0; j < 5; j++) {
        printf("Adresse de arr_double[%d] : %p\n", j, (void*)&arr_double[j]);
    }
    
    int *p = arr_int;
    printf("\nPointeur initial sur arr_int : %p\n", (void*)p);
    p++;
    printf("Pointeur après incrémentation (p++) : %p\n", (void*)p);
    printf("Différence après incrémentation du pointeur (en octets) : %ld\n", (long)p - (long)arr_int);
}

void info_tab_float(float* min, float* max, float* moyenne, float tab[10]){
    *min = tab[0];
    *max = tab[0];

    for(int i = 0; i < 10; i++){
        if (tab[i] < *min){
            *min = tab[i];
        }
        if (tab[i] > *max){
            *max = tab[i];
        }
        *moyenne += tab[i];
    }
    *moyenne /= 10.0;
}

int longueur (char* string){
    int i = 0;
    while(string[i]!= '\0'){
        i++;
    }
    return i;
}

bool compare (char* string1, char* string2){
    int len1 = longueur(string1);
    int len2 = longueur(string2);
    if (len1 != len2){
        return false;
    }
    else{
        for(int i = 0; i < len1; i++){
            if(string1[i]!= string2[i]){
                return false;
            }
        }
        return true;
    }
}
bool palindrome(char* string){
    int len = longueur(string);
    for(int i = 0; i < len/2; i++){
        if(string[i]!= string[len-i-1]){
            return false;
        }
    }
    return true;
}
int find_sub_string(char* string, char* sub_string){
    for(int i = 0; i < longueur(string); i++){
        if(compare(&string[i], sub_string)){
            return i;
        }
    }
    return -1;
}
int string_to_int(char* string){
    int number = 0;
    int sign = 1;
    int i = 0;
    if(string[0] == '-'){
        sign = -1;
        i++;
    }
    while(i < longueur(string)){
        number = number *10 + (string[i] -'0');
        i++;
    }
    return number * sign;
}

int evaluate_expression(int argc, char **argv) {
    int resultat = 0;
    int nombre;
    char operation = '+';  

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '+' || argv[i][0] == '-') {
            operation = argv[i][0]; 
        } else {
            nombre = string_to_int(argv[i]);

            if (operation == '+') {
                resultat += nombre;
            } else if (operation == '-') {
                resultat -= nombre;
            }
        }
    }
    return resultat;
}
int get_index(int i, int j, int k, int *array) {
    return *(array + i * 3 * 3 + j * 3 + k);
}

void set_index(int value, int i, int j, int k, int *array) {
    *(array + i * 3 * 3 + j * 3 + k) = value;
}

void init_tab_3D(int *array) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                *(array + i * 3 * 3 + j * 3 + k) = 0;
            }
        }
    }
}
void fill_pascal_triangle(int *pascal, int taille){
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (j == 0 || j == i) {
                *(pascal + i * taille + j) = 1;
            } else {
                *(pascal + i * taille + j) = *(pascal + (i - 1) * taille + (j - 1)) + *(pascal + (i - 1) * taille + j);
            }
        }
    }
}

void print_pascal_triangle(int *pascal, int taille) {
    for (int i = 0; i < taille; i++) {
        for (int space = 0; space < (taille - i - 1); space++) {
            printf("  ");
        }

        for (int j = 0; j <= i; j++) {
            printf("%4d", *(pascal + i * taille + j));
        }
        printf("\n");
    }
}


int main(int argc, char **argv){
    arithmetique();
    float min, max, moyenne;
    float tab[10] = {1.5, 2.7, 3.2, 4.8, 5.1, 6.3, 7.6, 8.9, 9.2, 10.5};
    info_tab_float(&min, &max, &moyenne, tab);
    printf("Minimum : %.2f\n", min);
    printf("Maximum : %.2f\n", max);
    printf("Moyenne : %.2f\n", moyenne);
    for (int i = 0; i < argc; i++) {
        printf("Paramètre %d : %s\n", i, argv[i]);
    }
    int i = 2, j =0, k=1;
    int array[3][3][3];
    init_tab_3D((int *)array);
    set_index(91,i,j,k,(int *)array);
    printf("Tableau 3D %d \n",get_index(i, j, k, (int *)array));

    int taille = 13;
    int pascal[taille*taille];
    fill_pascal_triangle((int *)pascal, taille);
    print_pascal_triangle((int *)pascal, taille);

}
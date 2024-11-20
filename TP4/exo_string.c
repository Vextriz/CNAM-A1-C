#include "exo_string.h"

char* copy( const char* chaine){
    int length = strlen(chaine);
    char* result = malloc((length + 1) * sizeof(char));
    strcpy(result, chaine);
    return result;
}
char* reverse(const char* chaine){
    int length = strlen(chaine);
    char* result = malloc((length + 1) * sizeof(char));
    strcpy(result, chaine);
    for(int i = 0; i < length / 2; i++){
        char temp = result[i];
        result[i] = result[length - i - 1];
        result[length - i - 1] = temp;
    }
    return result;
}
char* sub_string(const char* chaine, int pos, int len){
    int length = strlen(chaine);
    if(pos < 0 || pos >= length || len < 0 || len > length - pos){
        return NULL;
    }
    char* result = malloc((len + 1) * sizeof(char));
    strncpy(result, chaine + pos, len);
    result[len] = '\0';
    return result;
}
int decoupe(const char* chaine, char sepa, char*** souschaines);{

}
char* int_to_string(int val){
    char* result = malloc(16 * sizeof(char));
    sprintf(result, "%d", val);
    return result;
}
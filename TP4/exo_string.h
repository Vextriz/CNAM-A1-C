#include <stdio.h>
#include <stdbool.h>

char* copy( const char* chaine);
char* reverse(const char* chaine);
char* sub_string(const char* chaine, int pos, int len);
int decoupe(const char* chaine, char sepa, char*** souschaines);
char* int_to_string(int val);
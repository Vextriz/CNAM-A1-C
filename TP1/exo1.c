#include <stdlib.h>
#include <math.h> 
#include <stdio.h> 
#include <stdbool.h>

bool bissextile (int annee){
    if (annee % 4 == 0){
            if (annee % 100 == 0){
                if (annee % 400 ==0)
                    return true;
                return false;
            }
            else
                return true;
            return true;
        }
        else 
            return false;
    }
void utilisation_reel(double reel){
    int perimetre, surface;
    double diagonale;
   
    perimetre = reel *4;
    surface = reel * 2;
    diagonale = sqrt(pow(reel,2) *2);
    printf("Le périmètre est : %d\n",perimetre);
    printf("La surface est : %d\n",surface);
    printf("La diagonale est : %f\n",diagonale);
}
int jour_mois(int num_mois, int annee){
    switch (num_mois)
    {
    case 1 :
        return 31;
        break;
    case 2 : 
        if(bissextile(annee))
            return 29;
        else
            return 28;
        break;
    case 3 : 
        return 31;
        break;
    case 4 :
        return 30;
        break;
    case 5 : 
        return 31;
        break;
    case 6 : 
        return 30;
        break;
     case 7 : 
        return 31;
        break;
     case 8 : 
        return 31;
        break;
     case 9 : 
        return 30;
        break;
     case 10 :
        return 31;
        break;
     case 11 :
        return 30;
        break;
     case 12 :
        return 31; 
        break;
    default:
        printf("Le chiffre n'est pas valide");
        return 0;
        break;
    }
}

int diff_second_v1 (int h1, int m1, int s1, int h2, int m2, int s2){
        int c1,c2, diff;
        c1 = h1*3600 + m1*60 + s1;
        c2 = h2*3600 + m2*60 + s2;
        diff = c2-c1 ; 
        return diff;
    }
int diff_second_v2 (int h1, int m1, int s1, int h2, int m2, int s2){
        int c1,c2, diff, jour_supp;
        jour_supp = 86400;
        c1 = h1*3600 + m1*60 + s1;
        c2 = h2*3600 + m2*60 + s2;
        diff = jour_supp + c2-c1 ; 
        return diff;
}
void jour_suivant(int *jour, int *mois, int *annee){
    int nb_jours;
    nb_jours = jour_mois(*mois,*annee);
    if (*jour == nb_jours)
    {
        *jour = 1;
        if (*mois == 12){
            *mois = 1;
            *annee = *annee +1;
        }
        else 
        {
           * mois = *mois +1;
        }
    }
    else 
    {
        *jour = *jour + 1;
    }
}
      

int main (){
    int jour,mois,annee;
    double reel;
    int h1,m1,s1,h2,m2,s2;
    printf("Renseignez : jour, mois, année : \n");
    printf("Jour : ");
    scanf("%d[^\n]",&jour);
    printf("Mois :");
    scanf("%d[^\n]",&mois);
    printf("Année :");
    scanf("%d[^\n]",&annee);
    printf("La  date est %d/%d/%d\n",jour,mois,annee);
    jour_suivant(&jour,&mois,&annee);
    printf("La nouvelle date est %d/%d/%d\n",jour,mois,annee);
    printf("Veuillez saisir votre réel : \n");
    scanf("%lf[^\n]", &reel);
    printf("le réel %f \n",reel);
    utilisation_reel(reel);
    int j_mois = jour_mois(mois,annee);
    printf("Voici le nombre de jour de ce mois : %d\n",j_mois);
    printf("Veuilez renseigner deux heures,minutes,seconds : \n");
    printf("Heure 1 : ");
    scanf("%d[^\n]",&h1);
    printf("Minute 1 :");
    scanf("%d[^\n]",&m1);
    printf("Seconde 1 :");
    scanf("%d[^\n]",&s1);
    printf("Heure 2 : ");
    scanf("%d[^\n]",&h2);
    printf("Minute 2 :");
    scanf("%d[^\n]",&m2);
    printf("Seconde 2 :");
    scanf("%d[^\n]",&s2);
    int diff_v1 = diff_second_v1(h1,m1,s1,h2,m2,s2);
    printf("La diff si c'est le même jour est de : %d\n",diff_v1);
    int diff_v2 = diff_second_v2(h1,m1,s1,h2,m2,s2);
    printf("La diff si c'est le même jour est de : %d\n",diff_v2);
    return 0;
    
}
#include<stdio.h>
#include<stdlib.h>
#define Depatement1 'Math'
#define Depatement2 'Physique'
#define Depatement3 'Informatique'
#define Depatement4 'Economie'



typedef struct 
{
    int jours ,mois,annee ;
}date;


typedef struct 
{
    int id ;
    char nom[100];
    char prenom[100];
    date date_naissance;
    char depatement[100];
    int note;
} etudiants;

etudiants E[100];

int NE=0;

            // Ajouter les Etudiants :
// Ajouter one :
void AjouterOne(){
    int choix;
    E[NE].id=NE+1;
    printf("Le nom d'etudiant : ");
    scanf("%[^\n]",E[NE].nom);
    getchar();
   
    printf("Le prenom d'etudiant : ");
    scanf("%[^\n]",E[NE].prenom);
    getchar();
    
    do
    {
        printf("Entrez le deadline sous forme (jj-mm-dd) : ");
        scanf("%d-%d-%d", &E[NE].date_naissance.jours, &E[NE].date_naissance.mois, &E[NE].date_naissance.annee);

    } while (E[NE].date_naissance.jours <= 0 || E[NE].date_naissance.jours >= 32 || E[NE].date_naissance.mois <= 0 || E[NE].date_naissance.mois > 12 || E[NE].date_naissance.annee >= 2007);
    printf("La note d'etudiant : \n");
    scanf("%d",&E[NE].note);
    do
    {
        printf("Departements :\n \t1- 1- Math | 2- Physique | 3- Informatique | 4- Economie  \n");
        printf("Entrer : \n");
        scanf("%d", &choix);

    } while (choix <= 0 || choix >= 5);
     switch (choix) {
        case 1:
            strcpy(E[NE].depatement, Depatement1);
            break;
        case 2:
            strcpy(E[NE].depatement, Depatement2);
            break;
        case 3:
            strcpy(E[NE].depatement, Depatement3);
            break;
        case 4:
            strcpy(E[NE].depatement, Depatement4);
            break;
        default:
            printf( "Inconnu");
            break;
    }
};

// Ajouter plusieurs :
AjouterMany(){

};


int main(){
    AjouterOne();

    return 0;

}
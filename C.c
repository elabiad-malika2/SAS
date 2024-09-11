#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define Depatement1 'Math'
#define Depatement2 'Physique'
#define Depatement3 'Informatique'
#define Depatement4 'Economie'
#define max_etudiants 100

typedef struct
{
    int jours, mois, annee;
} date;

typedef struct
{
    int id;
    char nom[100];
    char prenom[100];
    date date_naissance;
    char depatement[100];
    float note;
} etudiants;

etudiants E[100];

int NE = 0;

// Ajouter les Etudiants :
// Ajouter one :
void AjouterOne()
{
    int choix;
    E[NE].id = NE + 1;
    printf("Le nom d'etudiant : ");
    scanf("%[^\n]", E[NE].nom);
    getchar();

    printf("Le prenom d'etudiant : ");
    scanf("%[^\n]", E[NE].prenom);
    getchar();

    do
    {
        printf("Entrez le deadline sous forme (jj-mm-dd) : ");
        scanf("%d-%d-%d", &E[NE].date_naissance.jours, &E[NE].date_naissance.mois, &E[NE].date_naissance.annee);

    } while (E[NE].date_naissance.jours <= 0 || E[NE].date_naissance.jours >= 32 || E[NE].date_naissance.mois <= 0 || E[NE].date_naissance.mois > 12 || E[NE].date_naissance.annee >= 2007);

    do
    {
        printf("Departements :\n \t1- 1- Math | 2- Physique | 3- Informatique | 4- Economie  \n");
        printf("Entrer : \n");
        scanf("%d", &choix);

    } while (choix <= 0 || choix >= 5);
    switch (choix)
    {
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
        printf("Inconnu");
        break;
    }
    printf("La note d'etudiant : \n");
    scanf("%.2f", &E[NE].note);
};

// Ajouter plusieurs :
void AjouteMultiple()
{
    int nb, i;
    printf("Combien de etudiants voulez-vous ajouter ? ");
    scanf("%d", &nb);
    if (nb > 0 && (NE + nb) < max_etudiants)
    {
        for (i = 0; i < nb; i++)
        {
            printf("\nAjout de l'etudiant %d:\n", i + 1);
            AjouterOne();
        }
    }
    else
    {
        printf("Erreur : Vous ne pouvez pas ajouter plus de %d etudiants.\n", max_etudiants - NE);
    }
}

// Modifier Etudiant :
void Modifier()
{
    int id, choix;
    if (NE == 0)
    {
        printf("Aucun etudiant a modifie");
    }
    printf("Entrer l'id d'etudiant : ");
    scanf("%d", &id);
    if (id < 0 || id > NE)
    {
        printf("ID invalid");
    }
    id--;
    printf("Vous voulez moidier : \n");
    printf("\t\t 1.Nom.\n");
    printf("\t\t 2.Prenom.\n");
    printf("\t\t 3.Date de naissance.\n");
    printf("\t\t 4.Departement.\n");
    printf("\t\t 5.Note.\n");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        printf("Entrer le nom a modifie : ");
        scanf("%s[^/n]", E[id].nom);
        getchar();
        printf("Le nom est modifie avec succes.\n");
        break;
    case 2:
        printf("Entrer le prenom a modifie : ");
        scanf("%s[^/n]", E[id].prenom);
        getchar();
        printf("Le prenom est modifie avec succes.\n");
        break;
    case 3:
        printf("Entrer la date a modifie : ");
        do
        {
            scanf("%d-%d-%d", &E[NE].date_naissance.jours, &E[NE].date_naissance.mois, &E[NE].date_naissance.annee);

        } while (E[NE].date_naissance.jours <= 0 || E[NE].date_naissance.jours >= 32 || E[NE].date_naissance.mois <= 0 || E[NE].date_naissance.mois > 12 || E[NE].date_naissance.annee >= 2007);
        printf("La date est modifie avec succes.\n");
        break;
    case 4:
        printf("Entrer la date a modifie : \n");

        do
        {
            printf("Departements :\n \t1- 1- Math | 2- Physique | 3- Informatique | 4- Economie  \n");
            printf("Entrer : \n");
            scanf("%d", &choix);

        } while (choix <= 0 || choix >= 5);
        switch (choix)
        {
        case 1:
            strcpy(E[id].depatement, Depatement1);
            break;
        case 2:
            strcpy(E[id].depatement, Depatement2);
            break;
        case 3:
            strcpy(E[id].depatement, Depatement3);
            break;
        case 4:
            strcpy(E[id].depatement, Depatement4);
            break;
        default:
            printf("Inconnu");
            break;
        }
        break;
    case 5:
        printf("Entrer la note a modifie : ");
        scanf("%.2f",&E[id].note);
        printf("La note est modifie avec succes.\n");
        break;


    default:
        printf("choix invalide. \n");
        break;
    }
};
            // Supprimer etudiants
void Supprimer(){
    int id;
    if (NE==0)
    {
        printf("Aucun etudiant a supprimer");
    }
    printf("Entrer l'id d'etudiant a supprime : ");
    scanf("%d",&id);
    if (id<=0 && id>NE)
    {
        printf("ID invalid");
    }
    id--;
    for (int i = 0; i < NE-1; i++)
    {
        
        E[i+1]=E[i];
    }
    
    NE--;
    printf("l'etudiant est supprime");
    

};
                 // Moyenne
// Moyenne par departement :
void MoyenneDepartement(){
    int countMath=0 , countPh=0 , countInfo, countEco=0;
    float sumMath=0 ,sumPh=0 , sumInfo=0 , sumEco=0;

    for (int i = 0; i < NE; i++)
    {
        if (strcmp(E[i].depatement,Depatement1)==0)
    {
        sumMath+=E[i].note;
        countMath++;
    }
       else if (strcmp(E[i].depatement,Depatement2)==0)
    {
        sumPh+=E[i].note;
        countPh++;
    }
      else if (strcmp(E[i].depatement,Depatement3)==0)
    {
        sumInfo+=E[i].note;
        countInfo++;
    }
      else if (strcmp(E[i].depatement,Depatement4)==0)
    {
        sumEco+=E[i].note;
        countEco++;
    }
    }
    if (countMath>0)
    {
        printf("Moyenne Math : %.2f \n",sumMath/countMath);
    }else{
        printf("Pas d'etudiants en Math\n");
    }
    if (countPh>0)
    {
        printf("Moyenne Physique : %.2f \n",sumPh/countPh);
    }else{
        printf("Pas d'etudiants en Physique\n");
    }
    if (countInfo>0)
    {
        printf("Moyenne Informatique : %.2f \n",sumInfo/countInfo);
    }else{
        printf("Pas d'etudiants en Informatique\n");
    }
    if (countEco>0)
    {
        printf("Moyenne Economie : %.2f \n",sumEco/countEco);
    }else{
        printf("Pas d'etudiants en Economie\n");
    }
    
};

// Moyenne de toute universite :
void MoyenneUniversite(){
    int countDep=0;
    float sumDep=0;

    for (int i = 0; i < NE; i++)
    {
        sumDep+=0;
        countDep++;
    }
    if (countDep>0)
    {
       printf("Moyenne de l'universite: %.2f\n",sumDep/countDep);
    }
    else{
        printf("Pas d'etudiants dans l'universite");
    }
    

};

int main()
{
    AjouteMultiple();

    return 0;
}
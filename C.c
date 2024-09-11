#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define Depatement1 "Math"
#define Depatement2 "Physique"
#define Depatement3 "Informatique"
#define Depatement4 "Economie"
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
    char status[50];
} etudiants;

etudiants E[100];

int NE = 0;

// Ajouter les Etudiants :
// Ajouter one :
void AjouterOne()
{
    int choix;
    E[NE].id = NE+1;
    printf("Le nom d'etudiant : ");
    scanf(" %[^\n]", E[NE].nom);
    getchar();

    printf("Le prenom d'etudiant : ");
    scanf(" %[^\n]", E[NE].prenom);
    getchar();

    do
    {
        printf("Entrez le deadline sous forme (jj-mm-dd) : ");
        scanf("%d-%d-%d", &E[NE].date_naissance.jours, &E[NE].date_naissance.mois, &E[NE].date_naissance.annee);

    } while (E[NE].date_naissance.jours <= 0 || E[NE].date_naissance.jours >= 32 || E[NE].date_naissance.mois <= 0 || E[NE].date_naissance.mois > 12 || E[NE].date_naissance.annee >= 2007);

    do
    {
        printf("Departements :\n \t- 1- Math | 2- Physique | 3- Informatique | 4- Economie  \n");
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
    scanf("%f", &E[NE].note);
    NE++;
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

// Affichage les details des etudiants
void Affiche(){
    printf("\t\t+--------------------------------------------------------------------------------------------+\n");
    printf("\t\t| Id |        Nom         |      Prenom     | Date Naissance |    Departement   |    Note    |\n");
    printf("\t\t+--------------------------------------------------------------------------------------------+\n");
    for (int i = 0; i < NE; i++)
    {
       printf("\t\t| %-2d | %-20s | %-20s | %2d-%2d-%4d  | %-11s | %.2f |\n", E[i].id, E[i].nom, E[i].prenom, E[i].date_naissance.jours, E[i].date_naissance.mois, E[i].date_naissance.annee, E[i].depatement,E[i].note);
    }
    printf("\t\t+----------------------------------------------------------------------------------------------+\n");
};

// Modifier Etudiant :
void Modifier()
{
    int id, choix,choix2;
    if (NE == 0)
    {
        printf("Aucun etudiant a modifie");
        return;
    }
    Affiche();
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
    getchar();

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
            scanf("%d-%d-%d", &E[id].date_naissance.jours, &E[id].date_naissance.mois, &E[id].date_naissance.annee);

        } while (E[id].date_naissance.jours <= 0 || E[id].date_naissance.jours >= 32 || E[id].date_naissance.mois <= 0 || E[id].date_naissance.mois > 12 || E[id].date_naissance.annee >= 2007);
        printf("La date est modifie avec succes.\n");
        break;
    case 4:
        printf("Entrer le departement a modifie : \n");

        do
        {
            printf("Departements :\n \t1- 1- Math | 2- Physique | 3- Informatique | 4- Economie  \n");
            printf("Entrer : ");
            scanf("%d", &choix2);

        } while (choix2 <= 0 || choix2 >= 5);
        switch (choix2)
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
    Affiche();
    printf("Entrer l'id d'etudiant a supprime : ");
    scanf("%d", &id);
    if (id<=0 && id>NE)
    {
        printf("ID invalid. \n");
    }
    id--;
    for (int i = id; i < NE-1; i++)
    {

        E[i]=E[i+1];
    }

    NE--;
    printf("l'etudiant est supprime.\n");


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
        sumDep+=E[i].note;
        countDep++;
    }
    if (countDep>0)
    {
       printf("Moyenne de l'universite: %.2f\n",sumDep/countDep);
    }
    else{
        printf("Pas d'etudiants dans l'universite.\n");
    }


};
// affich
void afficheEt(etudiants e){
    printf("Etudiant trouvee :\n");
                printf("ID: %d\n", e.id);
                printf("Nom: %s\n", e.nom);
                printf("Prenom: %s\n", e.prenom);
                printf("Date de naissance: %d-%d-%d\n", e.date_naissance.jours, e.date_naissance.mois, e.date_naissance.annee);
                printf("Departement : %s \n", e.depatement);
                printf("Note: %f\n", e.note);

}
            // La recherche d'etudiant :
void Recherche(){
    char nom[50];
    char depart[50];
    int choix,trouve;
    printf("Cherchez l'etudiant que vous voulez \n");
    printf("1.Rechercher un etudiant par son nom.\n");
    printf("2.Recher la liste des etudiants inscrits dans un departement specifique. \n");
    scanf("%d",&choix);
    getchar();
    switch (choix)
    {
    case 1:
        printf("Entrez le nom d'etudiants : ");
        scanf("%[^\n]", nom);
        getchar();
        for (int i = 0; i < NE; i++)
        {
            if (strcmp(E[i].nom,nom)==0)
        {
                afficheEt(E[i]);
                printf("\t\t*************************************************\n");
                trouve = 1;
        }

        }
        if (trouve != 1)
        {
            printf("Aucun etudiant trouver avec le nom %s.\n", nom);
        }
        break;
    case 2 :
        printf("Entrez une departement : ");
        scanf("%[^\n]", depart);
        for (int i = 0; i < NE; i++)
        {
            if (strcmp(E[i].depatement,depart)==0)
        {
                afficheEt(E[i]);
                printf("\t\t*************************************************\n");
                trouve = 1;

        }

        }
         if (trouve != 1)
        {
            printf("Aucune departement trouver avec le nom %s.\n", depart);
        }
        break;

    default:
        printf("Choix Invalid");
        break;
    }

};

            // Triage
// tri Alphabetique
void triAlph(){
    for (int i = 0; i < NE-1; i++)
    {
        for (int j = i+1; j < NE; j++)
        {
            if (strcasecmp(E[i].nom,E[j].nom)<0)
            {
                etudiants temp =E[j];
                E[j]=E[i];
                E[i]=temp;
            }

        }

    }
    Affiche();

};
// tri plus eleve au plus faibe
void triNote(){
    for (int i = 0; i < NE-1; i++)
    {
        for (int j = i+1; j < NE; j++)
        {
            if (E[i].note<E[j].note)
            {
                etudiants temp=E[j];
                E[j]=E[i];
                E[i]=temp;

            }

        }

    }
    Affiche();



};
void status(char *status,float note){
    if (note>=10)
        {
            if (note>=10 && note<=12)
            {
                strcpy(status,"Passable");

            }
            else if ( note<=14)
            {
                strcpy(status,"Assez-bien");

            }
            else if ( note<=16)
            {
                strcpy(status,"bien");

            }
            else
            {
                strcpy(status,"Excellent");

            }

        }
};
void triStatus(){
      for (int i = 1; i < NE; i++)
    {
        float temp = E[i].note;
        int j = i - 1;
        while (temp > E[j].note && j >= 0)
        {
            E[j + 1].note = E[j].note;
            j--;
        }
        E[j + 1].note = temp;
    }
    char sta[50];
    for (int i = 0; i < NE; i++)
    {
        status(&sta,E[i].note);
        printf("\t\t| %2d | %10s | %10s | %2d-%2d-%4d | %14s | %10.2f | %15s |\n",
               E[i].id, E[i].nom, E[i].prenom, E[i].date_naissance.jours, E[i].date_naissance.mois, E[i].date_naissance.annee, E[i].depatement, E[i].note, sta);
    }



};

void Triage(){
    int choix ;
    printf("\t\tMenu triage :\n");
        printf("\t\t1. tri alphabetique.\n");
        printf("\t\t2. tri moyenne general\n");
        printf("\t\t3. tri par status de reussite\n");
        printf("\t\tEnter votre choix (1-3): ");
        scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        triAlph();
        break;
    case 2:
        triNote();
        break;
    case 3:
        triStatus();
        break;

    default:
        break;
    }

};
            // Statistiques
// Afficher le nombre total des etudiants
void AfficherNbrEt(){
    printf("Le nombre d'etudiant inscrit : %d", NE);

};
// Afficher le nombre des etudiants par departement
void AfficheNbEtDep(){
     int countMath=0 , countPh=0 , countInfo, countEco=0;


    for (int i = 0; i < NE; i++)
    {
        if (strcmp(E[i].depatement,Depatement1)==0)
    {

        countMath++;
    }
       else if (strcmp(E[i].depatement,Depatement2)==0)
    {

        countPh++;
    }
      else if (strcmp(E[i].depatement,Depatement3)==0)
    {

        countInfo++;
    }
      else if (strcmp(E[i].depatement,Depatement4)==0)
    {

        countEco++;
    }
    }
    if (countMath>0)
    {
        printf("Le nombres des etudiants qui sont inscrit dans Math : %d \n",countMath);
    }else{
        printf("Pas d'etudiants en Math\n");
    }
    if (countPh>0)
    {
        printf("Le nombres des etudiants qui sont inscrit dans Physique : %.d \n",countPh);
    }else{
        printf("Pas d'etudiants en Physique\n");
    }
    if (countInfo>0)
    {
        printf("Le nombres des etudiants qui sont inscrit dans Informatique : %d \n",countInfo);
    }else{
        printf("Pas d'etudiants en Informatique\n");
    }
    if (countEco>0)
    {
        printf("Le nombres des etudiants qui sont inscrit dans Economie : %d \n",countEco);
    }else{
        printf("Pas d'etudiants en Economie\n");
    }

};
// Afficher les etudiants ayant une moyenne superieure a un seuil :
void AfficherSeuil(){
    float seuil ;
    printf("Veuillez entrer le seuil : ");
    scanf("%f",&seuil);
    for (int i = 0; i < NE; i++)
    {
        if (E[i].note>seuil)
        {
            afficheEt(E[i]);
        }

    }


};
// les 3 meilleurs etudiants :
void Affichemeil(){
    triNote();
    for (int i = 0; i < 3; i++)
    {
        afficheEt(E[i]);
    }

};
// Afficher nbre ayant la note supperieure a 10
void afficheSup(){
    for (int i = 0; i < NE; i++)
    {
        if (E[i].note>=10)
        {
            afficheEt(E[i]);
        }

    }


};
void Statistiques(){

    int choix;
    printf("1. Nombre total des etudiants\n2. Nombre des etudiants par departement\n3. Etudiants ayant une note superieure à un seuil\n4. Top 3 etudiants\n5. Nombre des etudiants ayant reussi par departement\n");
                printf("Choisissez une option: ");
                scanf("%d", &choix);
                switch (choix) {
                    case 1:
                        AfficherNbrEt();
                        break;
                    case 2:
                        AfficheNbEtDep();
                        break;
                    case 3:
                        AfficherSeuil();
                        break;
                    case 4:
                        Affichemeil();
                        break;
                    case 5:
                        afficheSup();
                        break;
                    default:
                        printf("Option invalide.\n");
                        break;
                }

};



void programmeMenu() {
    int choix;
    do {
        printf("\t\n**************** Ecole Youcode ***************\n");
        printf("\t1.  Ajouter un etudiant\n");
        printf("\t2.  Ajouter plusieurs etudiants\n");
        printf("\t3.  Modifier un etudiant\n");
        printf("\t4.  Supprimer un etudiant\n");
        printf("\t5.  Afficher la moyenne generale par departement\n");
        printf("\t6.  Afficher la moyenne de l'universite\n");
        printf("\t7.  Afficher les details des etudiants\n");
        printf("\t8.  Rechercher un etudiant\n");
        printf("\t9.  Tri des etudiant\n");
        printf("\t10. Afficher les statistiques\n");
        printf("\t11. Quitter\n\n");
        printf("\t\n**********************************************\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                system("cls");
                AjouterOne();
                break;
            case 2:
                system("cls");
                AjouteMultiple();
                break;
            case 3:
                system("cls");
                Modifier();
                break;
            case 4:
                system("cls");
                Supprimer();
                break;
            case 5:
                system("cls");
                MoyenneDepartement();
                break;
            case 6:
                system("cls");
                MoyenneUniversite();
                break;
            case 7:
                system("cls");
                Affiche();
                break;
            case 8:
                system("cls");
                Recherche();
                break;
            case 9:
                system("cls");
                Triage();
                break;
            case 10:
                system("cls");
                Statistiques();
                break;
            case 11 :
                return;


            default:
                printf("Option invalide. Veuillez reessayer.\n");
                break;
        }
    } while (choix != 11);
}
void InitialiserEtudiants() {
    // Exemples d'etudiants
    etudiants exemples[10] = {
        {1, "Dupont", "Pierre", {1, 1, 2000}, Depatement1, 12.5, "Passable"},
        {2, "Durand", "Marie", {2, 2, 2001}, Depatement2, 14.0, "Assez-bien"},
        {3, "Martin", "Jean", {3, 3, 2002}, Depatement3, 16.5, "Bien"},
        {4, "Lemoine", "Sophie", {4, 4, 2003}, Depatement4, 17.0, "Excellent"},
        {5, "Dubois", "Luc", {5, 5, 2004}, Depatement1, 10.0, "Passable"},
        {6, "Leroy", "Chantal", {6, 6, 2005}, Depatement2, 11.5, "Passable"},
        {7, "Petit", "Claude", {7, 7, 2006}, Depatement3, 15.0, "Assez-bien"},
        {8, "Gauthier", "elise", {8, 8, 2007}, Depatement4, 13.0, "Assez-bien"},
        {9, "Rousseau", "Alain", {9, 9, 2004}, Depatement1, 18.0, "Excellent"},
        {10, "Moulin", "Alice", {10, 10, 2003}, Depatement2, 12.0, "Passable"}
    };

    // Copier les valeurs dans le tableau global E
    for (int i = 0; i < 10; i++) {
        E[i] = exemples[i];
    }
    NE = 10; // Nombre d'etudiants initialises
}

int main()
{
    InitialiserEtudiants();
    programmeMenu();

    return 0;
}

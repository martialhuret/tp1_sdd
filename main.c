#include "liste.h"

void main () {
    
    T_Liste maliste = NULL;
    T_Elt e0 = 99;
    T_Elt e1 = 88;
    T_Elt e2 = 77;
    T_Elt e3 = 66;
    maliste = newMaille(1, maliste);
    maliste = newMaille(2, maliste);
    maliste = newMaille(3, maliste);
    int valeur;
    int choix;

    do {
        choix = menu();
        switch(choix)
        {
            case 1:
                printf("\nObjectif 1\n");
                printf("Réussi : il faut tester l'objectif 2 pour le voir\n");
                break;
            
            case 2:
                printf("\nObjectif 2\n");

                printf("Affichage itératif:\n");
                afficherListe(maliste);

                printf("Affichage récursif:\n");
                afficherListeRec(maliste);
                break;

            case 3:
                printf("\nObjectif 3\n");

                printf("\nInsertion en tête de liste\n");
                maliste = insererEnTete(&e0, maliste);

                printf("\nAffichage :\n");
                afficherListe(maliste);

                printf("\nInsertion 2 en tête de liste\n");
                insererEnTete2(&e1, &maliste);

                printf("\nAffichage :\n");
                afficherListe(maliste);  
                break;

            case 4:
                printf("\nObjectif 4\n");
                
                printf("\nInsertion en fin de liste\n");
                maliste = insererEnFin(&e2, maliste);

                printf("\nAffichage :\n");
                afficherListe(maliste);

                printf("\nInsertion 2 en fin de liste\n");
                maliste = insererEnFinRec(&e3, maliste);

                printf("\nAffichage :\n");
                afficherListe(maliste);  
                break;

            case 5:
                printf("\nObjectif 5\n");
            
                printf("\nQuelle valeur à tester ?");
                scanf("%d", &valeur);
                printf("%d appartient à la liste (itératif) ? ",valeur);
                if (appartient(valeur, maliste)) {
                    printf(" : OUI\n");
                }
                else {
                    printf(" : NON\n");
                }

                printf("\nQuelle valeur à tester ?");
                scanf("%d", &valeur);
                printf("%d appartient à la liste (récursif) ? ",valeur);
                if (appartientRec(valeur, maliste)) {
                    printf(" : OUI\n");
                }
                else {
                    printf(" : NON\n");
                }
        
                break;

            case 6:
                printf("\nObjectif 6\n");
                
                printf("\nQuelle valeur à insérer ? ");
                scanf("%d", &valeur);
                maliste = insererAvecOrdre(valeur, maliste);
                printf("%d est inséré dans la liste\n",valeur);
                afficherListe(maliste);

                break;

            case 7:
                printf("\nObjectif 7\n");

                printf("\nQuelle valeur à supprimer ? ");
                scanf("%d", &valeur);
                maliste = supprimerElement(valeur, maliste);
                printf("%d est supprimé de la liste\n",valeur);
                afficherListe(maliste);

                break;

            case 8:
                printf("\nObjectif 8\n");

                printf("\nQuelle est la taille de la liste ? ");
                printf("%d\n", tailleListe(maliste));

                break;
        }
    } while (choix != 0);
}


int menu()
{
    int choix;
    printf("\n\n\n TP LISTES CHAINEES\n");
    printf("\n 1 : Objectif 1: déclarer une liste");
    printf("\n 2 : Objectif 2: afficher la liste");
    printf("\n 3 : Objectif 3: insérer en tête de liste");
    printf("\n 4 : Objectif 4: insérer en fin de liste");
    printf("\n 5 : Objectif 5: telle valeur appartient ?");
    printf("\n 6 : Objectif 6: insérer avec ordre");
    printf("\n 7 : Objectif 7: suprrimer l'élément");
    printf("\n 8 : Objectif 8: taille de la liste");
    printf("\n 0 : QUITTER \n ");
    printf("\n votre choix ?  ");
    scanf("%d",&choix);

    return choix;
}
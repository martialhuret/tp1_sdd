#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "liste.h"


char * strtoupper( char * dest, const char * src ) { //transforme la chaine pointee par src en son equivalent en MAJUSCULE qui sera pointé par dest
    char * result = dest;
    while( *dest++ = toupper( *src++ ) );
    return result;
}

void supprimerPremierCaractere(char *chaine) {
    int longueur = strlen(chaine);
    
    // Vérifie si la chaîne est vide ou a seulement un caractère
    if (longueur <= 1) {
        chaine[0] = '\0'; // Remplace le premier caractère par un caractère nul pour vider la chaîne ou laisser une chaîne vide
    } else {
        // Déplace tous les caractères d'un indice vers la gauche
        for (int i = 0; i < longueur - 1; i++) {
            chaine[i] = chaine[i + 1];
        }
        chaine[longueur - 1] = '\0'; // Place un caractère nul à la fin de la chaîne
    }
}

int main()
{
    
    T_Maille *l=NULL;
    T_Elt e;
    
    int i,numLigne=1;
    
    FILE * fic=NULL;
    char mot[26];
    char motMAJ[26];
    char *pmotMAJ=NULL;
    int n=0;
    char c;
    fic=fopen("constitution.txt","r");
    
    do
    {
        i=0;
        do
        {
            c=fgetc(fic);
           if ((c != ' ' && c != '\n' && c != EOF) && !(c >= 33 && c <= 57) && !(c >= 91 && c <= 96) && !(c >= 123 && c <= 126))
                mot[i++] = c;
            else
            {
                if (c == '\n')
                    numLigne++;
            }
        }while((c!=' ' && c!='\n' && c!=EOF));

        mot[i]='\0';
  
        n++;
        if (strcmp(mot," ")!=0 && strcmp(mot,"\n")!=0 && strcmp(mot,"")!=0 ) 
        {
            
            
            printf("\nlu en ligne %d : -%s-  ", (c=='\n'?numLigne-1:numLigne), strtoupper(motMAJ,mot) ); //getchar();
            l = insererAvecOrdre(motMAJ, l);
            pmotMAJ=motMAJ;
            if (strchr(mot,'\'')==(mot+1)) {pmotMAJ=motMAJ+2; printf(" -->> -%s-",pmotMAJ);}
            if (strchr(pmotMAJ,'.')!=NULL || strchr(pmotMAJ,',')!=NULL) {pmotMAJ[strlen(pmotMAJ)-1]='\0'; printf(" -->> -%s-",pmotMAJ);}

        }
            
    }
    while(c!=EOF);
    printf("\n\n %d mots lus.\n",n);
    afficherListe(l);

    printf("\n\n");

    fclose(fic);
    
    
    

    
    return 0;
}

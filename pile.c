#include "pile.h"



void testPile(T_PileD * P)
{
    /*
    T_Elt z;
    initPile(P);
    empiler(P,1.8);
    empiler(P,2);
    empiler(P,3.4);
    empiler(P,4);
    empiler(P,5);
    empiler(P,6);
    afficherPile(P);
    depiler(P,&z);
    afficherPile(P);
    afficherElt(&z);
    */

    
    initPile(P);
    char string[20];
    strcpy(string, "(3+4)*(5-2)");
    toRPN(string,P);
    printf("\n");
    
    
    //tourDeHanoi(3);
    
}

void initPile( T_PileD * P)
{
    P->Elts=(T_Elt *)malloc(SEUIL*sizeof(T_Elt));
    P->nbElts=0; //important
    assert(P->Elts);
    //printf("\nInitialisation reussie de la pile dynamique");
}


int pilepleine(T_PileD *P)
{
    int nouvelleTaille;
    if (P->nbElts%SEUIL==0) {
        nouvelleTaille=((P->nbElts/SEUIL)+1)*SEUIL;
        P->Elts = realloc(P->Elts,nouvelleTaille*sizeof(T_Elt));
        //printf("\n ==> La pile est de taille %d",nouvelleTaille);
    }
    assert(P->Elts);
return 0; 
}


int pilevide(const  T_PileD *P)
{
    return (P->nbElts==0);
}



int empiler( T_PileD *P, T_Elt e) //renvoie 0 si pile pleine, sinon 1
{
    if (pilepleine(P)==0) {
        P->Elts[P->nbElts]=e;
        P->nbElts++;
        return 1;
    }
    return 0;
}



int depiler( T_PileD *P, T_Elt *pelt) //renvoie 0 si pile vide, sinon 1
{
    int nouvelleTaille;
    if (!pilevide(P))
        {
            *pelt=P->Elts[--P->nbElts];
            if (P->nbElts>0 && P->nbElts%SEUIL==0)
            {
                nouvelleTaille=(P->nbElts);
                P->Elts=realloc(P->Elts,nouvelleTaille*sizeof(T_Elt));
                //printf("\n==> La pile est de taille %d ",nouvelleTaille);
                assert(P->Elts);
            }
        return 1;
        }
return 0;
}



T_Elt sommet(const  T_PileD *P)
{
    return P->Elts[P->nbElts-1];
}



int hauteur(const  T_PileD *P)
{
return 0;
}


void afficherPile(  T_PileD *P)
{
    //afficher avec empliler et depiler
    T_PileD P2;
    initPile(&P2);
    T_Elt e;
    printf("\n");
    while (!pilevide(P))
    {
        depiler(P,&e);
        afficherElt(&e);
        empiler(&P2,e);
    }
    while (!pilevide(&P2))
    {
        depiler(&P2,&e);
        empiler(P,e);
    }

    printf("\n");
}


void toRPN(char * string, T_PileD *P){
    int i = 0;
    printf("%s\n", string);
    char c;
    while (string[i] != '\0')
    {
        c = string[i];
        if (c == '(')
        {
            empiler(P, c);
        }
        else if (c == '+' || c == '-' || c == '/' || c == '*')
            {
                if (pilevide(P))
                {
                    empiler(P,c);
                }
                else if (sommet(P) == '(')
                {
                    empiler(P, c);
                }
                else if (c == '*' || c == '/'){
                    if (sommet(P) == '+' || sommet(P) == '-'){
                        empiler(P, c);
                    }
                    else {
                        depiler(P, &c);
                        afficherElt(&c);
                        empiler(P, c);
                    }
                }
            }
        else if (c == ')')
        {
            while (sommet(P) != '('){
                depiler(P, &c);
                afficherElt(&c);
            }
            depiler(P, &c);
        }

        else 
        {
            afficherElt(&c);
        }                      

        i++;
    }

    while (!pilevide(P)){
        depiler(P, &c);
        printf("%c", c);
    }

    printf("\n");

}


void tourDeHanoi(int N){

}
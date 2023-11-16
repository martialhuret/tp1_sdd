#include "pile.h"



void testPile(T_PileD * P1, T_PileD * P2, T_PileD * P3)
{ 
    int i = 0;

    initPile(P1);
    initPile(P2);
    initPile(P3);

    empiler(P1, 3);
    empiler(P1, 2);
    empiler(P1, 1);
    
    Hanoi(P1, P2, P3, 3, P1, P2, P3, &i);

    printf("Nombre de mouvements : %d\n", i);

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
    return P->nbElts;
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

void Hanoi (T_PileD *A, T_PileD *B, T_PileD *C, int n,T_PileD *p1, T_PileD *p2, T_PileD *p3, int *i){
    *i+=1;
    if (n == 1){
        depiler(A, &n);
        empiler(C, n);
        afficher3pile(p1, p2, p3);
    }
    else {
        Hanoi(A, C, B, n-1,p1,p2,p3,i);
        depiler(A, &n);
        empiler(C, n);
        afficher3pile(p1, p2, p3);
        Hanoi(B, A, C, n-1,p1,p2,p3,i);
          
    }
}

int max(int a, int b, int c){
    if (a > b && a > c){
        return a;
    }
    else if (b > a && b > c){
        return b;
    }
    else {
        return c;
    }
}

void afficher3pile(T_PileD *A, T_PileD *B, T_PileD *C) {
    int max_height = max(hauteur(A), hauteur(B), hauteur(C));

    for (int i = max_height - 1; i >= 0; i--) {
        char elt_A = (i < hauteur(A)) ? A->Elts[i] + '0' : ' ';
        char elt_B = (i < hauteur(B)) ? B->Elts[i] + '0' : ' ';
        char elt_C = (i < hauteur(C)) ? C->Elts[i] + '0' : ' ';

        printf("%c | %c | %c \n", elt_A, elt_B, elt_C);
       
    }
    printf("----------\n\n");
}
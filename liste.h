#include "es.h" 
#include <stdlib.h>
#define listeVide(L) L==NULL

typedef struct maille {
    T_Elt elt; // type T_Elt toujours déclaré dans es.h
    struct maille *suivant; //ici se trouve l’auto référence
    // struct maille *precedent; //à mettre en oeuvre plus tard
}T_Maille ;

typedef struct T_Maille * T_Liste;


T_Maille *newMaille(T_Elt e, T_Maille * m);

int afficherListe(T_Maille * m);
int afficherListeRec(T_Maille *m);

T_Maille *insererEnTete(T_Elt *,T_Maille *);
void insererEnTete2(T_Elt *,T_Maille **);

T_Maille *insererEnFin(T_Elt *,T_Maille *);
T_Maille *insererEnFinRec(T_Elt *,T_Maille *);

int appartient(T_Elt , T_Maille *);
int appartientRec(T_Elt , T_Maille *);

T_Maille *insererAvecOrdre(T_Elt , T_Maille *);

T_Maille *supprimerElement(T_Elt e, T_Maille *m);

int tailleListe(T_Maille *);
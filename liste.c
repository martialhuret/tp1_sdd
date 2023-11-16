#include "liste.h"
//#define UTILISE_INT 
#define UTILISE_CHAR




#ifdef UTILISE_INT
T_Maille *newMaille(T_Elt e, T_Maille * m){
    if (appartient(e, m)) return m;

    T_Maille *m2;
    m2 = (T_Maille *)malloc(sizeof(T_Maille));
    affecterElt(&(m2->elt), &e);
    m2 -> suivant = m;
    return m2;
}

int afficherListe(T_Maille * m){
    if (m == NULL) {
        printf("Liste vide\n");
        return 0;
    }
    while (m != NULL) {
        afficherElt(&(m->elt));
        m = m->suivant;
        if (m != NULL) printf(" -> ");
    }
    
    printf("\n");
    return 1;    
}

int afficherListeRec(T_Maille *m){
    if (m == NULL) {
        printf("Liste vide\n");
        return 0;
    }
    afficherElt((m->elt));
    if (m->suivant != NULL) {
        printf(" -> ");
        afficherListeRec(m->suivant);
    }
    else {
        printf("\n");
    }
    return 1;
}
    
T_Maille *insererEnTete(T_Elt * e,T_Maille *m){
    return newMaille(*e, m);
}

void insererEnTete2(T_Elt *e,T_Maille ** m){
    *m = insererEnTete(e, *m);    
}

T_Maille *insererEnFin(T_Elt * e,T_Maille * m){
    if (appartient(*e, m)) return m;
    T_Maille * tete=m;
    if (m == NULL) {
        return newMaille(*e, NULL);
    }
    while (m->suivant != NULL) {
        m = m->suivant;
    }
    m->suivant= newMaille(*e, NULL);
    
    return tete;
}

T_Maille *insererEnFinRec(T_Elt * e,T_Maille * m){
    if (appartient(*e, m)) return m;
    if (listeVide(m) != NULL) {
        return newMaille(*e, NULL);
    }
    m->suivant = insererEnFinRec(e, m->suivant);
    return m;
}

int appartient(T_Elt e, T_Maille * m){
    if (listeVide(m)) {
        return 0;
    }
    while (m->suivant != NULL){
        if (e==m->elt) return 1;
        m = m->suivant;
    }
    return 0;
}

int appartientRec(T_Elt e, T_Maille *m){
    if (listeVide(m) != NULL) {
        return 0;
    }
    if (e == m->elt) {
        return 1;
    }
    return appartientRec(e, m->suivant);
}


T_Maille *insererAvecOrdre(T_Elt e, T_Maille * m){
    if (listeVide(m) == 1) {
        return newMaille(e, NULL);
    }

    if (e > m->elt) {
        return newMaille(e, m);
    }

    T_Maille *tete = m;
    while (m->suivant != NULL && e < m->suivant->elt) {
        m = m->suivant;
    }

    m->suivant = newMaille(e, m->suivant);

    return tete;
}

T_Maille *supprimerElement(T_Elt e, T_Maille *m){
    if (listeVide(m) == 1) {
        return m;
    }

    if (e == m->elt) {
        T_Maille *tete = m->suivant;
        free(m);
        return tete;
    }

    T_Maille *tete = m;
    while (m->suivant != NULL && e != m->suivant->elt) {
        m = m->suivant;
    }

    if (m->suivant == NULL) {
        return tete;
    }

    T_Maille *tmp = m->suivant;
    m->suivant = m->suivant->suivant;
    free(tmp);

    return tete;
};

int tailleListe(T_Maille *m){
    if (listeVide(m) == 1) {
        return 0;
    }
    int taille = 1;
    while (m->suivant != NULL) {
        taille++;
        m = m->suivant;
    }
    return taille;
}


#endif

#ifdef UTILISE_CHAR

T_Maille *newMaille(T_Elt e, T_Maille * m){
    if (appartient(e, m)) return m;

    T_Maille *m2;
    m2 = (T_Maille *)malloc(sizeof(T_Maille));
    affecterElt(&(m2->elt), e);
    m2 -> suivant = m;
    return m2;
}

int afficherListe(T_Maille * m){
    if (m == NULL) {
        printf("Liste vide\n");
        return 0;
    }
    while (m != NULL) {
        afficherElt(m->elt);
        m = m->suivant;
        if (m != NULL) printf(" - ");
    }
    return 1;    
}

T_Maille *insererEnTete(T_Elt * e,T_Maille *m){
    return newMaille(*e, m);
}


T_Maille *insererEnFin(T_Elt * e,T_Maille * m){
    if (appartient(*e, m)) return m;
    T_Maille * tete=m;
    if (m == NULL) {
        return newMaille(*e, NULL);
    }
    while (m->suivant != NULL) {
        m = m->suivant;
    }
    m->suivant= newMaille(*e, NULL);
    
    return tete;
}


int appartient(T_Elt e, T_Maille * m){

    if (listeVide(m)) {
        return 0;
    }
    do{
        if (strcmp(e,(m->elt))==0) return 1;
        m = m->suivant;
    }while (m != NULL);
    return 0;
}

T_Maille *insererAvecOrdre(T_Elt e, T_Maille * m){
    if (listeVide(m)) {
        T_Maille *test = insererEnTete(e, m);
        return test;
    }

    if (strcmp(e,m->elt)<0) {
        return insererEnTete(e,m);
    }

    T_Maille *tete = m;
    while (m->suivant != NULL && strcmp(e,m->elt)>0) {
        m = m->suivant;
    }
    m->suivant = newMaille(e, m->suivant);

    return tete;
}


T_Maille *supprimerElement(T_Elt e, T_Maille *m){
    if (listeVide(m)) {
        return m;
    }

    if (e == m->elt) {
        T_Maille *tete = m->suivant;
        free(m);
        return tete;
    }

    T_Maille *tete = m;
    while (m->suivant != NULL && !strcmp(e,(m->suivant->elt))) {
        m = m->suivant;
    }

    if (m->suivant == NULL) {
        return tete;
    }

    T_Maille *tmp = m->suivant;
    m->suivant = m->suivant->suivant;
    free(tmp);

    return tete;
};

int tailleListe(T_Maille *m){
    if (listeVide(m)) {
        return 0;
    }
    int taille = 1;
    while (m->suivant != NULL) {
        taille++;
        m = m->suivant;
    }
    return taille;
}

#endif


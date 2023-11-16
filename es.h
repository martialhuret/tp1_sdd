#include <stdio.h>
#include <string.h>

//#define UTILISE_INT 
#define UTILISE_CHAR

#ifdef UTILISE_INT
typedef int T_Elt; //TAD
#endif


//typedef char T_chaine[50];
//typedef T_chaine T_Elt; //TAD
// ou

#ifdef UTILISE_CHAR
typedef char * T_Elt; //TAD
#endif

void saisirElt(T_Elt );
void afficherElt(T_Elt );
void affecterElt(T_Elt ,T_Elt );







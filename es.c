#include "es.h"

//#define UTILISE_INT 
#define UTILISE_CHAR

/*
// lorsque T_ELt est un int  (c'est le case de notre TP)  
void saisirElt(T_Elt *e)
{
scanf("%.2f",e);
}
void afficherElt(T_Elt *e)
{
printf("\n%.2f",*e);
}
void affecterElt(T_Elt *d,T_Elt *s)
{
*d=*s;
}
*/

#ifdef UTILISE_CHAR
void saisirElt(T_Elt e)
{
scanf("%s",e);
}
void afficherElt(T_Elt e)
{
printf("\n%s",e);
}


void affecterElt(T_Elt d,T_Elt s)
{
strcpy(d,s);
}
#endif

#ifdef UTILISE_INT
void saisirElt(T_Elt *e)
{
scanf("%d",e);
}
void afficherElt(T_Elt *e)
{
printf("%d",*e);
}
void affecterElt(T_Elt *d,T_Elt *s)
{
*d=*s;
}
#endif












// lorsque T_ELt est une chaine (peut être un jour)

/*
void saisirElt(T_Elt e)
{
scanf("%s",e);
}
void afficherElt(T_Elt e)
{
printf("\n%s",*e);
}


void affecterElt(T_Elt d,T_Elt s)
{
strcpy(d,s);
}
*/
















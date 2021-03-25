#include "pile.h"



void initPile( T_Pile * P)
{
    P->nbElts=0;
}


int pilepleine(const  T_Pile *P)
{
    if (P->nbElts==MAX){
        return 1;
    }
    else return 0;
}



int pilevide(const  T_Pile *P)
{
    if (P->nbElts==0){
        return 1;
    }
    else return 0;
}



int empiler( T_Pile *P, T_Elt e) //renvoie 0 si pile pleine, sinon 1
{
    if (pilepleine(P)==1)
    {
        printf("Pile pleine, impossible d'empiler un nouvel élèment");
        return 0;
    }
    else
    {
        printf("Saissez l'élèment à empiler");
        saisirElt(e);
        P->nbElts = P->nbElts +1;
        return 1;
    }
}



int depiler( T_Pile *P, T_Elt *pelt)  //renvoie 0 si pile vide, sinon 1
{
    if (pilevide(P)==1)
    {
        printf("Pile vide, impossible de dépiler élèment");
        return 0;
    }
    else
    {
        affecterElt(pelt,P->Elts[(P->nbElts)-1]);
        P->nbElts = P->nbElts - 1;
        return 1;
    }
}



T_Elt sommet(const  T_Pile *P)
{
return P->Elts[(P->nbElts) - 1];
}



int hauteur(const  T_Pile *P)
{
return P->nbElts;
}


void afficherPile(  T_Pile *P)
{
    for (int i=0;i<(P->nbElts);i++)
    {
        afficherElt(P->Elts[i]);
    }
}









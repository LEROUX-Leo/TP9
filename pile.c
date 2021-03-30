#include "pile.h"

void initPile( T_Pile * P){
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
    if (pilepleine(P)==1){
        printf("\nPile pleine, impossible d'empiler un nouvel élément");
        return 0;
    }
    else{
        P->nbElts = P->nbElts +1;
        affecterElt(&(P->Elts[(P->nbElts)-1]),&e);
        return 1;
    }
}

int depiler( T_Pile *P, T_Elt *pelt)  //renvoie 0 si pile vide, sinon 1
{
    if (pilevide(P)==1){
        printf("\nPile vide, impossible de dépiler élément");
        return 0;
    }
    else{
        affecterElt(pelt,&(P->Elts[(P->nbElts)-1]));
        P->nbElts = P->nbElts - 1;
        return 1;
    }
}

T_Elt sommet(const  T_Pile *P){

	if (pilevide(P)==0){
		return P->Elts[(P->nbElts) - 1];
	}
	else{
		return 0;
	}
}

int hauteur(const  T_Pile *P){
	if (pilevide(P)!=1){
	return (P->nbElts)  ;
	}
	else{
		return 0;
	}
}

void afficherPile(T_Pile *P){
  
    T_Elt aux=0;
    T_Pile P2;
    initPile(&P2);
    int nbr=P->nbElts;
    for (int i=0;i<nbr;i++)
    {
        depiler(P,&aux);
		printf(" ");       
        afficherElt(&aux);
        empiler(&P2,aux);
    }
    for (int i=0;i<nbr;i++)
    {
        depiler(&P2,&aux);
        empiler(P,aux);
    }
}

void testPile(T_Pile *mapile1){

	T_Elt aux1 = 0;
	T_Elt aux2 = 69;

/***************************************************************************/
//TEST PILE VIDE

	printf("\nInitialisation de la pile\n");
	initPile(mapile1);

	printf("\n	TEST AVEC UNE PILE VIDE :\n");

	if(pilepleine(mapile1)==1){
		printf("\nPile pleine");
	} 
	else {
		printf("\nPile non pleine");
	}

	if(pilevide(mapile1)==1){
		printf("\nPile vide");
	} 
	else {
		printf("\nPile non vide");
	}

	if (depiler(mapile1,&aux1)==1){
		printf("L'élément est bien dépilé : ");
		printf("%d",aux1);
	}

	if(sommet(mapile1)==0){
		printf("\nPile vide, impossible d'afficher le sommet");
	}
	else{
		printf("\nSommet de la pile : ");
		printf("%d",sommet(mapile1));
	}
	if(hauteur(mapile1)==0){
		printf("\nPile vide, impossible d'afficher la hauteur");
	}
	else{
		printf("\nHauteur de la pile : ");
		printf("%d",hauteur(mapile1));
	}
	printf("\nAffichage de la pile");


	if (empiler(mapile1,aux2)==1)
	{
		printf("\nL'élément est bien empilé");
	}
	printf("\nAffichage de la pile : ");
	afficherPile(mapile1);

/************************************************************************************/
//PILE NON VIDE ET NON PLEINE

		printf("\n\n	TEST AVEC UNE PILE NON PLEINE ET NON VIDE :\n");
		if(pilepleine(mapile1)==1){
			printf("\nPile pleine");
		} 
		else {
			printf("\nPile non pleine");
		}
		if(pilevide(mapile1)==1){
			printf("\nPile vide");
		} 
		else {
			printf("\nPile non vide");
		}
		if(sommet(mapile1)==0){
			printf("\nPile vide, impossible d'afficher le sommet");
		}
		else{
			printf("\nSommet de la pile :  ");
			printf("%d",sommet(mapile1));
		}
		if(hauteur(mapile1)==0){
			printf("\nPile vide, impossible d'afficher l'hauteur");
		}
		else{
			printf("\nHauteur de la pile : ");
			printf("%d",hauteur(mapile1));
		}
		if (empiler(mapile1,aux2)==1){
			printf("\nL'élément est bien empilé");
		}
		if (depiler(mapile1,&aux1)==1){
			printf("\nL'élément est bien dépilé :  ");
			printf("%d",aux1);
		}
		printf("\nAffichage de la pile : ");
		afficherPile(mapile1);

/***************************************************************************/
//TEST PILE PLEINE

		//On rempli la pile
		printf("\n\n	TEST AVEC UNE PILE PLEINE :\n");
		for (int i=(mapile1->nbElts);i<MAX;i++){
			empiler(mapile1,aux2);
			aux2++;
		}
		if(pilepleine(mapile1)==1){
			printf("\nPile pleine");
		} 
		else {
			printf("\nPile non pleine");
		}
		if(pilevide(mapile1)==1){
			printf("\nPile vide");
		} 
		else {
			printf("\nPile non vide");
		}
		if(sommet(mapile1)==0){
			printf("\nPile vide, impossible d'afficher le sommet");
		}
		else{
			printf("\nSommet de la pile :  ");
			printf("%d",sommet(mapile1));
		}
		if(hauteur(mapile1)==0){
			printf("\nPile vide, impossible d'afficher l'hauteur");
		}
		else{
			printf("\nHauteur de la pile :  ");
			printf("%d",hauteur(mapile1));
		}
		if (empiler(mapile1,aux2)==1){
			printf("\nL'élément est bien empilé");
		}
		if (depiler(mapile1,&aux1)==1){
			printf("\nL'élément est bien dépilé :  ");
			printf("%d",aux1);
		}
		printf("\nAffichage de la pile : ");
		afficherPile(mapile1);
}









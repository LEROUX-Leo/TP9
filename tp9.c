// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)
#include "pile.h"
#include "file.h"

int menu(){

	int choix;
	printf("\n\n SDA1 TP9");
	printf("\n 1 : tester mon fichier pile.c");
	printf("\n 2 : tester mon fichier file.c");
	printf("\n 3 : afficher et compter les permutations d'une chaine");
	printf("\n 4 : afficher et compter les solutions pour un échiquier ");
	printf("\n 0 :  QUITTER  ");
	printf("\n votre choix ?  ");
	scanf("%d",&choix);
	return choix;
}

int main(){

	T_File mafile;
	T_Pile mapile;
	int chx;


	do
	{
	chx=menu();
	switch (chx)
		{
		case 1 :  
			testPile(&mapile); 
			break;

		case 2 : 		
			testFile(&mafile);
			break; 

		case 3 : 
			break;

		case 4 : 
			break;
		}
	}while(chx!=0);

	printf("\nAu plaisir de vous revoir ;)\n");
	return 0;
}

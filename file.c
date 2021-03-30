#include "file.h" 

void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
	ptrF->Tete=-1;
	ptrF->Queue=-1;
}

int retirer(T_File *ptrF) //si pas vide, en tete de file
{
	int i;
	if(ptrF->Queue!=-1){
		for(i=0; i<(ptrF->Queue);i++)	{
			ptrF->Elts[i]=ptrF->Elts[i+1];
		}
		ptrF->Queue--;
		return 1;
	}
	return 0;
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
	if(!filePleine(ptrF)){
		ptrF->Elts[ptrF->Queue+1]=*ptrE;
		ptrF->Queue++;
		ptrF->Tete=0;
		return 1;
	}
	return 0;
} 

int fileVide(const  T_File *ptrF) // qd Tete == -1 
{
	if (ptrF->Tete==-1){
		return 1;
	}
return 0;
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
	if (ptrF->Queue==MAX-1){
		return 1;
	}
return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
		if (ptrF->Tete!=-1){
		return ptrF->Elts[ptrF->Tete];
	}
return -1;
}

void afficherFile(T_File *ptrF)
{
	int i;
	if (ptrF->Tete!=-1){
		printf("[Tête ");
		for (i=0;i<=ptrF->Queue;i++){
			printf(" %d ",ptrF->Elts[i]);
		}
		printf(" Queue]\n");
	}
}

void testFile(T_File *ptrF){
	int i;
	printf("\nInitialisation de la File");
	initFile(ptrF);
	printf("\nOn regarde si la file est vide :");
	if (fileVide(ptrF)){
		printf("\nLa file est vide !\n");
	}
	printf("\nAjout de 11 valeurs à notre File :\n");
	for (i=0; i<=MAX;i++){
		printf("Ajout de la valeur %d\n",i);
		if (ajouter(ptrF, &i)==0){
			printf("STOP !!! Ajout impossible !\n");
		}
	}
	printf("On remarque que l'ajout de trop de valeurs est impossible !\n");
	printf("\nOn affiche la File :\n");
	afficherFile(ptrF);
	printf("\nOn regarde si la file est pleine");
	if (filePleine(ptrF)){
		printf("\nLa file est pleine !");
	}
	printf("\n\nOn affiche l'élément en tête");
	i=premier(ptrF);
	printf("\nElement en tête : %d",i);
	printf("\n\nOn retire la valeur de la tête, on défile");
	i=retirer(ptrF);
	printf("\nAffichons à nouveau la file :\n");
	afficherFile(ptrF);
	printf("\nFIN DU JEU DE TEST FILE");
}
#include "stdio.h"

#define TAILLE 10

int main(int argc, char** argv)
{

	int tableau[TAILLE];
	int* ptrTableau;
	int i;
	
	ptrTableau = tableau;
	printf("Entrez les %d entiers du tableau.\n",TAILLE);
	for (i = 0; i < TAILLE ; i++) 
	{		
		scanf("%d", ptrTableau + i);
		
	}
	

	printf("Voici votre tableau: \n");
	for (i = 0; i < TAILLE ; i++) 
	{		
		printf("%d ", *ptrTableau + i);
		
	}
	printf("\n");
}

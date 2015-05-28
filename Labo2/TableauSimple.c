#include "stdio.h"

#define TAILLE 10

int main(int argc, char** argv)
{

	int tableau[TAILLE];
	int i;
	
	
	printf("Entrez les %d entiers du tableau.\n",TAILLE);
	for (i = 0; i < TAILLE ; i++) 
	{		
		scanf("%d", &tableau[i] );
	}
	
		printf("Voici votre tableau: \n");
	for (i = 0; i < TAILLE ; i++)
	{
		printf("Position %d = %d \n",i,tableau[i]);
	}


	for ( i = 0; i < TAILLE ; i++)
	{
		tableau[i] = tableau[i] * 3;
	}
	
	printf("Voici votre tableau apres modification: \n");
	for (i = 0; i < TAILLE ; i++)
	{
		printf("Position %d = %d \n",i,tableau[i]);
	}
	
	return 0;
}

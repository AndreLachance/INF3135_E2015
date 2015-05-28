#include "stdio.h"

#define COLONNE 3
#define RANGEE 3

int main(int argc, char** argv)
{
	int i, j;
	int matrice[RANGEE][COLONNE];
	int matrice2[RANGEE][COLONNE];
	int matriceAdd[RANGEE][COLONNE];

	for (i = 0; i < RANGEE; i++)
	{
		for (j = 0; j < COLONNE; j++)
		{
			matrice[i][j] = i * j;
			matrice2[i][j] = (i*2) + j;
		}
	}
	
	printf("matrice1:");
	for (i = 0; i < RANGEE; i++)
	{
		printf("\n\t");
		for (j = 0; j < COLONNE; j++)
		{
		printf("%d ",matrice[i][j]);
		}
	}
	printf("\n");
	
	printf("matrice2:");
	for (i = 0; i < RANGEE; i++)
	{
		printf("\n\t");
		for (j = 0; j < COLONNE; j++)
		{
		printf("%d ",matrice2[i][j]);
		}
	}
	printf("\n");
	
	for (i = 0; i < RANGEE; i++)
	{
	
		for (j = 0; j < COLONNE; j++)
		{
		matriceAdd[i][j] = matrice[i][j] + matrice2[i][j];
		}
	}
	
	printf("matriceAdd:");
	for (i = 0; i < RANGEE; i++)
	{
		printf("\n\t");
		for (j = 0; j < COLONNE; j++)
		{
		printf("%d ", matriceAdd[i][j]);
		}
	}
	printf("\n");
	
	return 0;
}

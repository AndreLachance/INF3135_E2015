#include <stdio.h>

#define NOMBRE_LIGNE 3
#define NOMBRE_COLOMNE 3

int main(void){
	int matA[NOMBRE_LIGNE][NOMBRE_COLOMNE];
	int matB[NOMBRE_LIGNE][NOMBRE_COLOMNE];
	
	int* ligneA;
	int* ligneB;
	
	int i, j;
	
	printf("Ce programe fait l'addition de deux matrice, A et B.\n\n");
	
	printf("Matrice A\n\n");
	for (i = 0; i < NOMBRE_LIGNE; i++){
		ligneA = *(matA + i);
		
		for (j = 0; j < NOMBRE_COLOMNE; j++){
			printf("Entrez la valeur a la ligne %d colomne %d: ", i + 1, j + 1);
			scanf("%d", ligneA + j);
			printf("\n");
		}
	}
	
	printf("Matrice B\n\n");
	for (i = 0; i < NOMBRE_LIGNE; i++){
		ligneB = *(matB + i);
		
		for (j = 0; j < NOMBRE_COLOMNE; j++){
			printf("Entrez la valeur a la ligne %d colomne %d: ", i + 1, j + 1);
			scanf("%d", ligneB + j);
			printf("\n");
		}
	}
	
	printf("----------------------------------------------------\n\n");
	printf("La matrice A est:\n");
	
	for (i = 0; i < NOMBRE_LIGNE; i++){
		ligneA = *(matA + i);
		
		for (j = 0; j < NOMBRE_COLOMNE; j++){
			printf("%8d", *(ligneA + j));
		}
		printf("\n");
	}
	
	printf("La matrice B est:\n");
	
	for (i = 0; i < NOMBRE_LIGNE; i++){
		ligneB = *(matB + i);
		
		for (j = 0; j < NOMBRE_COLOMNE; j++){
			printf("%8d", *(ligneB + j));
		}
		printf("\n");
	}
	
	printf("La matrice resultante:\n");
	
	for (i = 0; i < NOMBRE_LIGNE; i++){
		ligneA = *(matA + i);
		ligneB = *(matB + i);
		
		for (j = 0; j < NOMBRE_COLOMNE; j++){
			printf("%8d", *(ligneA + j) + *(ligneB + j));
		}
		printf("\n");
	}
	
	return 0;
}
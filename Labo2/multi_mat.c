#include <stdio.h>

#define NOMBRE_LIGNE 3
#define NOMBRE_COLOMNE 3

int main(void){
	int matA[NOMBRE_LIGNE][NOMBRE_COLOMNE];
	int matB[NOMBRE_COLOMNE][NOMBRE_LIGNE];
	
	int i, j, k, res;
	
	printf("Ce programe fait la mutiplication de deux matrice 3x3, A et B.\n\n");
	
	printf("Matrice A\n\n");
	for (i = 0; i < NOMBRE_LIGNE; i++){
		for (j = 0; j < NOMBRE_COLOMNE; j++){
			printf("Entrez la valeur a la ligne %d colomne %d: ", i + 1, j + 1);
			scanf("%d", &matA[i][j]);
			printf("\n");
		}
	}
	
	printf("Matrice B\n\n");
	for (i = 0; i < NOMBRE_COLOMNE; i++){
		for (j = 0; j < NOMBRE_LIGNE; j++){
			printf("Entrez la valeur a la ligne %d colomne %d: ", i + 1, j + 1);
			scanf("%d", &matB[i][j]);
			printf("\n");
		}
	}
	
	printf("----------------------------------------------------\n\n");
	printf("La matrice A est:\n");
	
	for (i = 0; i < NOMBRE_LIGNE; i++){
		for (j = 0; j < NOMBRE_COLOMNE; j++){
			printf("%8d", matA[i][j]);
		}
		printf("\n");
	}
	
	printf("La matrice B est:\n");
	
	for (i = 0; i < NOMBRE_COLOMNE; i++){
		for (j = 0; j < NOMBRE_LIGNE; j++){
			printf("%8d", matB[i][j]);
		}
		printf("\n");
	}
	
	printf("La matrice resultante:\n");
	
	for (i = 0; i < NOMBRE_LIGNE; i++){
		
		for (j = 0; j < NOMBRE_LIGNE; j++){
			res = 0;
			for (k = 0; k < NOMBRE_COLOMNE; k++){
				res = res + (matA[i][k] * matB[k][j]);
			}
			printf("%8d", res);
		}
		printf("\n");
	}
	
	return 0;
}
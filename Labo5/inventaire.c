#include <stdlib.h>
#include <stdio.h>
#include "inventaire.h"

#define FICHIER_INVENTAIRE "inventaire.txt"
#define TAILLE_TAMPON 50
#define FORMAT_INVENTAIRE "Bridgerock\n18 pouces: %d\n20 pouces: %d\n22 pouces: %d\nMicheline\n18 pouces: %d\n20 pouces: %d\n22 pouces: %d\nTokio\n18 pouces: %d\n20 pouces: %d\n22 pouces: %d"

FILE* ouvrirFichierInventaire (char*);
void fermerFichier (FILE*);
void entreeInvalide();

void inventaireCharger (INVENTAIRE inventaire){
	FILE* fichier = ouvrirFichierInventaire ("r");
	fscanf(fichier, FORMAT_INVENTAIRE, &inventaire[0][0], &inventaire[0][1], &inventaire[0][2], &inventaire[1][0], &inventaire[1][1], &inventaire[1][2], &inventaire[2][0], &inventaire[2][1], &inventaire[2][2]);
	fermerFichier (fichier);
}

void inventaireAfficher (INVENTAIRE inventaire){
	printf(FORMAT_INVENTAIRE, inventaire[0][0], inventaire[0][1], inventaire[0][2], inventaire[1][0], inventaire[1][1], inventaire[1][2], inventaire[2][0], inventaire[2][1], inventaire[2][2]);
	printf("\n\n");
}

int* inventaireSelectionPneu (INVENTAIRE inventaire){
	int marque;
	int taille;
	char buffer[51];
	printf("Entrez la marque de pneu:\n");
	printf("0: Bridgerock\n");
	printf("1: Micheline\n");
	printf("2: Tokio\n");
	printf("Choix:");
	fgets(buffer, 50, stdin);
	sscanf(buffer, "%d", &marque);
	printf("\n");
	while (marque < 0 || marque > 2){
		entreeInvalide();
		fgets(buffer, 50, stdin);
		sscanf(buffer, "%d", &marque);
		printf("\n");
	}
	printf("Entrez la taille de pneu:\n");
	printf("0: 18 pouces\n");
	printf("1: 20 pouces\n");
	printf("2: 22 pouces\n");
	printf("Choix:");
	fgets(buffer, 50, stdin);
	sscanf(buffer, "%d", &taille);
	printf("\n");
	while (taille < 0 || taille > 2){
		entreeInvalide();
		fgets(buffer, 50, stdin);
		sscanf(buffer, "%d", &taille);
		printf("\n");
	}
	
	return &(inventaire[marque][taille]);
}

void inventaireSauvegarder (INVENTAIRE inventaire){
	FILE* fichier = ouvrirFichierInventaire ("w");
	fprintf(fichier, FORMAT_INVENTAIRE, inventaire[0][0], inventaire[0][1], inventaire[0][2], inventaire[1][0], inventaire[1][1], inventaire[1][2], inventaire[2][0], inventaire[2][1], inventaire[2][2]);
	fermerFichier (fichier);
}

FILE* ouvrirFichierInventaire (char* mode){
	FILE* fichier;

	fichier = fopen(FICHIER_INVENTAIRE, mode);
	if(fichier == NULL) {
		fprintf(stderr,"Erreur d'ouverture du fichier.\n");
		exit (1);
	}

	return fichier;
}

void fermerFichier (FILE* fichier){
	if(fclose(fichier) == EOF)
	{
		printf("Erreur de fermeture du fichier\n");
		exit (1);
	}
}

void entreeInvalide(){
	printf("Votre choix n'est pas valide.\nEntrez un autre choix:");
}

void modificationInventaire(INVENTAIRE inventaire){
	int temp = -1;
	int* pneu;
	char buffer[51];
	
	printf("Modification d'inventaire.\n");
	pneu = inventaireSelectionPneu (inventaire);
	printf("Quantite actuel:%d\n", *pneu);
	
	do {
		printf("Entrez la nouvelle quantite:");
		fgets(buffer, 50, stdin);
		sscanf(buffer, "%d", &temp);
		printf("\n");
		if (temp < 0){
			printf("La quantite ne peut pas etre negatif\n");
		}
	} while (temp < 0);
	
	*pneu = temp;
	printf("Quantite modifiee.\n");
	
	printf("\n");
}

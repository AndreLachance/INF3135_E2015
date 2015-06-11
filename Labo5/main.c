#include <stdlib.h>
#include <stdio.h>
#include "inventaire.h"

void afficherMenu();

void modificationInventaire(INVENTAIRE);

int main (void){
	int* inventaire[3];
	int pneuB[3];
	int pneuM[3];
	int pneuT[3];
	inventaire[0] = pneuB;
	inventaire[1] = pneuM;
	inventaire[2] = pneuT;
	char menu[51];
	
	inventaireCharger (inventaire);
	
	do{
		afficherMenu();
		scanf("%s", menu);
		printf("\n");
		switch(menu[0]){
			case 'a' :
			case 'A' :
				inventaireAfficher (inventaire);
				break;
			
			case 'm' :
			case 'M' :
				modificationInventaire(inventaire);
				break;
				
			case 'q':
			case 'Q':
				break;
				
			default:  
				printf("Entree Invalide!\n");
				break;
		}
	}while(menu[0] != 'q' && menu[0] != 'Q');
	
	inventaireSauvegarder (inventaire);
	return 0;
}

void modificationInventaire(INVENTAIRE inventaire){
	int temp;
	int* pneu;
	
	printf("Modification d'inventaire.\n");
	pneu = inventaireSelectionPneu (inventaire);
	printf("Quantite actuel:%d\n", *pneu);
	
	do {
		printf("Entrez la nouvelle quantite:");
		scanf("%d", &temp);
		printf("\n");
		if (temp < 0){
			printf("La quantite ne peut pas etre negatif\n");
		}
	} while (temp < 0);
	
	*pneu = temp;
	printf("Quantite modifiee.\n");
	
	printf("\n");
}

void afficherMenu(){
	printf("Menu:\n");
	printf("a: afficher l'invertaire\n");
	printf("m: modifier l'invertaire\n");
	printf("q: quiter\n");
	printf("Entrez votre choix:");
}
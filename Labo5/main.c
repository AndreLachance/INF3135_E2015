#include <stdlib.h>
#include <stdio.h>
#include "inventaire.h"

void afficherMenu();



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


void afficherMenu(){
	printf("Menu:\n");
	printf("a: afficher l'invertaire\n");
	printf("m: modifier l'invertaire\n");
	printf("q: quiter\n");
	printf("Entrez votre choix:");
}

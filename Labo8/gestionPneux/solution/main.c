#include <stdlib.h>
#include <stdio.h>
#include "pileProduit.h"
#include "produit.h"

#define TAILLE_TAMPON 50

void erreurFatal();

int main (void){
	PileProduit inventaire = pileProduitCreeVide();
	char entree[TAILLE_TAMPON + 1];
	Produit pr;
	unsigned nbTemp;

	if (inventaire == NULL){
		erreurFatal();
	}
	
	do{
		printf("Voulez-vous entrer un produit(o/n): ");
		scanf("%s", entree);
		printf("\n");
		if(entree[0] == 'o' || entree[0] == 'O'){
			pr = produitCreeVide();
			if(pr == NULL){
				erreurFatal();
			}
			printf("Entree le nom du produit: ");
			scanf("%s", entree);
			printf("\n");
			if( !produitModifierNom(pr, entree)){
				erreurFatal();
			}
			printf("Entree la description du produit: ");
			scanf("%s", entree);
			printf("\n");
			if( !produitModifierDescription(pr, entree)){
				erreurFatal();
			}
			printf("Entree le prix du produit: ");
			scanf("%u", &nbTemp);
			printf("\n");
			produitModifierPrix(pr, nbTemp);
			printf("Entree la quantite du produit: ");
			scanf("%u", &nbTemp);
			printf("\n");
			produitModifierQuantite(pr, nbTemp);

			if (!pileProduitEnpiler(inventaire, pr)){
				erreurFatal();
			}
			
		}
	}while(entree[0] != 'n' && entree[0] != 'N');

	while (!pileProduitEstVide(inventaire)){
		printf("On est la\n");
		pr = pileProduitDepiler(inventaire);
		produitAfficher(pr);
	}

	return 0;
}

void erreurFatal(){
	printf("Erreur fatale!!!");
	exit(1);
}

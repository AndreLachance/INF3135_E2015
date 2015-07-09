#include <stdlib.h>
#include "pileProduit.h"
#include "produit.h"
#include "chaine.h"

#define TAILLE_INITIALE 10
#define INCREMENTATION_TAILLE 10

struct pileProduit{
	Produit * pTabPile;
	unsigned taillePile;
	unsigned tailleMax;
};

PileProduit pileProduitCreeVide(){
	PileProduit pile = (PileProduit) malloc(sizeof(struct pileProduit));
	if (pile != NULL){
		pile->pTabPile = (Produit *) calloc(TAILLE_INITIALE, sizeof(Produit));
		pile->taillePile = 0;
		pile->tailleMax = TAILLE_INITIALE;
		if(pile->pTabPile == NULL){
			free(pile);
			pile = NULL;
		}
	}
	
	return pile;
}

int pileProduitEnpiler(PileProduit pile, Produit pro){
	Produit * temp;
	if (pile->taillePile == pile->tailleMax){
		temp = (Produit *)realloc(pile->pTabPile, sizeof(Produit) * (pile->tailleMax + INCREMENTATION_TAILLE));
		if (temp == NULL){
			return 0;
		} else {
			pile->pTabPile = temp;
			pile->tailleMax += INCREMENTATION_TAILLE;
		}
	}
	pile->pTabPile[pile->taillePile] = pro;
	pile->taillePile++;
	return 1;
}

Produit pileProduitDepiler(PileProduit pile){
	--pile->taillePile;
	return pile->pTabPile[pile->taillePile];
}

int pileProduitEstVide(PileProduit pile){
	return pile->taillePile;
}

void pileProduitSupprimmer(PileProduit pile){
	free(pile->pTabPile);
	free(pile);
}

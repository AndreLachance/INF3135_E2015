/* produit.c

Patrick Blanchette
2015/07/09
*/

#include <stdlib.h>
#include <string.h>
#include "chaine.h"
#include "produit.h"

struct produit{
	Chaine nom;
	Chaine description;
	unsigned prix;
	unsigned quantite;
};

Produit produitCreeVide(){
	Produit pr = (Produit) malloc(sizeof(struct produit));
	if (pr != NULL){
		pr->nom = chaineCreeVide();
		if (pr->nom == NULL){
			free(pr);
			return NULL;
		}
		pr->description = chaineCreeVide();
		if (pr->description == NULL){
			chaineSupprimme(pr->nom);
			free(pr);
			return NULL;
		}
		pr->prix = 0;
		pr->quantite = 0;
	}
	return pr;
}

char * produitNom(Produit pr){
	return chaineValeur(pr->nom);
}

int produitModifierNom(Produit pr, char* ch){
	Chaine temp = chaineCreeCopie(ch, strlen(ch));
	if (temp == NULL){
		return 0;
	}
	chaineSupprimme(pr->nom);
	pr->nom = temp;
	return 1;
}

char * produitDescription(Produit pr){
	return chaineValeur(pr->description);
}

int produitModifierDescription(Produit pr, char* ch){
	Chaine temp = chaineCreeCopie(ch, strlen(ch));
	if (temp == NULL){
		return 0;
	}
	chaineSupprimme(pr->description);
	pr->description = temp;
	return 1;
}

unsigned produitPrix(Produit pr){
	return pr->prix;
}

void produitModifierPrix(Produit pr, unsigned nb){
	pr->prix = nb;
}

unsigned produitQuantite(Produit pr){
	return pr->quantite;
}

void produitModifierQuantite(Produit pr, unsigned nb){
	pr->quantite = nb;
}

void produitSupprimme(Produit pr){
	chaineSupprimme(pr->nom);
	chaineSupprimme(pr->description);
	free(pr);
}

void produitAfficher(Produit pr){
	printf("Nom: %s\nDescription: %s\nPrix: %u\nQuantite: %u\n", chaineValeur(pr->nom), chaineValeur(pr->description), pr->prix, pr->quantite);
}

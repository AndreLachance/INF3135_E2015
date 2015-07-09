#ifndef PILE_PRODUIT_H
#	define PILE_PRODUI_H

#include "produit.h"

typedef struct pileProduit * PileProduit;

/* pileProduitCreeVide :
	renvoie un pointeur vers la pile produit si la creation a pu se faire, renvoie NULL sinon. La pile est vide mais un certain espace lui a été alloué.
*/
PileProduit pileProduitCreeVide();

/* pileProduitEnpiler :
	ajoute un produit a la Pile, en gerant l'allocation de memoire.

	Retourne faux si l'insertion echoue, vrai sinon.
	pile doit etre un pointeur non NULL vers une pile produit creee par pileProduitCreeVide.
*/
int pileProduitEnpiler(PileProduit, Produit);

/* pileProduitEnpiler :
	retourne le produit qui se trouve au sommet de la pile

	pile doit etre un pointeur non NULL vers une pile produit creee par pileProduitCreeVide.
*/
Produit pileProduitDepiler(PileProduit);

/* pileProduitEnpiler :
	retourne vrai si la pile est vide, faux sinon.

	pile doit etre un pointeur non NULL vers une pile produit creee par pileProduitCreeVide.
*/
int pileProduitEstVide(PileProduit);

/* pileProduitSupprimmer :
	supprime une pile de produit
	pile doit etre un pointeur non NULL vers une pile produit creee par pileProduitCreeVide.
*/
void pileProduitSupprimmer(PileProduit);

#endif /* PILE_PRODUI_H */

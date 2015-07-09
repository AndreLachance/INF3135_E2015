/* produit.h : Module implementant des produit comme type abstrait

Patrick Blanchette, UQAM, INF3135, Labo8
*/

#ifndef PRODUIT_H
#	define PRODUIT_H

typedef struct produit * Produit;

/* produitCreeVide :
	renvoie un pointeur vers le produit si la creation a pu se faire, renvoie NULL sinon.
*/
Produit produitCreeVide();

/* produitNom :
	retourne le nom du produit au format char*
	L'allocation de l'espace pour le résultat est assure par produitNom.
	
	pr doit etre un pointeur non NULL vers un produit creee par produitCreeVide.
*/
char * produitNom(Produit);

/* produitModifierNom :
	remplace l'ancien nom du produit par celui recu en paramettre.
	retourne FALSE si le changement n'a pas put se faire.
	
	pr doit etre un pointeur non NULL vers un produit creee par produitCreeVide.
*/
int produitModifierNom(Produit, char*);

/* produitDescription :
	retourne la description du produit au format char*
	L'allocation de l'espace pour le résultat est assure par produitNom.
	
	pr doit etre un pointeur non NULL vers un produit creee par produitCreeVide.
*/
char * produitDescription(Produit);

/* produitModifierDescription :
	remplace l'ancienne description du produit par celle recu en paramettre.
	retourne FALSE si le changement n'a pas put se faire.
	
	pr doit etre un pointeur non NULL vers un produit creee par produitCreeVide.
*/
int produitModifierDescription(Produit, char*);

/* produitPrix :
	retourne le prix du produit au format unsigned.
	
	pr doit etre un pointeur non NULL vers un produit creee par produitCreeVide.
*/
unsigned produitPrix(Produit);

/* produitModifierPrix :
	remplace l'ancien prix du produit par celui recu en paramettre.
	
	le nouveau prix doit etre un nombre de cents positif.
	pr doit etre un pointeur non NULL vers un produit creee par produitCreeVide.
*/
void produitModifierPrix(Produit, unsigned);

/* produitQuantite :
	retourne la quantite du produit au format unsigned.
	
	pr doit etre un pointeur non NULL vers un produit creee par produitCreeVide.
*/
unsigned produitQuantite(Produit);

/* produitModifierPrix :
	remplace l'ancienne quantite du produit par celui recu en paramettre.
	
	pr doit etre un pointeur non NULL vers un produit creee par produitCreeVide.
*/
void produitModifierQuantite(Produit, unsigned);

/* produitSupprimme :
	supprime un produit
	pr doit etre un pointeur non NULL vers une chaine creee par produitCreeVide.
*/
void produitSupprimme(Produit);

#endif /* PRODUIT_H */
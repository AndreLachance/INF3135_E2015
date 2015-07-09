/* chaine.h : Module implementant des chaines de caracteres dynamiques comme type abstrait

Emmanuel Chieze, UQAM, INF3135, A12, TP2

Modifier: Patrick Blanchette, UQAM, INF3135, Labo7
*/
#ifndef CHAINE_H
#	define CHAINE_H

typedef struct chaine * Chaine;

/* chaineCreeVide :
	renvoie un pointeur vers la chaine si la creation a pu se faire, renvoie NULL sinon. La chaine est vide mais un certain espace lui a été alloué. Renvoie NULL si l'allocation d'espace n'a pas pu se faire.
*/
Chaine chaineCreeVide();

/* chaineCreeCopie :
	renvoie un pointeur vers la chaine si la creation a pu se faire, renvoie NULL sinon. La chaine est creee comme copie des n premiers caracteres de ch. Renvoie NULL si l'allocation d'espace n'a pas pu se faire. n doit etre inferieur ou egal a la longueur de la chaine ch
*/
Chaine chaineCreeCopie(char * ch, unsigned n);

/* chaineAjouteChar :
	ajoute un caractere (deuxieme parametre) a la fin de la chaine (premier parametre), en gerant l'allocation de memoire.

	Retourne faux si l'insertion echoue, vrai sinon.
	ch doit etre un pointeur non NULL vers une chaine creee par ChaineCree
*/
int chaineAjouteChar(Chaine, unsigned char);

/* chaineAjouteChaine :
	ajoute une Chaine (deuxieme parametre) a la fin de la premiere chaine, en gerant l'allocation de memoire.

	Retourne faux si l'insertion echoue, vrai sinon.
	les chaine doivent etre des pointeurs non NULL vers une chaine creee par ChaineCree
*/
int chaineAjouteChaine(Chaine, Chaine);

/* chaineValeur
	retourne le contenu de la chaîne au format char *
	L'allocation de l'espace pour le résultat est assuré par chaineValeur.
	
	ch doit etre un pointeur non NULL vers une chaine creee par ChaineCree
*/
char * chaineValeur(Chaine);

/* chaineLongueur :
	retourne la longueur (nb de caracteres) d'une chaine. Le calcul devrait
	se faire en temps constant (peu importe la longueur de la chaine).
	ch doit etre un pointeur non NULL vers une chaine creee par chaineCree.
*/
unsigned chaineLongueur(Chaine);

/* chaineSupprimme :
	supprime une chaine
	ch doit etre un pointeur non NULL vers une chaine creee par chaineCree.
*/
void chaineSupprimme(Chaine);

#endif /* CHAINE_H */

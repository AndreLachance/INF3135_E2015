/* chaine.c

Patrick Blanchette
BLAP20118603
2015/04/03
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "chaine.h"

#define TAILLE_INITIALE 10
#define INCREMENTATION_TAILLE 10

struct chaine{
	char * pTabChaine;
	unsigned tailleChaine;
	unsigned tailleMax;
};

Chaine chaineCreeVide(void){
	Chaine p = (Chaine) malloc(sizeof(struct chaine));
	if (p != NULL){
		p->pTabChaine = (char*) malloc(sizeof(char) * TAILLE_INITIALE);
		p->tailleChaine = 0;
		p->tailleMax = TAILLE_INITIALE;
		if(p->pTabChaine == NULL){
			free(p);
			p = NULL;
			printf("Erreur d'allocation de la mémoire: %s",strerror(errno));
		} else {
			p->pTabChaine[0] = '\0';
		}
	} else {
		p = NULL;
		printf("Erreur d'allocation de la mémoire: %s",strerror(errno));
	}
	return p;
}

Chaine chaineCreeCopie(char * ch, unsigned n){
	Chaine nouvelleChaine;
	int ajoute = 1;
	unsigned i = 0;
	if (n > strlen(ch)){
		nouvelleChaine = NULL;
	} else {
		nouvelleChaine = chaineCreeVide();
		if (nouvelleChaine == NULL){
			return NULL;
		}
		while (i < n && ajoute != 0){
			ajoute = chaineAjouteChar(nouvelleChaine, ch[i]);
			i++;
		}
		if (ajoute == 0){
			chaineSupprimme(nouvelleChaine);
			nouvelleChaine = NULL;
		}
	}
	return nouvelleChaine;
}

int chaineAjouteChar(Chaine ch, unsigned char n){
	char * temp;
	if (ch->tailleChaine + 1 == ch->tailleMax){
		temp = (char *)realloc(ch->pTabChaine, sizeof(char) * (ch->tailleMax + INCREMENTATION_TAILLE));
		if (temp == NULL){
			printf("Erreur d'allocation de la mémoire: %s",strerror(errno));
			return 0;
		} else {
			ch->pTabChaine = temp;
			ch->tailleMax += INCREMENTATION_TAILLE;
		}
	}
	ch->pTabChaine[ch->tailleChaine] = n;
	ch->pTabChaine[ch->tailleChaine + 1] = '\0';
	ch->tailleChaine++;
	return 1;
}

int chaineAjouteChaine(Chaine chaineInit, Chaine chaineAjoute){
	char * temp;
	if (chaineInit->tailleChaine + chaineAjoute->tailleChaine >= chaineInit->tailleMax){
		temp = (char *)realloc(chaineInit->pTabChaine, sizeof(char) * (chaineInit->tailleMax + chaineAjoute->tailleChaine));
		if (temp == NULL){
			printf("Erreur d'allocation de la mémoire: %s",strerror(errno));
			return 0;
		} else {
			chaineInit->pTabChaine = temp;
			chaineInit->tailleMax += chaineInit->tailleChaine;
		}
	}
	strcat(chaineInit->pTabChaine, chaineAjoute->pTabChaine);
	chaineInit->tailleChaine += chaineAjoute->tailleChaine;
	return 1;
}

char * chaineValeur(Chaine ch){
	return ch->pTabChaine;
}

unsigned chaineLongueur(Chaine ch){
	return ch->tailleChaine;
}

void chaineSupprimme(Chaine ch){
	free(ch->pTabChaine);
	free(ch);
}

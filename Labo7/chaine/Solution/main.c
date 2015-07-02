#include <stdlib.h>
#include <stdio.h>
#include "chaine.h"

int main (void){
	Chaine ch1 = chaineCreeCopie("Salut", 5);
	Chaine ch2 = chaineCreeCopie(" toi\n", 5);
	
	if (chaineAjouteChaine(ch1, ch2)){
		printf("%s", chaineValeur(ch1));
	} else {
		printf("Erreur!");
	}
	return 0;
}
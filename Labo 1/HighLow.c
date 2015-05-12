#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char** argv){ 
	int nbHasard;
	int reponse;
	int nbTentative = 0;
	
	
	printf("Bonjour, bienvenue au jeu High Low.\n");
	printf("Le jeu génère un chiffre au hasard entre 0 et 99 et vous indique si vous êtes trop haut ou bas.\n");

	srand((unsigned)time(NULL));
	nbHasard = (rand() % 100);
	
		do{
			nbTentative++;
			printf("Veuillez entrer votre réponse:\n");
			scanf("%d",&reponse);
			
			if(reponse < nbHasard){
				printf("Trop bas\n");
			} else if (reponse > nbHasard){
				printf("Trop haut\n");
			} else {
				printf("Félicitations! Vous avez réussi!\n");
			}
			
		}while(reponse != nbHasard);
		
		printf("Vous avez pris %d tentatives pour réussir.\n", nbTentative); 
		return 0;
	}

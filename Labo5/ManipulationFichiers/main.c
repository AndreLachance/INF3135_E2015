#include "stdio.h"
#include "string.h"
#include "errno.h"
#include "stdlib.h"
#include "manipulationFichiers.h"
#include "entreeSortie.h"

int main(int argc, char** argv)
{

	FILE* fichierEntree;
	FILE* fichierSortie;
	char commande;
	char tampon[TAILLE_TAMPON + 1];
	
	verificationArguments(argc);
	
	printf("Bienvenue au programme de manipulation des fichiers\n");
	afficherMenu();

	do{
		printf("Entrez votre choix de commande:\n");
		fgets(tampon, TAILLE_TAMPON, stdin);
		commande = tampon[0];
		switch(commande){
			
			case 'a' :
				fichierEntree = ouvrirFichier (argv[1], "r");
				fichierSortie = ouvrirFichier (argv[2], "w");

				copieFichier(fichierEntree, fichierSortie);

				fermerFichier (fichierEntree);
				fermerFichier (fichierSortie);
				break;
			
			case 's' :
				fichierSortie = ouvrirFichier (argv[2], "a");

				ajoutLigne(fichierSortie);

				fermerFichier (fichierSortie);
				break;
				
			case 'r' :
				fichierEntree = ouvrirFichier (argv[1], "r");

				nombreMot(fichierEntree);

				fermerFichier (fichierEntree);
				break;
				
			case 'h' :
				afficherMenu();
				break;
				
			case 'q':
			case 'Q':
				return EXIT_SUCCESS;
				break;
			default:  
				printf("Entrée Invalide\n");
				break;
		}
	}while(commande != 'q' && commande != 'Q');
}

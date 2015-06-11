#include "stdio.h"
#include "string.h"
#include "errno.h"
#include "stdlib.h"
#include "entreeSortie.h"

FILE* ouvrirFichier (char* adresseFichier, char* mode)
{
	FILE* fichier;

	fichier = fopen(adresseFichier, mode);
	if(fichier == NULL) {
		fprintf(stderr,"Erreur d'ouverture du fichier: %s\n", strerror(errno));
		exit (1);
	}

	return fichier;
}

void fermerFichier (FILE* fichier)
{
	if(fclose(fichier) == EOF)
	{
		printf("Erreur de fermeture du fichier\n");
		exit (1);
	}
}

void afficherMenu()
{
	printf("Veuillez entrer une lettre parmis les suivantes: \n");
	printf("a: Copie le fichier entree dans le fichier sortie\n");
	printf("s: permet d'ajouter des lignes de texte manuellement au fichier de sortie\n");
	printf("r: recherche d'un mot dans le fichier d'entree\n");
	printf("h: affiche le menu des commandes\n");
	printf("q: Quitte le programme\n");
}

void verificationArguments(int argc){
	
	if (argc != 3) {
		
		fprintf(stderr, "Nombre invalide d'arguments!\n Utilisation selon le format suivant: ./nomExecutable <fichierSource.txt> <fichierSortie.txt> \n");
		exit(1);
		
	}
	
}
